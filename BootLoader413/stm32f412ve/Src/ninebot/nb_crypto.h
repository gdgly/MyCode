/**
 * @file nb_crypto.h
 * @author Segway Insight 
 * @brief NB_CRYPTO 加密解密算法，NB_CRYPTO 加密解密算法打包lib，提供调用接口
 *        适用于Flash参数存储加密，不适用于通讯加密
 * @version 1.0.1
 * @date 2019-11-05
 * 
 * @copyright Copyright (c) 2019 纳恩博（北京）科技有限公司
 * All rights reserved.
 * 
 */
 
#ifndef _NB_CRYPTO_H_
#define _NB_CRYPTO_H_

#include "stdint.h"

#define ERROR_PLAIN_NULL                -1
#define ERROR_INVALID_PLAIN_SIZE        -2
#define ERROR_CIPHER_NULL               -3
#define ERROR_CIPHER_BUFFER_NOT_ENOUGH  -4
#define ERROR_KEY_NULL                  -5
#define ERROR_INVALID_KEY_SIZE          -6
#define ERROR_INVALID_CIPHER_SIZE       -7
#define ERROR_PLAIN_BUFFER_NOT_ENOUGH   -8
#define ERROR_AUTH_NOT_MATCH            -9

/**
 * @brief 返回加解密库版本号
 * 
 * @return 加密库版本号指针
 */
const char *get_lib_version(void);

/**
 * @brief 返回加解密库lib文件名
 * 
 * @return 加解密库lib文件名指针
 */
const char *get_lib_name(void);

/**
 * @brief Ninebot NB_CRYPTO 加密算法
 * 
 * @param plain			明文数据指针
 * @param plain_size	需要加密的字节数
 
 * @param cipher			密文数据指针
 * @param cipher_max_len	密文数据指针指向的空间大小(字节), 需满足 cipher_max_len >= (plain_size + 4)
 
 * @param key			密钥指针
 * @param key_size		密钥长度(仅支持16字节密钥, 必须为16)


 * @return int
 *              大于0	                            密文的字节数 (plain_size + 4)
 *              ERROR_PLAIN_NULL		            plain == NULL
 *              ERROR_INVALID_PLAIN_SIZE		    plain_size 大小错误
 *              ERROR_CIPHER_NULL		            cipher == NULL
 *              ERROR_CIPHER_BUFFER_NOT_ENOUGH      cipher_max_len 大小错误
 *              ERROR_KEY_NULL                      key == NULL
 *              ERROR_INVALID_KEY_SIZE              key_size 大小错误
**/

int nb_crypto_encrypt(const uint8_t *plain, uint16_t plain_size,
                      uint8_t *cipher, uint16_t cipher_max_len, const uint8_t *key, uint8_t key_size);

/**
 * @brief Ninebot NB_CRYPTO 解密算法
 * 
 * @param cipher		密文数据指针
 * @param cipher_size	密文字节数
 
 * @param plain			明文数据指针
 * @param plain_max_len	明文数据指针指向的空间大小(字节),需满足 需满足 plain_max_len >= (cipher_size - 4)
 
 * @param key			密钥指针
 * @param size_key		密钥长度(仅支持16字节密钥, 必须为16)
 
 * @return int
 *              大于0	                            原文的字节数
 *              ERROR_CIPHER_NULL                   cipher == NULL
 *              ERROR_INVALID_CIPHER_SIZE           cipher_size 大小错误
 *              ERROR_PLAIN_NULL                    plain == NULL
 *              ERROR_PLAIN_BUFFER_NOT_ENOUGH       plain_max_len 大小错误
 *              ERROR_KEY_NULL                      key == NULL
 *              ERROR_INVALID_KEY_SIZE              key_size 大小错误
 *              ERROR_AUTH_NOT_MATCH                数据验证出错
**/

int nb_crypto_decrypt(const uint8_t *cipher, uint16_t cipher_size,
                      uint8_t *plain, uint16_t plain_max_len, const uint8_t *key, uint8_t key_size);

#endif


