/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-10-23     flybreak     the first version
 */

#include <rtthread.h>
#include <rtdevice.h>

#include <string.h>
#include <stdlib.h>

#define DBG_TAG "lsm6ds0"
#define DBG_LVL DBG_INFO
#include <rtdbg.h>

#include "lsm6ds0.h"
#include "lsm6ds0_reg.h"

#define MPU6XXX_ACCEL_SEN     (16384)
#define MPU6XXX_GYRO_SEN      (1310)

#define LSM6DS0_SPI_MAX_SPEED (10 * 1000 * 1000)

#define MPU60X0_TEMP_SEN      (340)
#define MPU60X0_TEMP_OFFSET   (36.5)

#define MPU6500_TEMP_SEN      (333.87)
#define MPU6500_TEMP_OFFSET   (21)

/**
 * This function writes the value of the register for mpu6xxx
 *
 * @param dev the pointer of device driver structure
 * @param reg the register for mpu6xxx
 * @param data value to write
 *
 * @return the writing status, RT_EOK reprensents  writing the value of the register successfully.
 */
static rt_err_t lsm6ds0_write_reg(struct lsm6ds0_device *dev, rt_uint8_t reg, rt_uint8_t data)
{
    rt_int8_t res = 0;
#ifdef RT_USING_I2C
    struct rt_i2c_msg msgs;
    rt_uint8_t buf[2] = {reg, data};
#endif
    if (dev->bus->type == RT_Device_Class_I2CBUS)
    {
#ifdef RT_USING_I2C
        msgs.addr  = dev->i2c_addr;    /* slave address */
        msgs.flags = RT_I2C_WR;        /* write flag */
        msgs.buf   = buf;              /* Send data pointer */
        msgs.len   = 2;

        if (rt_i2c_transfer((struct rt_i2c_bus_device *)dev->bus, &msgs, 1) == 1)
        {
            res = RT_EOK;
        }
        else
        {
            res = -RT_ERROR;
        }
#endif
    }
    else
    {
#ifdef RT_USING_SPI    //RT_Device_Class_SPIBUS
        res = rt_spi_send_then_send((struct rt_spi_device *)dev->bus, &reg, 1, &data, 1);
#endif
    }
    return res;
}

/**
 * This function reads the value of registers for mpu6xxx
 *
 * @param dev the pointer of device driver structure
 * @param reg the register for mpu6xxx
 * @param len number of register
 * @param buf read data pointer
 *
 * @return the reading status, RT_EOK reprensents  reading the value of registers successfully.
 */
static rt_err_t lsm6ds0_read_regs(struct lsm6ds0_device *dev, rt_uint8_t reg, rt_uint8_t len, rt_uint8_t *buf)
{
    rt_int8_t res = 0;
#ifdef RT_USING_I2C
    struct rt_i2c_msg msgs[2];
#endif
#ifdef RT_USING_SPI
    rt_uint8_t tmp;
#endif
    if (dev->bus->type == RT_Device_Class_I2CBUS)
    {
#ifdef RT_USING_I2C
        msgs[0].addr  = dev->i2c_addr;    /* Slave address */
        msgs[0].flags = RT_I2C_WR;        /* Write flag */
        msgs[0].buf   = &reg;             /* Slave register address */
        msgs[0].len   = 1;                /* Number of bytes sent */

        msgs[1].addr  = dev->i2c_addr;    /* Slave address */
        msgs[1].flags = RT_I2C_RD;        /* Read flag */
        msgs[1].buf   = buf;              /* Read data pointer */
        msgs[1].len   = len;              /* Number of bytes read */

        if (rt_i2c_transfer((struct rt_i2c_bus_device *)dev->bus, msgs, 2) == 2)
        {
            res = RT_EOK;
        }
        else
        {
            res = -RT_ERROR;
        }
#endif
    }
    else
    {
#ifdef RT_USING_SPI
		tmp = reg;
        res = rt_spi_send_then_recv((struct rt_spi_device *)dev->bus, &tmp, 1, buf, len);
#endif
    }
    return res;
}

/**
 * This function writes a bit value of registers for mpu6xxx
 *
 * @param dev the pointer of device driver structure
 * @param reg the register for mpu6xxx
 * @param bit the position of the register
 * @param data value to write
 *
 * @return the writing status, RT_EOK reprensents  writing a bit value of registers successfully.
 */
static rt_err_t lsm6ds0_write_bit(struct lsm6ds0_device *dev, rt_uint8_t reg, rt_uint8_t bit, rt_uint8_t data)
{
    rt_uint8_t byte;
    rt_err_t res;

    res = lsm6ds0_read_regs(dev, reg, 1, &byte);
    if (res != RT_EOK)
    {
        return res;
    }

    byte = (data != 0) ? (byte | (1 << bit)) : (byte & ~(1 << bit));

    return lsm6ds0_write_reg(dev, reg, byte);
}

