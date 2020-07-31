/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2020 STMicroelectronics.
  * All rights reserved.</center></h2>
  *
  * This software component is licensed by ST under Ultimate Liberty license
  * SLA0044, the "License"; You may not use this file except in compliance with
  * the License. You may obtain a copy of the License at:
  *                             www.st.com/SLA0044
  *
  ******************************************************************************
  */
/* USER CODE END Header */

/* Includes ------------------------------------------------------------------*/
#include "FreeRTOS.h"
#include "task.h"
#include "main.h"
#include "cmsis_os.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "printf.h"
#include "tcp_client.h"
#include "mqttclient.h"
/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

#include "queue.h"
QueueHandle_t MQTT_Data_Queue = NULL;

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
    .name = "defaultTask",
    .priority = (osPriority_t) osPriorityNormal,
    .stack_size = 256 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
//task_led
osThreadId_t task_led_handle;
const osThreadAttr_t task_led_attributes = {
    .name = "task_led",
    .priority = (osPriority_t) osPriorityNormal,
    .stack_size = 256 * 2
};
void task_led_entry(void *argument);

//task_test_c
osThreadId_t task_test_c_handle;
const osThreadAttr_t task_test_c_attributes = {
    .name = "task_test_c",
    .priority = (osPriority_t) osPriorityNormal,
    .stack_size = 256 * 4
};
void task_test_c_entry(void *argument);
/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

extern void MX_LWIP_Init(void);
void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/**
  * @brief  FreeRTOS initialization
  * @param  None
  * @retval None
  */
void MX_FREERTOS_Init(void) {
    /* USER CODE BEGIN Init */

    /* USER CODE END Init */

    /* USER CODE BEGIN RTOS_MUTEX */
    /* add mutexes, ... */
    /* USER CODE END RTOS_MUTEX */

    /* USER CODE BEGIN RTOS_SEMAPHORES */
    /* add semaphores, ... */
    /* USER CODE END RTOS_SEMAPHORES */

    /* USER CODE BEGIN RTOS_TIMERS */
    /* start timers, add new ones, ... */
    /* USER CODE END RTOS_TIMERS */

    /* USER CODE BEGIN RTOS_QUEUES */
    /* add queues, ... */
    /* USER CODE END RTOS_QUEUES */

    /* Create the thread(s) */
    /* creation of defaultTask */
    defaultTaskHandle = osThreadNew(StartDefaultTask, NULL, &defaultTask_attributes);

    /* USER CODE BEGIN RTOS_THREADS */
    /* add threads, ... */

    /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
/* USER CODE END Header_StartDefaultTask */

extern struct netif gnetif;
extern ip4_addr_t ipaddr;
extern ip4_addr_t netmask;
extern ip4_addr_t gw;


uint8_t IP_ADDRESS[4];
uint8_t NETMASK_ADDRESS[4];
uint8_t GATEWAY_ADDRESS[4];

void TCPIP_Init(void)
{
    tcpip_init(NULL, NULL);

    /* IP addresses initialization */
    /* USER CODE BEGIN 0 */
#if LWIP_DHCP
    ip_addr_set_zero_ip4(&ipaddr);
    ip_addr_set_zero_ip4(&netmask);
    ip_addr_set_zero_ip4(&gw);
#else
    IP4_ADDR(&ipaddr, IP_ADDR0, IP_ADDR1, IP_ADDR2, IP_ADDR3);
    IP4_ADDR(&netmask, NETMASK_ADDR0, NETMASK_ADDR1, NETMASK_ADDR2, NETMASK_ADDR3);
    IP4_ADDR(&gw, GW_ADDR0, GW_ADDR1, GW_ADDR2, GW_ADDR3);
#endif /* USE_DHCP */
    /* USER CODE END 0 */
    /* Initilialize the LwIP stack without RTOS */
    /* add the network interface (IPv4/IPv6) without RTOS */
    netif_add(&gnetif, &ipaddr, &netmask, &gw, NULL, &ethernetif_init, &tcpip_input);

    /* Registers the default network interface */
    netif_set_default(&gnetif);

    if (netif_is_link_up(&gnetif))
    {
        /* When the netif is fully configured this function must be called */
        netif_set_up(&gnetif);
    }
    else
    {
        /* When the netif link is down this function must be called */
        netif_set_down(&gnetif);
    }

#if LWIP_DHCP	   			//若使用了DHCP
    int err;
    /*  Creates a new DHCP client for this interface on the first call.
    Note: you must call dhcp_fine_tmr() and dhcp_coarse_tmr() at
    the predefined regular intervals after starting the client.
    You can peek in the netif->dhcp struct for the actual DHCP status.*/

    //printf("本例程将使用DHCP动态分配IP地址,如果不需要则在lwipopts.h中将LWIP_DHCP定义为0\n\n");

    err = dhcp_start(&gnetif);      //开启dhcp
    if(err == ERR_OK)
        printf("lwip dhcp init success...\n\n");
    else
        printf("lwip dhcp init fail...\n\n");
    while(ip_addr_cmp(&(gnetif.ip_addr), &ipaddr))  //等待dhcp分配的ip有效
    {
        vTaskDelay(1);
    }
#endif
    printf("LocalIP:%d.%d.%d.%d\n\n",  \
           ((gnetif.ip_addr.addr) & 0x000000ff),       \
           (((gnetif.ip_addr.addr) & 0x0000ff00) >> 8),  \
           (((gnetif.ip_addr.addr) & 0x00ff0000) >> 16), \
           ((gnetif.ip_addr.addr) & 0xff000000) >> 24);
}


void StartDefaultTask(void *argument)
{
    /* init code for LWIP */
    //MX_LWIP_Init();
    TCPIP_Init();
    /* USER CODE BEGIN StartDefaultTask */

    /* 创建Test_Queue */
    MQTT_Data_Queue = xQueueCreate(10, sizeof(DHT11_Data_TypeDef));    /*消息的大小 */

    mqtt_thread_init();

    task_led_handle = osThreadNew(task_led_entry, NULL, &task_led_attributes);
    task_test_c_handle = osThreadNew(task_test_c_entry, NULL, &task_test_c_attributes);
    /* Infinite loop */
    for(;;)
    {
        //task_tcp_client();
        osDelay(100);
    }
    /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

void task_led_entry(void *argument)
{
    uint8_t led_flag = 1;
    while(1)
    {
        HAL_GPIO_WritePin(LD1_GPIO_Port, LD1_Pin, (GPIO_PinState)(led_flag & (1 << 0)));
        HAL_GPIO_WritePin(LD2_GPIO_Port, LD2_Pin, (GPIO_PinState)(led_flag & (1 << 1)));
        HAL_GPIO_WritePin(LD3_GPIO_Port, LD3_Pin, (GPIO_PinState)(led_flag & (1 << 2)));

        led_flag <<= 1;
        if(led_flag >= 0x10)
        {
            led_flag = 0x01;
        }


        osDelay(200);
    }
}

DHT11_Data_TypeDef test = {0};
void task_test_c_entry(void *argument)
{
    uint32_t task_cnt = 0;
    while(1)
    {
        test.humidity += 0.1;
        test.temperature += 0.1;

        //xQueueReceive( MQTT_Data_Queue, &recv_data, 1000);
        xQueueSend(MQTT_Data_Queue, &test, 0);

        task_cnt++;
        printf("%s %04X\r\n", __func__, task_cnt);
        osDelay(3000);
    }
}
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
