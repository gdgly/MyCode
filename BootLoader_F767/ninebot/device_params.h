/**
 * @file device_params.h
 * @author Segway Inside 
 * @brief Flash �������ܴ�ȡͨ�ýӿڣ����� NB_CRYPTO ���ܽ����㷨����Ҫ�����Ӧ�� lib ���ͷ�ļ�
 * @version 1.1
 * @date 2020-02-13
 * 
 * @copyright Copyright (c) 2020 �ɶ������������Ƽ����޹�˾
 * All rights reserved.
 * 
 */
#ifndef __DEVICE_PARAMS_H_
#define __DEVICE_PARAMS_H_

#include <stdint.h>
#include "flash_utils.h"

// #define ENCRYPT_PARAMS_ADDR         0x0800C000

#define ENCRYPT_PARAMS_MAX_SIZE     0x800
#define ENCRYPT_MIC_SIZE            4
#define MAX_BUFFER_LEN              512
#define MAX_PARAMS_LEN              (MAX_BUFFER_LEN - ENCRYPT_MIC_SIZE)

#define ERROR_PARAMS_OK                     0
#define ERROR_PARAMS_INVALID_PARAM          -1
#define ERROR_PARAMS_ENCRYPT_FAILED         -2
#define ERROR_PARAMS_DECRYPT_FAILED         -3
#define ERROR_PARAMS_FLASH_ERROR            -4

typedef struct {
    uint32_t params_start_addr;
    Flash_Backend_Type *backend;
} Params_Context;


/**
 * @brief ������Ĳ������ܲ��洢��ָ����Flash����
 * 
 * @param ctx           ָ�������ʼ��ַ��Flash����������ָ�룬���û�����
 * @param params        �����ܲ�����ָ��
 * @param params_len    �����ܲ����ֽ���
 * @param key           ��Կָ��
 * @param key_size      ��Կ����(��֧��16�ֽ���Կ, ����Ϊ16)
 * @return int 
 *                      ERROR_PARAMS_OK                     �������ܲ��ɹ��洢��Flash
 *                      ERROR_PARAMS_INVALID_PARAM          ��������
 *                      ERROR_PARAMS_ENCRYPT_FAILED         ��������ʱ�����˴���
 *                      ERROR_PARAMS_FLASH_ERROR            ����Flashʱ�����˴���
 */
int encrypt_and_save_params(const Params_Context *ctx, const uint8_t *params, int params_len, const uint8_t *key, uint8_t key_size);

/**
 * @brief ��ָ��Flash�����ȡ�����ؽ��ܺ�Ĳ���
 * 
 * @param ctx               ָ�������ʼ��ַ��Flash����������ָ�룬���û�����
 * @param params_buf        ���ڽ����ѽ��ܲ�����bufferָ��
 * @param params_buf_len    buffer����
 * @param params_len        ����ǰ�����ֽ���
 * @param key               ��Կָ��
 * @param key_size          ��Կ����(��֧��16�ֽ���Կ, ����Ϊ16)
 * @return int 
 *                          ERROR_PARAMS_OK                     ������ȡ�����ܳɹ�
 *                          ERROR_PARAMS_INVALID_PARAM          ��������
 *                          ERROR_PARAMS_DECRYPT_FAILED         ��������ʱ�����˴���
 *                          ERROR_PARAMS_FLASH_ERROR            ����Flashʱ�����˴���
 */
int decrypt_and_load_params(const Params_Context *ctx, uint8_t *params_buf, int params_buf_len, int params_len, const uint8_t *key, uint8_t key_size);

#endif

