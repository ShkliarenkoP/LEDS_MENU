/* USER CODE BEGIN Header */
/**
  ******************************************************************************
  * @file           : main.c
  * @brief          : Main program body
  ******************************************************************************
  * @attention
  *
  * Copyright (c) 2023 STMicroelectronics.
  * All rights reserved.
  *
  * This software is licensed under terms that can be found in the LICENSE file
  * in the root directory of this software component.
  * If no LICENSE file comes with this software, it is provided AS-IS.
  *
  ******************************************************************************
  */
/* USER CODE END Header */
/* Includes ------------------------------------------------------------------*/
#include "main.h"

/* Private includes ----------------------------------------------------------*/
/* USER CODE BEGIN Includes */
#include "LCD_Lib.h"
#include "menu_Lib.h"
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

/* USER CODE BEGIN PV */
extern uint8_t button = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
/* USER CODE BEGIN PFP */

/* USER CODE END PFP */

/* Private user code ---------------------------------------------------------*/
/* USER CODE BEGIN 0 */

/* USER CODE END 0 */

/**
  * @brief  The application entry point.
  * @retval int
  */
int main(void)
{
  /* USER CODE BEGIN 1 */

  /* USER CODE END 1 */

  /* MCU Configuration--------------------------------------------------------*/

  /* Reset of all peripherals, Initializes the Flash interface and the Systick. */
  HAL_Init();

  /* USER CODE BEGIN Init */

  /* USER CODE END Init */

  /* Configure the system clock */
  SystemClock_Config();

  /* USER CODE BEGIN SysInit */

  /* USER CODE END SysInit */

  /* Initialize all configured peripherals */
  MX_GPIO_Init();
  /* USER CODE BEGIN 2 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  HAL_GPIO_WritePin(MANAGE_PORT, RW, 1);
//  HAL_GPIO_WritePin(MANAGE_PORT, RS, 1);

//  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);//because pin is invert
  init_8bit_interface();
  displayControl(CURSOR_BLINK_OFF & CURSOR_OFF);
  HAL_Delay(10);


 // struct MenuItem *change_item;

  struct MenuItem MainMenu, led[4], subLed0[2],
                                    subLed1[2],
									subLed2[2],
									subLed3[3];

  	  MainMenu.name[10] = " ";
  	  MainMenu.text[10] = " ";
  	  MainMenu.ddram_name = NULL;
  	  MainMenu.ddram_text = NULL;
  	  MainMenu.subItem = led;
  	  MainMenu.parentalItem = NULL;
  	  MainMenu.navigation_list = NULL;
  	  MainMenu.writeFunction = writeMainMenu;

  		  strcpy(led[0].name, " Ld1: ");
  		  led[0].text[10] = " ";
  		  led[0].ddram_name = 0x00;
  		  led[0].ddram_text = NULL;
  		  led[0].state_item = CHOOSED_LED;
  		  led[0].subItem = &subLed0[0];
  		  led[0].parentalItem = NULL;
  		  led[0].navigation_list = &led[1];
  		  led[0].writeFunction = writeSubLedMenu;

  			  strcpy(subLed0[0].name, " SET");
  			  strcpy(subLed0[0].text, led[0].name);
  			  subLed0[0].ddram_name = 0x40;
  			  subLed0[0].ddram_text = 0x00;
  			  subLed0[0].state_item = SET_V;
  			  subLed0[0].subItem = NULL;
  			  subLed0[0].parentalItem = &MainMenu;
  			  subLed0[0].navigation_list = &subLed0[1];


  			  strcpy(subLed0[1].name, " BACK");
  			  strcpy(subLed0[1].text, led[0].name);
  			  subLed0[1].ddram_name = 0x48;
  			  subLed0[1].ddram_text = 0x00;
  			  subLed0[1].state_item = BACK;
  			  subLed0[1].subItem = NULL;
  			  subLed0[1].parentalItem = &MainMenu;
  			  subLed0[1].navigation_list = &subLed0[0];




  		  strcpy(led[1].name, " Ld2: ");
  		  led[1].text[10] = " ";
  		  led[1].ddram_name = 0x08;
  		  led[1].ddram_text = NULL;
  		  led[1].state_item = CHOOSED_LED;
  		  led[1].subItem = &subLed1[0];
  		  led[1].parentalItem = &MainMenu;
  		  led[1].navigation_list = &led[2];
  		  led[1].writeFunction = writeSubLedMenu;

  			  strcpy(subLed1[0].name, " SET");
  			  strcpy(subLed1[0].text, led[1].name);
  			  subLed1[0].ddram_name = 0x40;
  			  subLed1[0].ddram_text = 0x00;
  			  subLed1[0].state_item = SET_V;
  			  subLed1[0].subItem = NULL;
  			  subLed1[0].parentalItem = &MainMenu;
  			  subLed1[0].navigation_list = &subLed1[1];


  			  strcpy(subLed1[1].name, " BACK");
  			  strcpy(subLed1[1].text, led[1].name);
  			  subLed1[1].ddram_name = 0x48;
  			  subLed1[1].ddram_text = 0x00;
  			  subLed1[1].state_item = BACK;
  			  subLed1[1].subItem = NULL;
  			  subLed1[1].parentalItem = &MainMenu;
  			  subLed1[1].navigation_list = &subLed1[0];




  		  strcpy(led[2].name, " Ld3: ");
  		  led[2].text[10] = " ";
  		  led[2].ddram_name = 0x40;
  		  led[2].ddram_text = NULL;
  		  led[2].state_item = CHOOSED_LED;
  		  led[2].subItem = &subLed2[0];
  		  led[2].parentalItem = &MainMenu;
  		  led[2].navigation_list = &led[3];
  		  led[2].writeFunction = writeSubLedMenu;

  			  strcpy(subLed2[0].name, " SET");
  			  strcpy(subLed2[0].text, led[2].name);
  			  subLed2[0].ddram_name = 0x40;
  			  subLed2[0].ddram_text = 0x00;
  		      subLed2[0].state_item = SET_V;
  			  subLed2[0].subItem = NULL;
  			  subLed2[0].parentalItem = &MainMenu;
  			  subLed2[0].navigation_list = &subLed3[1];


  			  strcpy(subLed2[1].name, " BACK");
  			  strcpy(subLed2[1].text, led[2].name);
  			  subLed2[1].ddram_name = 0x48;
  			  subLed2[1].ddram_text = 0x00;
  			  subLed2[1].state_item = BACK;
  			  subLed2[1].subItem = NULL;
  			  subLed2[1].parentalItem = &MainMenu;
  			  subLed2[1].navigation_list = &subLed3[0];




  		  strcpy(led[3].name, " Ld4: ");
  		  led[3].text[10] = " ";
  		  led[3].ddram_name = 0x48;
  		  led[3].ddram_text = NULL;
  		  led[3].state_item = CHOOSED_LED;
  		  led[3].subItem = &subLed3[0];
  		  led[3].parentalItem = &MainMenu;
  		  led[3].navigation_list = &led[0];
  		  led[3].writeFunction = writeSubLedMenu;

  			  strcpy(subLed3[0].name, " SET");
  			  strcpy(subLed3[0].text, led[3].name);
  			  subLed3[0].ddram_name = 0x40;
  			  subLed3[0].ddram_text = 0x00;
  			  subLed3[0].state_item = SET_V;
  			  subLed3[0].subItem = NULL;
  			  subLed3[0].parentalItem = &MainMenu;
  			  subLed3[0].navigation_list = &subLed3[1];


  			  strcpy(subLed3[1].name, " BACK");
  			  strcpy(subLed3[1].text, led[3].name);
  			  subLed3[1].ddram_name = 0x48;
  			  subLed3[1].ddram_text = 0x00;
  			  subLed3[1].state_item = BACK;
  			  subLed3[1].subItem = NULL;
  			  subLed3[1].parentalItem = &MainMenu;
  			  subLed3[1].navigation_list = &subLed3[0];






  MainMenu.writeFunction(led);

  struct MenuItem *horizontal_lvl_curr = &led[0],
		  	  	  *horizontal_lvl_prev = NULL;

  setCursor(horizontal_lvl_curr);

  while (1)
  {
	 switch(button)
	 {
	 case CHANGE:
		 button = 0;

		 horizontal_lvl_prev = horizontal_lvl_curr;

		 switchCursor(horizontal_lvl_prev, horizontal_lvl_prev->navigation_list);

		 horizontal_lvl_curr = horizontal_lvl_prev->navigation_list;

		 break;

	 case SELECT:
		 button = 0;

		 switch(horizontal_lvl_curr->state_item)
		 {
		 case CHOOSED_LED:
			 horizontal_lvl_curr = horizontal_lvl_curr->writeFunction(horizontal_lvl_curr->subItem);

			 break;

		 case SET_V:
			 break;

		 case BACK:
			 horizontal_lvl_curr = backFunc(horizontal_lvl_curr->parentalItem);

	//		 setCursor(horizontal_lvl_curr);
			 break;
		 }

//		 horizontal_lvl_curr = horizontal_lvl_curr->writeFunction(horizontal_lvl_curr->subItem);

/*		 horizontal_lvl_curr = horizontal_lvl_curr->subItem;
		 writeSubLedMenu(horizontal_lvl_curr);
*/
		 break;
	 }

    /* USER CODE END WHILE */

    /* USER CODE BEGIN 3 */
  }
  /* USER CODE END 3 */
}