/**
 * This function reads a bit value of registers for mpu6xxx
 *
 * @param dev the pointer of device driver structure
 * @param reg the register for mpu6xxx
 * @param bit the position of the register
 * @param data read data pointer
 *
 * @return the reading status, RT_EOK reprensents  reading a bit value of registers successfully.
 */
static rt_err_t lsm6ds0_read_bit(struct lsm6ds0_device *dev, rt_uint8_t reg, rt_uint8_t bit, rt_uint8_t *data)
{
    rt_uint8_t byte;
    rt_err_t res;

    res = lsm6ds0_read_regs(dev, reg, 1, &byte);
    if (res != RT_EOK)
    {
        return res;
    }

    *data = byte & (1 << bit);

    return RT_EOK;
}

/**
 * This function writes multi-bit value of registers for mpu6xxx
 *
 * @param dev the pointer of device driver structure
 * @param reg the register for mpu6xxx
 * @param start_bit the start position of the register
 * @param len number of bits to write
 * @param data value to write
 *
 * @return the writing status, RT_EOK reprensents  writing multi-bit value of registers successfully.
 */
static rt_err_t lsm6ds0_write_bits(struct lsm6ds0_device *dev, rt_uint8_t reg, rt_uint8_t start_bit, rt_uint8_t len, rt_uint8_t data)
{
    rt_uint8_t byte, mask;
    rt_err_t res;

    res = lsm6ds0_read_regs(dev, reg, 1, &byte);
    if (res != RT_EOK)
    {
        return res;
    }

    mask = ((1 << len) - 1) << (start_bit - len + 1);
    data <<= (start_bit - len + 1); // shift data into correct position
    data &= mask; // zero all non-important bits in data
    byte &= ~(mask); // zero all important bits in existing byte
    byte |= data; // combine data with existing byte

    return lsm6ds0_write_reg(dev, reg, byte);
}

/**
 * This function reads multi-bit value of registers for mpu6xxx
 *
 * @param dev the pointer of device driver structure
 * @param reg the register for mpu6xxx
 * @param start_bit the start position of the register
 * @param len number of bits to write
 * @param data read data pointer
 *
 * @return the reading status, RT_EOK reprensents  reading multi-bit value of registers successfully.
 */
static rt_err_t lsm6ds0_read_bits(struct lsm6ds0_device *dev, rt_uint8_t reg, rt_uint8_t start_bit, rt_uint8_t len, rt_uint8_t *data)
{
    rt_uint8_t byte, mask;
    rt_err_t res;

    res = lsm6ds0_read_regs(dev, reg, 1, &byte);
    if (res != RT_EOK)
    {
        return res;
    }

    mask = ((1 << len) - 1) << (start_bit - len + 1);
    byte &= mask;
    byte >>= (start_bit - len + 1);
    *data = byte;

    return RT_EOK;
}

