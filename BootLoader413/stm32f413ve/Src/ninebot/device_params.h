/**
 * @file device_params.h
 * @author Segway Inside 
 * @brief Flash 参数加密存取通用接口，基于 NB_CRYPTO 加密解密算法，需要添加相应的 lib 库和头文件
 * @version 1.1
 * @date 2020-02-13
 * 
 * @copyright Copyright (c) 2020 纳恩博（北京）科技有限公司
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
 * @brief 将传入的参数加密并存储到指定的Flash区域
 * 
 * @param ctx           指向参数起始地址和Flash操作函数的指针，需用户传入
 * @param params        待加密参数的指针
 * @param params_len    待加密参数字节数
 * @param key           密钥指针
 * @param key_size      密钥长度(仅支持16字节密钥, 必须为16)
 * @return int 
 *                      ERROR_PARAMS_OK                     参数加密并成功存储到Flash
 *                      ERROR_PARAMS_INVALID_PARAM          参数错误
 *                      ERROR_PARAMS_ENCRYPT_FAILED         参数加密时发生了错误
 *                      ERROR_PARAMS_FLASH_ERROR            操作Flash时发生了错误
 */
int encrypt_and_save_params(const Params_Context *ctx, const uint8_t *params, int params_len, const uint8_t *key, uint8_t key_size);

/**
 * @brief 从指定Flash区域读取并返回解密后的参数
 * 
 * @param ctx               指向参数起始地址和Flash操作函数的指针，需用户传入
 * @param params_buf        用于接收已解密参数的buffer指针
 * @param params_buf_len    buffer长度
 * @param params_len        加密前参数字节数
 * @param key               密钥指针
 * @param key_size          密钥长度(仅支持16字节密钥, 必须为16)
 * @return int 
 *                          ERROR_PARAMS_OK                     参数读取并解密成功
 *                          ERROR_PARAMS_INVALID_PARAM          参数错误
 *                          ERROR_PARAMS_DECRYPT_FAILED         参数解密时发生了错误
 *                          ERROR_PARAMS_FLASH_ERROR            操作Flash时发生了错误
 */
int decrypt_and_load_params(const Params_Context *ctx, uint8_t *params_buf, int params_buf_len, int params_len, const uint8_t *key, uint8_t key_size);

#endif