/**
  * @brief System Clock Configuration
  * @retval None
  */
void SystemClock_Config(void)
{
  RCC_OscInitTypeDef RCC_OscInitStruct = {0};
  RCC_ClkInitTypeDef RCC_ClkInitStruct = {0};

  /** Configure the main internal regulator output voltage
  */
  __HAL_RCC_PWR_CLK_ENABLE();
  __HAL_PWR_VOLTAGESCALING_CONFIG(PWR_REGULATOR_VOLTAGE_SCALE2);

  /** Initializes the RCC Oscillators according to the specified parameters
  * in the RCC_OscInitTypeDef structure.
  */
  RCC_OscInitStruct.OscillatorType = RCC_OSCILLATORTYPE_HSI;
  RCC_OscInitStruct.HSIState = RCC_HSI_ON;
  RCC_OscInitStruct.HSICalibrationValue = RCC_HSICALIBRATION_DEFAULT;
  RCC_OscInitStruct.PLL.PLLState = RCC_PLL_ON;
  RCC_OscInitStruct.PLL.PLLSource = RCC_PLLSOURCE_HSI;
  RCC_OscInitStruct.PLL.PLLM = 16;
  RCC_OscInitStruct.PLL.PLLN = 336;
  RCC_OscInitStruct.PLL.PLLP = RCC_PLLP_DIV4;
  RCC_OscInitStruct.PLL.PLLQ = 7;
  if (HAL_RCC_OscConfig(&RCC_OscInitStruct) != HAL_OK)
  {
    Error_Handler();
  }

  /** Initializes the CPU, AHB and APB buses clocks
  */
  RCC_ClkInitStruct.ClockType = RCC_CLOCKTYPE_HCLK|RCC_CLOCKTYPE_SYSCLK
                              |RCC_CLOCKTYPE_PCLK1|RCC_CLOCKTYPE_PCLK2;
  RCC_ClkInitStruct.SYSCLKSource = RCC_SYSCLKSOURCE_PLLCLK;
  RCC_ClkInitStruct.AHBCLKDivider = RCC_SYSCLK_DIV1;
  RCC_ClkInitStruct.APB1CLKDivider = RCC_HCLK_DIV2;
  RCC_ClkInitStruct.APB2CLKDivider = RCC_HCLK_DIV1;

  if (HAL_RCC_ClockConfig(&RCC_ClkInitStruct, FLASH_LATENCY_2) != HAL_OK)
  {
    Error_Handler();
  }
}