/**
 * This function gets the raw data of the accelerometer
 *
 * @param dev the pointer of device driver structure
 * @param accel the pointer of 3axes structure for receive data
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
static rt_err_t lsm6ds0_get_accel_raw(struct lsm6ds0_device *dev, struct mpu6xxx_3axes *accel)
{
    rt_uint8_t buffer[6];
    rt_err_t res;

    res = lsm6ds0_read_regs(dev, LSM6DS3_ACC_GYRO_OUTX_L_XL, 6, buffer); 
    if (res != RT_EOK)
    {
        return res;
    }

    accel->x = ((rt_uint16_t)buffer[0] << 8) + buffer[1];
    accel->y = ((rt_uint16_t)buffer[2] << 8) + buffer[3];
    accel->z = ((rt_uint16_t)buffer[4] << 8) + buffer[5];

    return RT_EOK;
}

/**
 * This function gets the raw data of the gyroscope
 *
 * @param dev the pointer of device driver structure
 * @param gyro the pointer of 3axes structure for receive data
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
static rt_err_t lsm6ds0_get_gyro_raw(struct lsm6ds0_device *dev, struct mpu6xxx_3axes *gyro)
{
    rt_uint8_t buffer[6];
    rt_err_t res;

    res = lsm6ds0_read_regs(dev, LSM6DS3_ACC_GYRO_OUTX_L_G, 6, buffer);		
    if (res != RT_EOK)
    {
        return res;
    }

    gyro->x = ((rt_uint16_t)buffer[0] << 8) + buffer[1];
    gyro->y = ((rt_uint16_t)buffer[2] << 8) + buffer[3];
    gyro->z = ((rt_uint16_t)buffer[4] << 8) + buffer[5];

    return RT_EOK;
}

/**
 * This function gets the raw data of the temperature
 *
 * @param dev the pointer of device driver structure
 * @param temp read data pointer
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
static rt_err_t lsm6ds0_get_temp_raw(struct lsm6ds0_device *dev, rt_int16_t *temp)
{
    rt_uint8_t buffer[2];
    rt_err_t res;

    res = lsm6ds0_read_regs(dev, LSM6DS3_ACC_GYRO_OUT_TEMP_L, 2, buffer);
    if (res != RT_EOK)
    {
        return res;
    }

    *temp = ((rt_uint16_t)buffer[0] << 8) + buffer[1];

    return RT_EOK;
}

/**
 * This function gets mpu6xxx parameters.
 *
 * @param dev the pointer of device driver structure
 * @param cmd Configuration item
 * @param param read data pointer
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
static rt_err_t lsm6ds0_get_param(struct lsm6ds0_device *dev, enum lsm6ds0_cmd cmd, rt_uint16_t *param)
{
    rt_uint8_t data = 0;
    rt_err_t res = RT_EOK;

    RT_ASSERT(dev);

    switch (cmd)
    {
    case LSM6DS0_GYRO_RANGE:  /* Gyroscope full scale range */
        res = lsm6ds0_read_bits(dev, LSM6DS3_ACC_GYRO_CTRL2_G, 2, 2, &data);
        *param = data;
        break;
    case LSM6DS0_ACCEL_RANGE: /* Accelerometer full scale range */
        res = lsm6ds0_read_bits(dev, LSM6DS3_ACC_GYRO_CTRL1_XL, 2, 2, &data);
        *param = data;
        break;
    case LSM6DS0_DLPF_CONFIG: /* Digital Low Pass Filter */
        //res = lsm6ds0_read_bits(dev, MPU6XXX_RA_CONFIG, MPU6XXX_CFG_DLPF_CFG_BIT, MPU6XXX_CFG_DLPF_CFG_LENGTH, &data);
        *param = data;
        break;
    case LSM6DS0_SAMPLE_RATE: /* Sample Rate */
        /* Sample Rate = Gyroscope Output Rate / (1 + SMPLRT_DIV) */
//        res = lsm6ds0_read_bits(dev, MPU6XXX_RA_CONFIG, MPU6XXX_CFG_DLPF_CFG_BIT, MPU6XXX_CFG_DLPF_CFG_LENGTH, &data);
//        if (res != RT_EOK)
//        {
//            break;
//        }

//        if (data == 0 || data == 7) /* dlpf is disable */
//        {
//            res = lsm6ds0_read_regs(dev, MPU6XXX_RA_SMPLRT_DIV, 1, &data);
//            *param = 8000 / (data + 1);
//        }
//        else /* dlpf is enable */
//        {
//            res = lsm6ds0_read_regs(dev, MPU6XXX_RA_SMPLRT_DIV, 1, &data);
//            *param = 1000 / (data + 1);
//        }
        break;
    case LSM6DS0_SLEEP: /* sleep mode */
        res = lsm6ds0_read_bit(dev, LSM6DS3_ACC_GYRO_FIFO_CTRL4, 6, &data);
        *param = data;
        break;
    }

    return res;
}

/**
 * This function set mpu6xxx parameters.
 *
 * @param dev the pointer of device driver structure
 * @param cmd Configuration item
 * @param param Configuration item parameter
 *
 * @return the setting status, RT_EOK reprensents  setting the parameter successfully.
 */
