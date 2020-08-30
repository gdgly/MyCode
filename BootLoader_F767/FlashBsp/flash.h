/**
 * @file flash.h
 * @author Segway Inside 
 * @brief STM32 Ƭ�� FLASH �����ӿں���
 * @version 1.0
 * @date 2020-01-21
 * 
 * @copyright Copyright (c) 2020 �ɶ������������Ƽ����޹�˾
 * All rights reserved.
 * 
 */

#ifndef __FLASH_H_
#define __FLASH_H_

#include <stdint.h>
#include <string.h>
#include "flash_config.h"

/**
 * @brief ���ֽڶ�ȡFLASH����
 * 
 * @param addr ���ݶ�ȡ��ʼ��ַ
 * @param buf ָ�����ȡ���ݵ�bufferָ��
 * @param size ����ȡ���ݴ�С�����ֽ�Ϊ��λ
 * @return int 
 *              ERROR_FLASH_MISALIGN        ��ַδ����
 *              ERROR_FLASH_OUT_OF_RANGE    ��ַ������FLASH��Ч���ݷ�Χ
 *              > 0                         ʵ�ʶ�ȡ���ֽ���
 */
int flash_read(uint32_t addr, uint8_t *buf, uint32_t size);

/**
 * @brief ���ֽ�д��FLASH����
 * 
 * @param addr ����д����ʼ��ַ
 * @param buf ָ���д�����ݵ�bufferָ��
 * @param size ��д�����ݴ�С�����ֽ�Ϊ��λ
 * @return int 
 *              ERROR_FLASH_MISALIGN        ��ַδ����
 *              ERROR_FLASH_OUT_OF_RANGE    ��ַ������FLASH��Ч���ݷ�Χ
 *              ERROR_FLASH_PROGRAM_FAIL    ����д�뷢������
 *              > 0                         ʵ��д����ֽ���
 */
int flash_write(uint32_t addr, const uint8_t *buf, uint32_t size);

/**
 * @brief ����ָ����ַ��ʼ�ĵ���/���SECTOR
 * 
 * @param addr ������ʼ��ַ
 * @param size ������С�����ֽ�Ϊ��λ
 * @return int 
 *              ERROR_FLASH_MISALIGN        ��ַδ����
 *              ERROR_FLASH_OUT_OF_RANGE    ��ַ������FLASH��Ч���ݷ�Χ
 *              ERROR_FLASH_ERASE_FAIL      ������������
 *              > 0                         ʵ�ʲ�����С
 */
int flash_erase(uint32_t addr, uint32_t size);


#endif
