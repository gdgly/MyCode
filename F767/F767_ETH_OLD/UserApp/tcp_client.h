
#ifndef __TCP_CLIENT_H
#define __TCP_CLIENT_H


#include "global.h"

void Tcp_Client(void);	

#define TCP_CLIENT_RX_BUFSIZE	200		//����tcp client���������ݳ���
#define	TCP_CLIENT_PORT			8080	//����tcp clientҪ���ӵ�Զ�˶˿�

//tcp����������״̬
enum tcp_client_states
{
    ES_TCPCLIENT_NONE = 0,		//û������
    ES_TCPCLIENT_CONNECTED,		//���ӵ���������
    ES_TCPCLIENT_CLOSING,		//�ر�����
};
//LWIP�ص�����ʹ�õĽṹ��
struct tcp_client_struct
{
    uint8_t state;               //��ǰ����״
    struct tcp_pcb *pcb;    //ָ��ǰ��pcb
    struct pbuf *p;         //ָ�����/�����pbuf
};
struct ip_addr
{
    uint32_t addr;
};


void tcp_client_set_remoteip(void);
void tcp_client_test(void);//TCP Client���Ժ���
err_t tcp_client_connected(void *arg, struct tcp_pcb *tpcb, err_t err);
err_t tcp_client_recv(void *arg,struct tcp_pcb *tpcb,struct pbuf *p,err_t err);
void tcp_client_error(void *arg,err_t err);
err_t tcp_client_poll(void *arg, struct tcp_pcb *tpcb);
err_t tcp_client_sent(void *arg, struct tcp_pcb *tpcb, u16_t len);
void tcp_client_senddata(struct tcp_pcb *tpcb, struct tcp_client_struct * es);
void tcp_client_connection_close(struct tcp_pcb *tpcb, struct tcp_client_struct * es );


#endif

