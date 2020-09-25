/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * File Name          : freertos.c
  * Description        : Code for freertos applications
  ******************************************************************************
  * @attention
  *
  * <h2><center>&copy; Copyright (c) 2019 STMicroelectronics.
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
osThreadId defaultTaskHandle;
osThreadId TaskMainHandle;
osThreadId TaskLcdHandle;

/* Private function prototypes -----------------------------------------------*/
/* USER CODE BEGIN FunctionPrototypes */

/* USER CODE END FunctionPrototypes */

void StartDefaultTask(void const * argument);
void task_main(void const * argument);
void task_lcd(void const * argument);

void MX_FREERTOS_Init(void); /* (MISRA C 2004 rule 8.1) */

/* GetIdleTaskMemory prototype (linked to static allocation support) */
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize );

/* GetTimerTaskMemory prototype (linked to static allocation support) */
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize );

/* Hook prototypes */
void configureTimerForRunTimeStats(void);
unsigned long getRunTimeCounterValue(void);
void vApplicationIdleHook(void);
void vApplicationTickHook(void);
void vApplicationMallocFailedHook(void);
void vApplicationDaemonTaskStartupHook(void);

/* USER CODE BEGIN 1 */
/* Functions needed when configGENERATE_RUN_TIME_STATS is on */
__weak void configureTimerForRunTimeStats(void)
{

}

__weak unsigned long getRunTimeCounterValue(void)
{
    return 0;
}
/* USER CODE END 1 */

/* USER CODE BEGIN 2 */
__weak void vApplicationIdleHook( void )
{

    /* vApplicationIdleHook() will only be called if configUSE_IDLE_HOOK is set
    to 1 in FreeRTOSConfig.h. It will be called on each iteration of the idle
    task. It is essential that code added to this hook function never attempts
    to block in any way (for example, call xQueueReceive() with a block time
    specified, or call vTaskDelay()). If the application makes use of the
    vTaskDelete() API function (as this demo application does) then it is also
    important that vApplicationIdleHook() is permitted to return to its calling
    function, because it is the responsibility of the idle task to clean up
    memory allocated by the kernel to any task that has since been deleted. */
}
/* USER CODE END 2 */

/* USER CODE BEGIN 3 */
__weak void vApplicationTickHook( void )
{
    /* This function will be called by each tick interrupt if
    configUSE_TICK_HOOK is set to 1 in FreeRTOSConfig.h. User code can be
    added here, but the tick hook is called from an interrupt context, so
    code must not attempt to block, and only the interrupt safe FreeRTOS API
    functions can be used (those that end in FromISR()). */
}
/* USER CODE END 3 */

/* USER CODE BEGIN 5 */
__weak void vApplicationMallocFailedHook(void)
{
    /* vApplicationMallocFailedHook() will only be called if
    configUSE_MALLOC_FAILED_HOOK is set to 1 in FreeRTOSConfig.h. It is a hook
    function that will get called if a call to pvPortMalloc() fails.
    pvPortMalloc() is called internally by the kernel whenever a task, queue,
    timer or semaphore is created. It is also called by various parts of the
    demo application. If heap_1.c or heap_2.c are used, then the size of the
    heap available to pvPortMalloc() is defined by configTOTAL_HEAP_SIZE in
    FreeRTOSConfig.h, and the xPortGetFreeHeapSize() API function can be used
    to query the size of free heap space that remains (although it does not
    provide information on how the remaining heap might be fragmented). */
}
/* USER CODE END 5 */

/* USER CODE BEGIN DAEMON_TASK_STARTUP_HOOK */
void vApplicationDaemonTaskStartupHook(void)
{
}
/* USER CODE END DAEMON_TASK_STARTUP_HOOK */

/* USER CODE BEGIN VPORT_SUPPORT_TICKS_AND_SLEEP */
__weak void vPortSuppressTicksAndSleep( TickType_t xExpectedIdleTime )
{
    // Generated when configUSE_TICKLESS_IDLE == 2.
    // Function called in tasks.c (in portTASK_FUNCTION).
    // TO BE COMPLETED or TO BE REPLACED by a user one, overriding that weak one.
}
/* USER CODE END VPORT_SUPPORT_TICKS_AND_SLEEP */

/* USER CODE BEGIN GET_IDLE_TASK_MEMORY */
static StaticTask_t xIdleTaskTCBBuffer;
static StackType_t xIdleStack[configMINIMAL_STACK_SIZE];
  
