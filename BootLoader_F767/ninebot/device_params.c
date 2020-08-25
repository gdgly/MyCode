/**
 * @file device_params.c
 * @author Segway Inside 
 * @brief Flash �������ܴ�ȡͨ�ýӿڣ����� NB_CRYPTO ���ܽ����㷨����Ҫ�����Ӧ�� lib ���ͷ�ļ�
 * @version 1.1
 * @date 2020-02-13
 * 
 * @copyright Copyright (c) 2020 �ɶ������������Ƽ����޹�˾
 * All rights reserved.
 * 
 */

#include "nb_crypto.h"
#include "device_params.h"
#include "flash.h"

static uint8_t buffer[MAX_BUFFER_LEN] = {0};
static uint8_t flash_cache[ENCRYPT_PARAMS_MAX_SIZE] = {0};

int encrypt_and_save_params(const Params_Context *ctx, const uint8_t *params, int params_len, const uint8_t *key, uint8_t key_size)
{
    int ret = 0;
    int cipher_len = 0;

    if (ctx == NULL || ctx->backend == NULL 
        || ctx->backend->read == NULL || ctx->backend->write == NULL || ctx->backend->erase == NULL
        || params == NULL || key == NULL || params_len > MAX_PARAMS_LEN)
    {
        ret = ERROR_PARAMS_INVALID_PARAM;
        goto err;
    }

    cipher_len = nb_crypto_encrypt(params, params_len, buffer, sizeof(buffer), key, key_size);
    if (cipher_len < 0)
    {
        ret = ERROR_PARAMS_ENCRYPT_FAILED;
        goto err;
    }

    // ������ܲ����� Flash
    ret = ctx->backend->read(ctx->params_start_addr, flash_cache, ENCRYPT_PARAMS_MAX_SIZE);
    if (ret < 0)
    {
        ret = ERROR_PARAMS_FLASH_ERROR;
        goto err;
    }
    memcpy(flash_cache, buffer, cipher_len);
    ret = ctx->backend->erase(ctx->params_start_addr, ENCRYPT_PARAMS_MAX_SIZE);
    if (ret < 0)
    {
        ret = ERROR_PARAMS_FLASH_ERROR;
        goto err;
    }
    ret = ctx->backend->write(ctx->params_start_addr, flash_cache, ENCRYPT_PARAMS_MAX_SIZE);
    if (ret < 0)
    {
        ret = ERROR_PARAMS_FLASH_ERROR;
        goto err;
    }

    return ERROR_PARAMS_OK;
err:
    return ret;
}

int decrypt_and_load_params(const Params_Context *ctx, uint8_t *params_buf, int params_buf_len, int params_len, const uint8_t *key, uint8_t key_size)
{
    int ret = 0;
    int plain_len = 0;
    int cipher_len = 0;

    if (ctx == NULL || ctx->backend == NULL 
        || ctx->backend->read == NULL || ctx->backend->write == NULL || ctx->backend->erase == NULL
        || params_buf == NULL || key == NULL || params_len > MAX_PARAMS_LEN)
    {
        ret = ERROR_PARAMS_INVALID_PARAM;
        goto err;
    }
    
    cipher_len = params_len + ENCRYPT_MIC_SIZE;
    // �� Flash ��ȡ���ܲ���
    ret = ctx->backend->read(ctx->params_start_addr, buffer, cipher_len);
    if (ret < 0)
    {
        ret = ERROR_PARAMS_FLASH_ERROR;
        goto err;
    }
    plain_len = nb_crypto_decrypt(buffer, cipher_len, params_buf, params_buf_len, key, key_size);
    if (plain_len < 0)
    {
        ret = ERROR_PARAMS_DECRYPT_FAILED;
        goto err;
    }

    return ERROR_PARAMS_OK;
err:
    return ret;
}
