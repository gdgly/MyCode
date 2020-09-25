#ifndef __NBOOT_CONFIG_H__
#define __NBOOT_CONFIG_H__

#ifdef __cplusplus
extern "C" {
#endif

//#define RTT_ENABLE
//#define NBOOT_DEBUG

#define IMAGE_META_DATA_ADDR        0x08004000
#define IMAGE_META_DATA_MAX_SIZE    0x4000
#define IMAGE_SLOT_A_START          0x08008000
#define MAX_IMAGE_SIZE              ((16+16+64+128+128+128)*1024)//480K

#ifdef __cplusplus
}
#endif

#endif /* __NBOOT_CONFIG_H__ */
