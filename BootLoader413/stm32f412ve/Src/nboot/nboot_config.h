#ifndef __NBOOT_CONFIG_H__
#define __NBOOT_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

//#define RTT_ENABLE
//#define NBOOT_DEBUG

#define IMAGE_META_DATA_ADDR        0x08008000
#define IMAGE_META_DATA_MAX_SIZE    0x800
#define IMAGE_SLOT_A_START          0x08010000
#define MAX_IMAGE_SIZE              ((64+128)*1024)

#ifdef __cplusplus
}
#endif

#endif /* __NBOOT_CONFIG_H__ */
