#ifndef AT_FILE_H
#define AT_FILE_H

#define AT_FILE_NAME_SIZE_MAX 80
#define AT_FILE_OPEN_MAX      20
#define AT_FILE_BUFFER_MAX    1024

#include "at_device.h"

//The open mode of the file.
#define AT_FILE_O_CREAT_WR    0
#define AT_FILE_O_CREAT_TRUNC 1
#define AT_FILE_O_RDONLY      2

//Set File Pointer to a Position
#define AT_FILE_SEEK_SET 0
#define AT_FILE_SEEK_CUR 1
#define AT_FILE_SEEK_END 2

struct at_file;

struct at_file_ops
{
    int (*open)(struct at_file *file, char *name, int mode);
    int (*read)(struct at_file *file, int handle, uint8_t *buf, int nbytes);
    int (*write)(struct at_file *file, int handle, uint8_t *buf, int nbytes);
    int (*seek)(struct at_file *file, int handle, int offset, int position);
    int (*position)(struct at_file *file, int handle);
    int (*close)(struct at_file *file, int handle);
    int (*delete)(struct at_file *file, char *name);
    int (*upload)(struct at_file *file, char *name, uint8_t *buf, int nbytes);
};

struct at_file
{
    void *device;
    const struct at_file_ops *ops;
    
    rt_event_t urc_event;                       /* AT device urc event */

    int handle[AT_FILE_OPEN_MAX];
    uint8_t recv_buf[AT_FILE_BUFFER_MAX];
    int recv_len;
    /* user-specific data */
    int is_init;
    void *user_data;
};

int at_file_init(struct at_file_ops *ops, struct at_device *device);
int at_file_deinit(void);
int at_file_open(char *name, int mode);
int at_file_read(int handle, uint8_t *buf, int nbytes);
int at_file_write(int handle, uint8_t *buf, int nbytes);
int at_file_seek(int handle, int offset, int position);
int at_file_position(int handle);
int at_file_close(int handle);
int at_file_delete(char *name);
int at_file_upload(char *name, uint8_t *buf, int nbytes);
struct at_file *at_file_get_ctx(int handle);

#endif