rt_err_t lsm6ds0_set_param(struct lsm6ds0_device *dev, enum lsm6ds0_cmd cmd, rt_uint16_t param)
{
    rt_uint8_t data = 0;
    rt_err_t res = RT_EOK;

    RT_ASSERT(dev);

    switch (cmd)
    {
    case LSM6DS0_GYRO_RANGE:  /* Gyroscope full scale range */
        res = lsm6ds0_write_bits(dev, LSM6DS3_ACC_GYRO_CTRL2_G, 2, 2, param);
        dev->config.gyro_range = param;
        break;
    case LSM6DS0_ACCEL_RANGE: /* Accelerometer full scale range */
        res = lsm6ds0_write_bits(dev, LSM6DS3_ACC_GYRO_CTRL1_XL, 2, 2, param);
        dev->config.accel_range = param;
        break;
    case LSM6DS0_DLPF_CONFIG: /* Digital Low Pass Filter */
        //res = lsm6ds0_write_bits(dev, MPU6XXX_RA_CONFIG, MPU6XXX_CFG_DLPF_CFG_BIT, MPU6XXX_CFG_DLPF_CFG_LENGTH, param);
        break;
    case LSM6DS0_SAMPLE_RATE: /* Sample Rate —— 16-bit unsigned value.
                                 Sample Rate = [1000 -  4]HZ when dlpf is enable
                                 Sample Rate = [8000 - 32]HZ when dlpf is disable */

//        //Sample Rate = Gyroscope Output Rate / (1 + SMPLRT_DIV)
//        res = lsm6ds0_read_bits(dev, MPU6XXX_RA_CONFIG, MPU6XXX_CFG_DLPF_CFG_BIT, MPU6XXX_CFG_DLPF_CFG_LENGTH, &data);
//        if (res != RT_EOK)
//        {
//            break;
//        }

//        if (data == 0 || data == 7) /* dlpf is disable */
//        {
//            if (param > 8000)
//                data = 0;
//            else if (param < 32)
//                data = 0xFF;
//            else
//                data = 8000 / param - 1;
//        }
//        else /* dlpf is enable */
//        {
//            if (param > 1000)
//                data = 0;
//            else if (param < 4)
//                data = 0xFF;
//            else
//                data = 1000 / param - 1;
//        }
//        res = lsm6ds0_write_reg(dev, MPU6XXX_RA_SMPLRT_DIV, data);
        break;
    case LSM6DS0_SLEEP: /* Configure sleep mode */
        res = lsm6ds0_write_bit(dev, LSM6DS3_ACC_GYRO_FIFO_CTRL4, 6, param);
        break;
    }

    return res;
}

/**
* This function gets the data of the accelerometer, unit: mg
 *
 * @param dev the pointer of device driver structure
 * @param accel the pointer of 3axes structure for receive data
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
rt_err_t lsm6ds0_get_accel(struct lsm6ds0_device *dev, struct mpu6xxx_3axes *accel)
{
    struct mpu6xxx_3axes tmp;
    rt_uint16_t sen;
    rt_err_t res;

    res = lsm6ds0_get_accel_raw(dev, &tmp);
    if (res != RT_EOK)
    {
        return res;
    }

    sen = MPU6XXX_ACCEL_SEN >> dev->config.accel_range;

    accel->x = (rt_int32_t)tmp.x * 1000 / sen;
    accel->y = (rt_int32_t)tmp.y * 1000 / sen;
    accel->z = (rt_int32_t)tmp.z * 1000 / sen;

    return RT_EOK;
}

/**
* This function gets the data of the gyroscope, unit: deg/10s
 *
 * @param dev the pointer of device driver structure
 * @param gyro the pointer of 3axes structure for receive data
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
rt_err_t lsm6ds0_get_gyro(struct lsm6ds0_device *dev, struct mpu6xxx_3axes *gyro)
{
    struct mpu6xxx_3axes tmp;
    rt_uint16_t sen;
    rt_err_t res;

    res = lsm6ds0_get_gyro_raw(dev, &tmp);
    if (res != RT_EOK)
    {
        return res;
    }

    sen = MPU6XXX_GYRO_SEN >> dev->config.gyro_range;

    gyro->x = (rt_int32_t)tmp.x * 100 / sen;
    gyro->y = (rt_int32_t)tmp.y * 100 / sen;
    gyro->z = (rt_int32_t)tmp.z * 100 / sen;

    return RT_EOK;
}

/**
 * This function gets the data of the temperature, unit: Centigrade
 *
 * @param dev the pointer of device driver structure
 * @param temp read data pointer
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
rt_err_t lsm6ds0_get_temp(struct lsm6ds0_device *dev, float *temp)
{
    rt_int16_t tmp;
    rt_err_t res;

    res = lsm6ds0_get_temp_raw(dev, &tmp);
    if (res != RT_EOK)
    {
        return res;
    }

    if (dev->id == LSM6DS0_ACC_GYRO_WHO_AM_I)
    {
        /* mpu60x0: Temperature in degrees C = (TEMP_OUT Register Value as a signed quantity)/340 + 36.53 */
        *temp = (double)tmp / MPU60X0_TEMP_SEN + MPU60X0_TEMP_OFFSET;
    }
    else
    {
        /* mpu6500:  ((TEMP_OUT – RoomTemp_Offset)/Temp_Sensitivity)+ 21degC */
        *temp = (double)tmp / MPU6500_TEMP_SEN + MPU6500_TEMP_OFFSET;
    }

    return RT_EOK;
}

