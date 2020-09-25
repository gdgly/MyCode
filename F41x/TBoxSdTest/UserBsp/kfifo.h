#ifndef __KFIFO_H
#define __KFIFO_H

#include "stdint.h"
#include "string.h"
#include "stdlib.h"
#include "bsp_can.h"




#define is_power_of_2(x) ((x) != 0 && (((x) & ((x)-1)) == 0))

typedef struct
{
    unsigned char *buffer;  /* the buffer holding the data*/
    unsigned int size;      /* the size of the allocated buffer*/
    unsigned int in;        /* data is added at offset (in % size)*/
    unsigned int out;       /* data is extracted from off. (out % size)*/
} my_fifo;

/**
  * @brief  CAN Rx message structure definition
  */



extern my_fifo gFifoReg1;
extern my_fifo gFifoReg2;
extern my_fifo gFifoReg3;


void my_fifo_init(my_fifo *fifo, unsigned char *buffer, unsigned int size);
unsigned int my_fifo_put(my_fifo *fifo, unsigned char *buffer, unsigned int len);
unsigned int my_fifo_get(my_fifo *fifo, unsigned char *buffer, unsigned int len);

void my_fifo_reset(my_fifo *fifo);
unsigned int my_fifo_len(my_fifo *fifo);



void can_kfifo_init (my_fifo* fifo, void* buffer, uint32_t size);
uint32_t can_kfifo_get (my_fifo* rb, void* buffer, uint32_t len);
uint32_t can_kfifo_put (my_fifo* rb, void* buffer, uint32_t len);

#endif