void vApplicationGetIdleTaskMemory( StaticTask_t **ppxIdleTaskTCBBuffer, StackType_t **ppxIdleTaskStackBuffer, uint32_t *pulIdleTaskStackSize )
{
  *ppxIdleTaskTCBBuffer = &xIdleTaskTCBBuffer;
  *ppxIdleTaskStackBuffer = &xIdleStack[0];
  *pulIdleTaskStackSize = configMINIMAL_STACK_SIZE;
  /* place for user code */
}                   
/* USER CODE END GET_IDLE_TASK_MEMORY */

/* USER CODE BEGIN GET_TIMER_TASK_MEMORY */
static StaticTask_t xTimerTaskTCBBuffer;
static StackType_t xTimerStack[configTIMER_TASK_STACK_DEPTH];
  
void vApplicationGetTimerTaskMemory( StaticTask_t **ppxTimerTaskTCBBuffer, StackType_t **ppxTimerTaskStackBuffer, uint32_t *pulTimerTaskStackSize )  
{
  *ppxTimerTaskTCBBuffer = &xTimerTaskTCBBuffer;
  *ppxTimerTaskStackBuffer = &xTimerStack[0];
  *pulTimerTaskStackSize = configTIMER_TASK_STACK_DEPTH;
  /* place for user code */
}                   
/* USER CODE END GET_TIMER_TASK_MEMORY */

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
  /* definition and creation of defaultTask */
  osThreadDef(defaultTask, StartDefaultTask, osPriorityNormal, 0, 128);
  defaultTaskHandle = osThreadCreate(osThread(defaultTask), NULL);

  /* definition and creation of TaskMain */
  osThreadDef(TaskMain, task_main, osPriorityNormal, 0, 512);
  TaskMainHandle = osThreadCreate(osThread(TaskMain), NULL);

  /* definition and creation of TaskLcd */
  osThreadDef(TaskLcd, task_lcd, osPriorityLow, 0, 128);
  TaskLcdHandle = osThreadCreate(osThread(TaskLcd), NULL);

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
void StartDefaultTask(void const * argument)
{
  /* USER CODE BEGIN StartDefaultTask */
    /* Infinite loop */
    for(;;)
    {
        osDelay(1000);
    }
  /* USER CODE END StartDefaultTask */
}

