/**
 * @file nb_crypto.h
 * @author Segway Insight 
 * @brief NB_CRYPTO ���ܽ����㷨��NB_CRYPTO ���ܽ����㷨���lib���ṩ���ýӿ�
 *        ������Flash�����洢���ܣ���������ͨѶ����
 * @version 1.0.1
 * @date 2019-11-05
 * 
 * @copyright Copyright (c) 2019 �ɶ������������Ƽ����޹�˾
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
 * @brief ���ؼӽ��ܿ�汾��
 * 
 * @return ���ܿ�汾��ָ��
 */
const char *get_lib_version(void);

/**
 * @brief ���ؼӽ��ܿ�lib�ļ���
 * 
 * @return �ӽ��ܿ�lib�ļ���ָ��
 */
const char *get_lib_name(void);

/**
 * @brief Ninebot NB_CRYPTO �����㷨
 * 
 * @param plain			��������ָ��
 * @param plain_size	��Ҫ���ܵ��ֽ���
 
 * @param cipher			��������ָ��
 * @param cipher_max_len	��������ָ��ָ��Ŀռ��С(�ֽ�), ������ cipher_max_len >= (plain_size + 4)
 
 * @param key			��Կָ��
 * @param key_size		��Կ����(��֧��16�ֽ���Կ, ����Ϊ16)


 * @return int
 *              ����0	                            ���ĵ��ֽ��� (plain_size + 4)
 *              ERROR_PLAIN_NULL		            plain == NULL
 *              ERROR_INVALID_PLAIN_SIZE		    plain_size ��С����
 *              ERROR_CIPHER_NULL		            cipher == NULL
 *              ERROR_CIPHER_BUFFER_NOT_ENOUGH      cipher_max_len ��С����
 *              ERROR_KEY_NULL                      key == NULL
 *              ERROR_INVALID_KEY_SIZE              key_size ��С����
**/

int nb_crypto_encrypt(const uint8_t *plain, uint16_t plain_size,
                      uint8_t *cipher, uint16_t cipher_max_len, const uint8_t *key, uint8_t key_size);

/**
 * @brief Ninebot NB_CRYPTO �����㷨
 * 
 * @param cipher		��������ָ��
 * @param cipher_size	�����ֽ���
 
 * @param plain			��������ָ��
 * @param plain_max_len	��������ָ��ָ��Ŀռ��С(�ֽ�),������ ������ plain_max_len >= (cipher_size - 4)
 
 * @param key			��Կָ��
 * @param size_key		��Կ����(��֧��16�ֽ���Կ, ����Ϊ16)
 
 * @return int
 *              ����0	                            ԭ�ĵ��ֽ���
 *              ERROR_CIPHER_NULL                   cipher == NULL
 *              ERROR_INVALID_CIPHER_SIZE           cipher_size ��С����
 *              ERROR_PLAIN_NULL                    plain == NULL
 *              ERROR_PLAIN_BUFFER_NOT_ENOUGH       plain_max_len ��С����
 *              ERROR_KEY_NULL                      key == NULL
 *              ERROR_INVALID_KEY_SIZE              key_size ��С����
 *              ERROR_AUTH_NOT_MATCH                ������֤����
**/

int nb_crypto_decrypt(const uint8_t *cipher, uint16_t cipher_size,
                      uint8_t *plain, uint16_t plain_max_len, const uint8_t *key, uint8_t key_size);

#endif