/**
 * This function initialize the mpu6xxx device.
 *
 * @param dev_name the name of transfer device
 * @param param the i2c device address for i2c communication, RT_NULL for spi
 *
 * @return the pointer of device driver structure, RT_NULL reprensents  initialization failed.
 */
struct lsm6ds0_device *lsm6ds0_init(const char *dev_name, rt_uint8_t param)
{
    struct lsm6ds0_device *dev = RT_NULL;
    rt_uint8_t reg = 0xFF, res = RT_EOK;

    RT_ASSERT(dev_name);

    dev = rt_calloc(1, sizeof(struct lsm6ds0_device));
    if (dev == RT_NULL)
    {
        LOG_E("Can't allocate memory for mpu6xxx device on '%s' ", dev_name);
        goto __exit;
    }

    dev->bus = rt_device_find(dev_name);
    if (dev->bus == RT_NULL)
    {
        LOG_E("Can't find device:'%s'", dev_name);
        goto __exit;
    }

    if (dev->bus->type == RT_Device_Class_I2CBUS)
    {
#ifdef RT_USING_I2C
        if (param != RT_NULL)
        {
            dev->i2c_addr = param;
        }ge
        else
        {
            /* find mpu6xxx device at address: 0x68 */
            dev->i2c_addr = MPU6XXX_ADDRESS_AD0_LOW;
            if (mpu6xxx_read_regs(dev, MPU6XXX_RA_WHO_AM_I, 1, &reg) != RT_EOK)
            {
                /* find mpu6xxx device at address 0x69 */
                dev->i2c_addr = MPU6XXX_ADDRESS_AD0_HIGH;
                if (mpu6xxx_read_regs(dev, MPU6XXX_RA_WHO_AM_I, 1, &reg) != RT_EOK)
                {
                    LOG_E("Can't find device at '%s'!", dev_name);
                    goto __exit;
                }
            }
            LOG_D("Device i2c address is:'0x%x'!", dev->i2c_addr);
        }
#endif
    }
    else if (dev->bus->type == RT_Device_Class_SPIBUS)
    {
#ifdef RT_USING_SPI
        struct rt_spi_configuration cfg;

        cfg.data_width = 8;
        cfg.mode = RT_SPI_MASTER | RT_SPI_MODE_0 | RT_SPI_MSB;
        cfg.max_hz = LSM6DS0_SPI_MAX_SPEED; /* Set spi max speed */

        rt_spi_configure((struct rt_spi_device *)dev->bus, &cfg);
#endif
    }
    else
    {
        LOG_E("Unsupported device:'%s'!", dev_name);
        goto __exit;
    }

    if (lsm6ds0_read_regs(dev, LSM6DS3_ACC_GYRO_WHO_AM_I_REG, 1, &reg) != RT_EOK)
    {
        LOG_E("Failed to read device id!");
        goto __exit;
    }

    dev->id = reg;

    switch (dev->id)
    {
	case LSM6DS0_ACC_GYRO_WHO_AM_I:
		LOG_E("device is lsm6dsx imu\r\n");
	break;
    case 0xFF:
        LOG_E("No device connection!");
        goto __exit;
    default:
        LOG_W("Unknown device id: 0x%x!", reg);
    }

    res += lsm6ds0_get_param(dev, LSM6DS0_ACCEL_RANGE, &dev->config.accel_range);
    res += lsm6ds0_get_param(dev, LSM6DS0_GYRO_RANGE, &dev->config.gyro_range);

    //res += lsm6ds0_write_bits(dev, MPU6XXX_RA_PWR_MGMT_1, MPU6XXX_PWR1_CLKSEL_BIT, MPU6XXX_PWR1_CLKSEL_LENGTH, MPU6XXX_CLOCK_PLL_XGYRO);
    res += lsm6ds0_set_param(dev, LSM6DS0_ACCEL_RANGE, LSM6DS0_GYRO_RANGE_250DPS);
    res += lsm6ds0_set_param(dev, LSM6DS0_GYRO_RANGE, LSM6DS0_ACCEL_RANGE_2G);
    res += lsm6ds0_set_param(dev, LSM6DS0_SLEEP, LSM6DS0_SLEEP_DISABLE);

    if (res == RT_EOK)
    {
        LOG_I("Device init succeed!");
    }
    else
    {
        LOG_W("Error in device initialization!");
    }
    return dev;

__exit:
    if (dev != RT_NULL)
    {
        rt_free(dev);
    }
    return RT_NULL;
}

/**
 * This function releases memory
 *
 * @param dev the pointer of device driver structure
 */
void lsm6ds0_deinit(struct lsm6ds0_device *dev)
{
    RT_ASSERT(dev);

    rt_free(dev);
}

