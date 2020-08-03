/*
 * Copyright (c) 2006-2018, RT-Thread Development Team
 *
 * SPDX-License-Identifier: Apache-2.0
 *
 * Change Logs:
 * Date           Author       Notes
 * 2018-10-23     flybreak     the first version
 */

#ifndef LSM6DS0_H_
#define LSM6DS0_H_

#include <rtthread.h>

/* Accelerometer full scale range */
enum mpu6xxx_accel_range
{
    LSM6DS0_ACCEL_RANGE_2G  = 0, // ±2G
    LSM6DS0_ACCEL_RANGE_4G  = 1, // ±16G
    LSM6DS0_ACCEL_RANGE_8G  = 2, // ±4G
    LSM6DS0_ACCEL_RANGE_16G = 3  // ±8G
};

/* Gyroscope full scale range */
enum mpu6xxx_gyro_range
{
    LSM6DS0_GYRO_RANGE_250DPS  = 0, // ±245°/s
    LSM6DS0_GYRO_RANGE_500DPS  = 1, // ±500°/s
    LSM6DS0_GYRO_RANGE_1000DPS = 2, // ±1000°/s
    LSM6DS0_GYRO_RANGE_2000DPS = 3  // ±2000°/s
};

/* Digital Low Pass Filter parameters */
enum mpu6xxx_dlpf
{
    MPU6XXX_DLPF_DISABLE = 0, //256HZ
    MPU6XXX_DLPF_188HZ = 1,
    MPU6XXX_DLPF_98HZ  = 2,
    MPU6XXX_DLPF_42HZ  = 3,
    MPU6XXX_DLPF_20HZ  = 4,
    MPU6XXX_DLPF_10HZ  = 5,
    MPU6XXX_DLPF_5HZ   = 6
};

/* sleep mode parameters */
enum mpu6xxx_sleep
{
    LSM6DS0_SLEEP_DISABLE = 0,
    LSM6DS0_SLEEP_ENABLE  = 1
};

/* Supported configuration items */
enum lsm6ds0_cmd
{
    LSM6DS0_GYRO_RANGE,  /* Gyroscope full scale range */
    LSM6DS0_ACCEL_RANGE, /* Accelerometer full scale range */
    LSM6DS0_DLPF_CONFIG, /* Digital Low Pass Filter */
    LSM6DS0_SAMPLE_RATE, /* Sample Rate —— 16-bit unsigned value.
                            Sample Rate = [1000 -  4]HZ when dlpf is enable
                            Sample Rate = [8000 - 32]HZ when dlpf is disable */
    LSM6DS0_SLEEP        /* Sleep mode */
};

/* 3-axis data structure */
struct mpu6xxx_3axes
{
    rt_int16_t x;
    rt_int16_t y;
    rt_int16_t z;
};

/* mpu6xxx config structure */
struct lsm6ds0_config
{
    rt_uint16_t accel_range;
    rt_uint16_t gyro_range;
};

/* mpu6xxx device structure */
struct lsm6ds0_device
{
    rt_device_t bus;
    rt_uint8_t id;
    rt_uint8_t i2c_addr;
    struct lsm6ds0_config config;
};

/**
 * This function initialize the mpu6xxx device.
 *
 * @param dev_name the name of transfer device
 * @param param the i2c device address for i2c communication, RT_NULL for spi
 *
 * @return the pointer of device driver structure, RT_NULL reprensents  initialization failed.
 */
struct lsm6ds0_device *lsm6ds0_init(const char *dev_name, rt_uint8_t param);

/**
 * This function releases memory
 *
 * @param dev the pointer of device driver structure
 */
void lsm6ds0_deinit(struct lsm6ds0_device *dev);

/**
 * This function set mpu6xxx parameters.
 *
 * @param dev the pointer of device driver structure
 * @param cmd Configuration item
 * @param param Configuration item parameter
 *
 * @return the setting status, RT_EOK reprensents  setting the parameter successfully.
 */
rt_err_t lsm6ds0_set_param(struct lsm6ds0_device *dev, enum lsm6ds0_cmd cmd, rt_uint16_t param);

/**
* This function gets the data of the accelerometer, unit: mg
 *
 * @param dev the pointer of device driver structure
 * @param accel the pointer of 3axes structure for receive data
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
rt_err_t lsm6ds0_get_accel(struct lsm6ds0_device *dev, struct mpu6xxx_3axes *accel);

/**
* This function gets the data of the gyroscope, unit: deg/10s
 *
 * @param dev the pointer of device driver structure
 * @param gyro the pointer of 3axes structure for receive data
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
rt_err_t lsm6ds0_get_gyro(struct lsm6ds0_device *dev, struct mpu6xxx_3axes *gyro);

/**
 * This function gets the data of the temperature, unit: Centigrade
 *
 * @param dev the pointer of device driver structure
 * @param temp read data pointer
 *
 * @return the reading status, RT_EOK reprensents  reading the data successfully.
 */
rt_err_t lsm6ds0_get_temp(struct lsm6ds0_device *dev, float *temp);

#endif //LSM6DS0_H_