/* USER CODE BEGIN Header_task_main */
/**
* @brief Function implementing the TaskMain thread.
* @param argument: Not used
* @retval None
*/
/* USER CODE END Header_task_main */
void task_main(void const * argument)
{
  /* USER CODE BEGIN task_main */
    short Gyro_X;
    short Gyro_Y;
    short Gyro_Z;

    static uint32_t task_main_cnt = 0;
    static uint32_t start_cnt = 0;
    static int pwm_offset = 500;	//电机死区
    /* Infinite loop */
    for(;;)
    {

        task_main_cnt++;
        start_cnt++;
        if(task_main_cnt % 2 == 0)
        {
            moto_get_speed(LEFT);
            moto_get_speed(RIGHT);
        }

        //读取陀螺仪数据
        if(mpu_dmp_get_data(&gMpu.euler.pitch, &gMpu.euler.roll, &gMpu.euler.yaw) == 0)
        {
            gMpu.temp = MPU_Get_Temperature() / 100.0;		//得到温度值
            MPU_Get_Accelerometer(&gMpu.accel.x, &gMpu.accel.y, &gMpu.accel.z);	//得到加速度传感器数据
            MPU_Get_Gyroscope(&Gyro_X, &Gyro_Y, &Gyro_Z);		//得到陀螺仪数据

            gMpu.gyro.x = Gyro_X;
            gMpu.gyro.y = Gyro_Y;
            gMpu.gyro.z = Gyro_Z;


            //获得倾角
            get_angle(2);
            //PWM清零
            gMotor_r.pwm_cnt = 0;
            gMotor_l.pwm_cnt = 0;

            //平衡环
            balance_ctrl(gMpu.balance_angle, gMpu.gyro.x);

            //速度环
            speed_ctrl();

            //确定转动方向
            if(gMotor_r.pwm_cnt > 0)
            {
                gMotor_r.direction = 1;
                gMotor_l.direction = 1;

                gMotor_r.pwm_cnt += pwm_offset;//电机死区
                gMotor_l.pwm_cnt += pwm_offset;

                //设置方向
//			moto_set_pwm_cnt(LEFT, 0);
//			moto_set_pwm_cnt(RIGHT, 0);
                moto_dir_ctrl(gMotor_l.direction, gMotor_r.direction);


            }
            else
            {
                gMotor_r.direction = 0;
                gMotor_l.direction = 0;

                //设置方向
//			moto_set_pwm_cnt(LEFT, 0);
//			moto_set_pwm_cnt(RIGHT, 0);
                moto_dir_ctrl(gMotor_l.direction, gMotor_r.direction);

                //转换为正值
                gMotor_l.pwm_cnt = -gMotor_l.pwm_cnt;
                gMotor_r.pwm_cnt = -gMotor_r.pwm_cnt;


                gMotor_r.pwm_cnt += pwm_offset;
                gMotor_l.pwm_cnt += pwm_offset;
            }

            //消除电机左右摩擦力不同
            gMotor_l.pwm_cnt = 1.2*gMotor_r.pwm_cnt;


            //PWM限幅
            if(gMotor_l.pwm_cnt > 7000)
            {
                gMotor_l.pwm_cnt = 7000;
            }

            if(gMotor_r.pwm_cnt > 7000)
            {
                gMotor_r.pwm_cnt = 7000;
            }

            //倾角过大关闭电机
            if(gMpu.euler.roll > 40)
            {
                gMotor_l.pwm_cnt = 0;
                gMotor_r.pwm_cnt = 0;

                pid_l.ei = 0;
                pid_r.ei = 0;
            }
            if(gMpu.euler.roll < -40)
            {
                gMotor_l.pwm_cnt = 0;
                gMotor_r.pwm_cnt = 0;

                pid_l.ei = 0;
                pid_r.ei = 0;
            }

            //刚开机数据不稳，不刷新PWM数据
            if(start_cnt >= 500)
            {
                start_cnt = 500;
                if(gMotor_l.pwm_old_cnt != gMotor_l.pwm_cnt)
                {
                    gMotor_l.pwm_old_cnt = gMotor_l.pwm_cnt;
                    moto_set_pwm_cnt(LEFT, gMotor_l.pwm_cnt);
                }
                if(gMotor_r.pwm_old_cnt != gMotor_r.pwm_cnt)
                {
                    gMotor_r.pwm_old_cnt = gMotor_r.pwm_cnt;
                    moto_set_pwm_cnt(RIGHT, gMotor_r.pwm_cnt);
                }
            }

        }


        osDelay(3);
    }
  /* USER CODE END task_main */
}

/* USER CODE BEGIN Header_task_lcd */
/**
* @brief Function implementing the TaskLcd thread.
* @param argument: Not used
* @retval None
*/

uint8_t adc_ok_flag = 0;
uint32_t adc_val[30] = {0};
uint32_t adc_cnt = 0;
uint32_t battery_adc = 0;
uint32_t battery_v = 0;
/* USER CODE END Header_task_lcd */
void task_lcd(void const * argument)
{
  /* USER CODE BEGIN task_lcd */
    uint8_t show_buff[40] = {0};
    uint32_t i = 0;
    uint16_t usage = 0.0;
		
    /* Infinite loop */
    for(;;)
    {
		
		if(adc_ok_flag == 1)
		{
			battery_adc = get_average_uint(adc_val, 30);
			battery_v = battery_adc*3300*11/4096;
			sprintf((char*)show_buff, "Battery_V:%2d.%3d", battery_v/1000, battery_v%1000);
			OLED_ShowString(0, 48, show_buff);
			
			adc_ok_flag = 0;
		}
		
		
        sprintf((char*)show_buff, "PITCH:%03.2f", gMpu.balance_angle);
        OLED_ShowString(0, 12, show_buff);
        sprintf((char*)show_buff, "V_L:%-3d", gMotor_l.speed_get);
        OLED_ShowString(0, 24, show_buff);
        sprintf((char*)show_buff, "V_R:%-3d", gMotor_r.speed_get);
        OLED_ShowString(64, 24, show_buff);

        usage = osGetCPUUsage();
        sprintf((char*)show_buff, "CPU:%3d%%", usage);
        OLED_ShowString(0, 36, show_buff);

        OLED_Refresh_Gram();
        i++;
        if(i >= 10)
        {
            i = 0;
            HAL_GPIO_TogglePin(GPIOA, GPIO_PIN_4);
        }

        osDelay(50);
    }
  /* USER CODE END task_lcd */
}

/* Private application code --------------------------------------------------*/
/* USER CODE BEGIN Application */



/* USER CODE END Application */

/************************ (C) COPYRIGHT STMicroelectronics *****END OF FILE****/
