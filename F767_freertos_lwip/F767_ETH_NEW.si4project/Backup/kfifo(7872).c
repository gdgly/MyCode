#include "kfifo.h"
#include "tool.h"
my_fifo gFifoReg1;
my_fifo gFifoReg2;
/*
 * kfifo��ʼ��
*/
void my_fifo_init(my_fifo *fifo, unsigned char *buffer, unsigned int size)
{
    if (!is_power_of_2(size))
    {
        return;
    }
    fifo->buffer = buffer;
    fifo->size = size;
    fifo->in = fifo->out = 0u;
    memset(fifo->buffer, 0, size);
}

/*
 * __kfifo_put - puts some data into the FIFO, no locking version
 * @fifo: the fifo to be used.
 * @buffer: the data to be added.
 * @len: the length of the data to be added.
 *
 * This function copies at most 'len' bytes from the 'buffer' into
 * the FIFO depending on the free space, and returns the number of
 * bytes copied.
 *
 * Note that with only one concurrent reader and one concurrent
 * writer, you don't need extra locking to use these functions.
 */

unsigned int my_fifo_put(my_fifo *fifo, unsigned char *buffer, unsigned int len)
{
    unsigned int l = 0;

    len = MIN(len, fifo->size - fifo->in + fifo->out);  /*�����ǻ������Ŀ��г��Ȼ���Ҫд����*/
    /* first put the data starting from fifo->in to buffer end*/

    l = MIN(len, fifo->size - (fifo->in & (fifo->size - 1)));
    memcpy(fifo->buffer + (fifo->in & (fifo->size - 1)), buffer, l);

    /* then put the rest (if any) at the beginning of the buffer*/

    memcpy(fifo->buffer, buffer + l, len - l);         //��ʣ�ಿ�ַŵ���������ͷ����������ݵ�����£�

    fifo->in += len;

    return len;
}

/*
* __kfifo_get - gets some data from the FIFO, no locking version
* @fifo: the fifo to be used.
* @buffer: where the data must be copied.
* @len: the size of the destination buffer.
*
* This function copies at most 'len' bytes from the FIFO into the
* 'buffer' and returns the number of copied bytes.
*
* Note that with only one concurrent reader and one concurrent
* writer, you don't need extra locking to use these functions.
*/
unsigned int my_fifo_get(my_fifo *fifo, unsigned char *buffer, unsigned int len)
{
    unsigned int l = 0;

    len = MIN(len, fifo->in - fifo->out); /*�ɶ�����*/

    /* first get the data from fifo->out until the end of the buffer*/
    l = MIN(len, fifo->size - (fifo->out & (fifo->size - 1)));
    memcpy(buffer, fifo->buffer + (fifo->out & (fifo->size - 1)), l);

    /* then get the rest (if any) from the beginning of the buffer*/
    memcpy(buffer + l, fifo->buffer, len - l);

    fifo->out += len;

    return len;
}

/*
 * __kfifo_reset - removes the entire FIFO contents, no locking version
 * @fifo: the fifo to be emptied.
 */
void my_fifo_reset(my_fifo *fifo)
{
    fifo->in = fifo->out = 0;
}

/*
 * __kfifo_len - returns the number of bytes available in the FIFO, no locking version
 * @fifo: the fifo to be used.
 */
unsigned int my_fifo_len(my_fifo *fifo)
{
    return fifo->in - fifo->out;
}










