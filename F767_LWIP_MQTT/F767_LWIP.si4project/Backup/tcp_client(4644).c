

#include "tcp_client.h"
#include "printf.h"
#include "kfifo.h"

//TCP Client接收数据缓冲区
uint8_t tcp_client_recvbuf[200];
//TCP服务器发送数据内容

uint8_t tcp_client_sendbuf[] = "Explorer STM32F407 TCP Client send data\r\n";

//TCP Client 测试全局状态标记变量
//bit7:0,没有数据要发送;1,有数据要发送
//bit6:0,没有收到数据;1,收到数据了.
//bit5:0,没有连接上服务器;1,连接上服务器了.
//bit4~0:保留
uint8_t tcp_client_flag;

USER_TCP_TYPE gTcpReg = {0};

err_t tcp_client_recv(void *arg,struct tcp_pcb *tpcb,struct pbuf *p,err_t err)
{
    err_t ret_err;
	struct pbuf *p_temp;
	
	if(p!=NULL)//当处于连接状态并且接收到的数据不为空时
    {
        for(p_temp=p; p_temp!=NULL; p_temp=p_temp->next) //遍历完整个pbuf链表
        {
            //判断要拷贝到TCP_CLIENT_RX_BUFSIZE中的数据是否大于TCP_CLIENT_RX_BUFSIZE的剩余空间，如果大于
            //的话就只拷贝TCP_CLIENT_RX_BUFSIZE中剩余长度的数据，否则的话就拷贝所有的数据
            if(p_temp->len > (TCP_CLIENT_RX_BUFSIZE-data_len)) 
			{
				my_fifo_put
				memcpy(tcp_client_recvbuf+data_len,q->payload,(TCP_CLIENT_RX_BUFSIZE-data_len));//拷贝数据
			}
            else
			{
				memcpy(tcp_client_recvbuf+data_len,q->payload,q->len);
			}
            data_len += q->len;
            if(data_len > TCP_CLIENT_RX_BUFSIZE) break; //超出TCP客户端接收数组,跳出
        }
        tcp_client_flag|=1<<6;		//标记接收到数据了
        tcp_recved(tpcb,p->tot_len);//用于获取接收数据,通知LWIP可以获取更多数据
        pbuf_free(p);  	//释放内存


return ret_err;
}
//lwIP tcp_err函数的回调函数
void tcp_client_error(void *arg,err_t err)
{
    //这里我们不做任何处理
}
//lwIP tcp_poll的回调函数
err_t tcp_client_poll(void *arg, struct tcp_pcb *tpcb)
{
    err_t ret_err;
    return ret_err;
}
//lwIP tcp_sent的回调函数(当从远端主机接收到ACK信号后发送数据)
err_t tcp_client_sent(void *arg, struct tcp_pcb *tpcb, u16_t len)
{
    LWIP_UNUSED_ARG(len);
    //tcp_client_senddata(tpcb,es);//发送数据
    return ERR_OK;
}
//此函数用来发送数据
void tcp_client_senddata(struct tcp_pcb *tpcb, uint8_t * data, uint16_t len)
{
	tcp_write(tpcb,data,len,1);
	tcp_output(tpcb);
}

//关闭与服务器的连接
void tcp_client_connection_close(struct tcp_pcb *tpcb)
{
    tcp_abort(tpcb);//终止连接,删除pcb控制块
    tcp_arg(tpcb,NULL);
    tcp_recv(tpcb,NULL);
    tcp_sent(tpcb,NULL);
    tcp_err(tpcb,NULL);
    tcp_poll(tpcb,NULL,0);
    tcp_client_flag&=~(1<<5);//标记连接断开了
}


err_t tcp_client_connected(void *arg, struct tcp_pcb *tpcb, err_t err)
{
    if(err==ERR_OK)
    {
            tcp_recv(tpcb,tcp_client_recv);  	//初始化LwIP的tcp_recv回调功能
            tcp_err(tpcb,tcp_client_error); 	//初始化tcp_err()回调函数
            tcp_sent(tpcb,tcp_client_sent);		//初始化LwIP的tcp_sent回调功能
            tcp_poll(tpcb,tcp_client_poll,1); 	//初始化LwIP的tcp_poll回调功能
            tcp_client_flag|=1<<5; 				//标记连接到服务器了
            err=ERR_OK;
    }
    else
    {
        tcp_client_connection_close(tpcb);//关闭连接
    }
    return err;
}



uint8_t remoteip[] = {192, 168, 31, 105};

struct tcp_pcb* tcp_pcb = NULL;
ip_addr_t rmtipaddr;

void Tcp_Client(void)
{
    static uint16_t i = 0;
    static uint16_t num = 0;
    static uint8_t connflag=0;
	static uint8_t work_step = 0;

	
	if(work_step == 0)
	{
		tcp_pcb = (struct tcp_pcb*)tcp_new();	//创建一个新的pcb

		if(tcp_pcb)			//创建成功
		{
			IP4_ADDR(&rmtipaddr,remoteip[0],remoteip[1],remoteip[2],remoteip[3]);
			tcp_connect(tcp_pcb,(const ip_addr_t *)&rmtipaddr,TCP_CLIENT_PORT,tcp_client_connected);  //连接到目的地址的指定端口上,当连接成功后回调tcp_client_connected()函数
			work_step = 1;
		}
		else
		{
			work_step = 0;
		}
	}
	else if(work_step == 1)
	{
		i++;
		if(i == 1000)//发送数据
		{
			i = 0;
			num++;

			if(!(tcp_client_flag&1<<5) && (connflag==0))//断开连接
			{
				tcp_client_connection_close(tcp_pcb);//关闭TCP Client连接
				tcp_pcb = (struct tcp_pcb*)tcp_new();	//创建一个新的pcb

				if(tcp_pcb) 		//创建成功
				{
					tcp_connect(tcp_pcb,(const ip_addr_t *)&rmtipaddr,TCP_CLIENT_PORT,tcp_client_connected);  //连接到目的地址的指定端口上,当连接成功后回调tcp_client_connected()函数
				}
			}
			else
			{
				printf("%s  %d\r\n", "Hello World", num);
				tcp_client_flag|=1<<7;//标记要发送数据
			}
		}

		if(tcp_client_flag&1<<6)//收到数据
		{
			printf("%s\r\n", tcp_client_recvbuf);
			tcp_client_flag&=~(1<<6);//标记数据已经被处理了.
		}

		if(tcp_client_flag&1<<5)//已连接
		{
			if(connflag==0)
			{
				printf("\r\n%s\r\n", "Connected");
				connflag=1;//标记连接了
			}
			
			tcp_client_senddata(tcp_pcb, "Hello World\r\n", 13);
		}
		else
		{
			printf("\r\n%s\r\n", "Disconnected");
			if(connflag)
			{
				connflag=0;	//标记连接断开了
			}
		}

		MX_LWIP_Process();
	}

}