/**
  * @brief GPIO Initialization Function
  * @param None
  * @retval None
  */
static void MX_GPIO_Init(void)
{
  GPIO_InitTypeDef GPIO_InitStruct = {0};

  /* GPIO Ports Clock Enable */
  __HAL_RCC_GPIOC_CLK_ENABLE();
  __HAL_RCC_GPIOH_CLK_ENABLE();
  __HAL_RCC_GPIOA_CLK_ENABLE();
  __HAL_RCC_GPIOB_CLK_ENABLE();

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOA, GPIO_PIN_1|GPIO_PIN_4|LD2_Pin|GPIO_PIN_6
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOC, GPIO_PIN_7, GPIO_PIN_RESET);

  /*Configure GPIO pin Output Level */
  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5, GPIO_PIN_RESET);

  /*Configure GPIO pin : B1_Pin */
  GPIO_InitStruct.Pin = B1_Pin;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_FALLING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(B1_GPIO_Port, &GPIO_InitStruct);

  /*Configure GPIO pins : PC0 PC1 */
  GPIO_InitStruct.Pin = GPIO_PIN_0|GPIO_PIN_1;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PA1 PA4 LD2_Pin PA6
                           PA7 PA8 PA9 PA10 */
  GPIO_InitStruct.Pin = GPIO_PIN_1|GPIO_PIN_4|LD2_Pin|GPIO_PIN_6
                          |GPIO_PIN_7|GPIO_PIN_8|GPIO_PIN_9|GPIO_PIN_10;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOA, &GPIO_InitStruct);

  /*Configure GPIO pin : PC7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOC, &GPIO_InitStruct);

  /*Configure GPIO pins : PB3 PB4 PB5 */
  GPIO_InitStruct.Pin = GPIO_PIN_3|GPIO_PIN_4|GPIO_PIN_5;
  GPIO_InitStruct.Mode = GPIO_MODE_OUTPUT_PP;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  GPIO_InitStruct.Speed = GPIO_SPEED_FREQ_LOW;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /*Configure GPIO pin : PB7 */
  GPIO_InitStruct.Pin = GPIO_PIN_7;
  GPIO_InitStruct.Mode = GPIO_MODE_IT_RISING;
  GPIO_InitStruct.Pull = GPIO_NOPULL;
  HAL_GPIO_Init(GPIOB, &GPIO_InitStruct);

  /* EXTI interrupt init*/
  HAL_NVIC_SetPriority(EXTI0_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI0_IRQn);

  HAL_NVIC_SetPriority(EXTI1_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI1_IRQn);

  HAL_NVIC_SetPriority(EXTI9_5_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI9_5_IRQn);

  HAL_NVIC_SetPriority(EXTI15_10_IRQn, 0, 0);
  HAL_NVIC_EnableIRQ(EXTI15_10_IRQn);

}

/* USER CODE BEGIN 4 */

/* USER CODE END 4 */

/**
  * @brief  This function is executed in case of error occurrence.
  * @retval None
  */
void Error_Handler(void)
{
  /* USER CODE BEGIN Error_Handler_Debug */
  /* User can add his own implementation to report the HAL error return state */
  __disable_irq();
  while (1)
  {
  }
  /* USER CODE END Error_Handler_Debug */
}

#ifdef  USE_FULL_ASSERT
/**
  * @brief  Reports the name of the source file and the source line number
  *         where the assert_param error has occurred.
  * @param  file: pointer to the source file name
  * @param  line: assert_param error line source number
  * @retval None
  */
void assert_failed(uint8_t *file, uint32_t line)
{
  /* USER CODE BEGIN 6 */
  /* User can add his own implementation to report the file name and line number,
     ex: printf("Wrong parameters value: file %s on line %d\r\n", file, line) */
  /* USER CODE END 6 */
}
#endif /* USE_FULL_ASSERT */
