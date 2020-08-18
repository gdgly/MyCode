/**
 * @file nboot.h
 * @author Segway Inside 
 * @brief �� IAP �̼������йصĺ���
 * @version 0.2
 * @date 2020-03-06
 * 
 * @copyright Copyright (c) 2020 �ɶ������������Ƽ����޹�˾
 * All rights reserved.
 * 
 */
#ifndef __NBOOT_H_
#define __NBOOT_H_

#include <stdint.h>
#include "nboot_config.h"
#include "flash_utils.h"

enum {
    IMAGE_STATE_INVALID = 0,
    IMAGE_STATE_DOWNLOAD_OK,
};

#define IMAGE_DOWN_MAGIC            0xa5389ace

#if !defined(IMAGE_META_DATA_ADDR)
#define IMAGE_META_DATA_ADDR        0x08008000
#endif

#if !defined(IMAGE_META_DATA_MAX_SIZE)
#define IMAGE_META_DATA_MAX_SIZE    0x800
#endif

#if !defined(IMAGE_SLOT_A_START)
#define IMAGE_SLOT_A_START          0x08010000
#endif

#if !defined(MAX_IMAGE_SIZE)
#define MAX_IMAGE_SIZE              ((64+128)*1024)
#endif

#if !defined(IMAGE_SLOT_A_END)
#define IMAGE_SLOT_A_END            (IMAGE_SLOT_A_START+MAX_IMAGE_SIZE-1)
#endif

#if !defined(IMAGE_SLOT_B_START)
#define IMAGE_SLOT_B_START          (IMAGE_SLOT_A_END+1)
#endif

#if !defined(IMAGE_SLOT_B_END)
#define IMAGE_SLOT_B_END            (IMAGE_SLOT_B_START+MAX_IMAGE_SIZE-1)
#endif

typedef struct {
    uint32_t start;
    uint32_t end;
} Slot_Range;

typedef struct {
    uint32_t magic_bytes;
    uint8_t down_state;
    uint32_t down_size;
} IAP_Images_Down_State;

typedef struct {
    uint32_t flash_start_addr;
    Flash_Backend_Type *backend;
} Temp_Flash_Context;

/**
 * @brief ��ȡ�̼����ش洢�����̼�����֮ǰ���ã���������Ƭ��FLASH��
 * 
 * @return const Slot_Range*    ָ��̼���������ַ��Ϣ
 */
const Slot_Range *nboot_get_down_slot(void);

/**
 * @brief ��ȡ�̼�����״̬
 * 
 * @param down_state        ���ڻ�ȡ�̼�����״̬��ָ��
 * @param down_size         ���ڻ�ȡ�̼���С��ָ��
 * @return int 
 *                  0       ��ȡ�ɹ�
 *                  < 0     ��ȡʧ��
 */
int nboot_get_image_down_state(uint8_t *down_state, uint32_t *down_size);

/**
 * @brief ���ù̼�����״̬
 * 
 * @param down_state        �̼�����״̬
 * @param down_size         �̼���С
 * @return int 
 *                  0       ���óɹ�
 *                  < 0     ����ʧ��
 */
int nboot_set_image_down_state(uint8_t down_state, uint32_t down_size);

/**
 * @brief ����Ӧ�ó���������¹̼����ȿ����̼���
 * 
 * @param flash_ctx         ��ʱ�����̼���������Flash����������
 */
void boot_app(const Temp_Flash_Context *flash_ctx);

#endif
