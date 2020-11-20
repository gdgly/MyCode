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
#include "ff.h"
#include "string.h"
#include "stdio.h"
#include "stdlib.h"


#include "SEGGER_RTT.h"
#include "app_ec20_4g.h"


/* USER CODE END Includes */

/* Private typedef -----------------------------------------------------------*/
/* USER CODE BEGIN PTD */

/* USER CODE END PTD */

/* Private define ------------------------------------------------------------*/
/* USER CODE BEGIN PD */

/* USER CODE END PD */

/* Private macro -------------------------------------------------------------*/
/* USER CODE BEGIN PM */

/* USER CODE END PM */

/* Private variables ---------------------------------------------------------*/
/* USER CODE BEGIN Variables */

/* USER CODE END Variables */
/* Definitions for defaultTask */
osThreadId_t defaultTaskHandle;
const osThreadAttr_t defaultTask_attributes = {
  .name = "defaultTask",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 1024 * 4
};

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */
osThreadId_t task1_handle;
const osThreadAttr_t task1_attributes = {
  .name = "task1",
  .priority = (osPriority_t) osPriorityNormal,
  .stack_size = 1024 * 4
};

void task1_entry(void *argument);

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void *argument);

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
  task1_handle = osThreadNew(task1_entry, NULL, &task1_attributes);
  /* USER CODE END RTOS_THREADS */

}

/* USER CODE BEGIN Header_StartDefaultTask */
/**
  * @brief  Function implementing the defaultTask thread.
  * @param  argument: Not used
  * @retval None
  */
FRESULT res = ~FR_OK;
FATFS fatfs;

extern uint8_t retSD;    /* Return value for SD */
extern char SDPath[4];   /* SD logical drive path */
extern FATFS SDFatFS;    /* File system object for SD logical drive */
FIL fp;       /* File object for SD */


uint8_t write_buff[20] = {0};
uint8_t read_buff[20] = {0};

DWORD file_size = 0;
FATFS * temp_fat;

BYTE work[512] = {0};
  
/* USER CODE END Header_StartDefaultTask */
void StartDefaultTask(void *argument)
{
  /* USER CODE BEGIN StartDefaultTask */

  uint32_t byte_num = 0;

  uint32_t task_cnt = 0;


  res = f_mount(&SDFatFS, "0:", 1);
  
  if(res != FR_OK)
  {
      res = f_mkfs("0:", FM_FAT32, 512, work, 512);
      if(res == FR_OK)
      {
        /* 格式化后，先取消挂载 */
        res = f_mount(NULL, "0:", 1);
        /* 重新挂载	*/			
        res = f_mount(&SDFatFS, "0:", 1);
      }
  }
  
  f_getfree("0:", &file_size, &temp_fat);

  res = f_open(&fp, "test.txt", FA_CREATE_NEW);
  res = f_close(&fp);

  /* Infinite loop */
  for(;;)
  {
    task_cnt++;
    sprintf((char*)write_buff, "%05d", task_cnt);

    byte_num = 0;
    res = f_open(&fp, "test.txt", FA_WRITE);
    res = f_write(&fp, write_buff, 5, &byte_num);
    res = f_close(&fp);
    osDelay(100);

    byte_num = 0;
    res = f_open(&fp, "test.txt", FA_READ);
    res = f_read(&fp, read_buff, 5, &byte_num);
    res = f_close(&fp);
    
    memcpy(&read_buff[5], "\r\n", 2);
    SEGGER_RTT_printf(0, read_buff);

    
    osDelay(1000);
  }
  /* USER CODE END StartDefaultTask */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */

void task1_entry(void *argument)
{
    Ec20_SoftInit();
    while(1)
    {
        Task_4G();
        osDelay(100);
    }
}
/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
