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
#include "string.h"
#include "stdio.h"
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
TIM_HandleTypeDef htim2;
TIM_HandleTypeDef htim3;

/* USER CODE BEGIN PV */
extern uint8_t button = 0;
/* USER CODE END PV */

/* Private function prototypes -----------------------------------------------*/
void SystemClock_Config(void);
static void MX_GPIO_Init(void);
static void MX_TIM2_Init(void);
static void MX_TIM3_Init(void);
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
  MX_TIM2_Init();
  MX_TIM3_Init();
  /* USER CODE BEGIN 2 */
  /* USER CODE END 2 */

  /* Infinite loop */
  /* USER CODE BEGIN WHILE */
//  HAL_GPIO_WritePin(MANAGE_PORT, RW, 1);
//  HAL_GPIO_WritePin(MANAGE_PORT, RS, 1);

//  HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1);//because pin is invert
  HAL_TIM_PWM_Start(&htim2, TIM_CHANNEL_1);

  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_3);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_4);
  HAL_TIM_PWM_Start(&htim3, TIM_CHANNEL_1);

  init_8bit_interface();
  displayControl(CURSOR_BLINK_OFF & CURSOR_OFF);
  HAL_Delay(10);


 // struct MenuItem *change_item;

  struct MenuItem MainMenu, led[4], subLed0[4],
                                    subLed1[4],
									subLed2[4],
									subLed3[4];


  	  MainMenu.name[10] = 0;
  	  MainMenu.text[10] = 0;
  	  MainMenu.ddram_name = 0;
  	  MainMenu.ddram_text = 0;
  	  MainMenu.subItem = led;
  	  MainMenu.parentalItem = NULL;
  	  MainMenu.navigation_list = NULL;
  	  MainMenu.itemFunction = writeMainMenu;


  	  	  led[0].PWM_lvl = 0;
  		  sprintf(led[0].name, " Ld1:");
  		  sprintf(led[0].text, " Ld1:%d", led[0].PWM_lvl);
  		  led[0].ddram_name = 0x00;
  		  led[0].ddram_text = 0;
  		  led[0].state_item = CHOOSED_LED;
  		  led[0].subItem = &subLed0[0];
  		  led[0].parentalItem = NULL;
  		  led[0].navigation_list = &led[1];
  		  led[0].itemFunction = writeSubLedMenu;
  		  led[0].PWM_Reg = &(TIM2->CCR1);

  		  	  strcpy(subLed0[0].name, (const char*)" -");
  		      sprintf(subLed0[0].text, "%s", led[0].name);
			  subLed0[0].ddram_name = 0x44;
			  subLed0[0].ddram_text = 0x00;
			  subLed0[0].state_item = MINUS;
			  subLed0[0].PWM_lvl = 0;
			  subLed0[0].subItem = &led[0];
			  subLed0[0].parentalItem = &MainMenu;
			  subLed0[0].navigation_list = &subLed0[1];
			  subLed0[0].itemFunction = reWrite;

			  strcpy(subLed0[1].name, (const char*)" +");
			  sprintf(subLed0[1].text, "%s", led[0].name);
			  subLed0[1].ddram_name = 0x48;
			  subLed0[1].ddram_text = 0x00;
			  subLed0[1].state_item = PLUS;
			  subLed0[1].PWM_lvl = 0;
			  subLed0[1].subItem = &led[0];
			  subLed0[1].parentalItem = &MainMenu;
			  subLed0[1].navigation_list = &subLed0[2];
			  subLed0[1].itemFunction = reWrite;

  			  strcpy(subLed0[2].name, (const char*)" SET");
  			  strcpy(subLed0[2].text, led[0].name);
  			  subLed0[2].ddram_name = 0x0B;
  			  subLed0[2].ddram_text = 0x00;
  			  subLed0[2].state_item = SET_V;
  			  subLed0[2].PWM_lvl = 0;
  			  subLed0[2].subItem = &led[0];
  			  subLed0[2].parentalItem = &MainMenu;
  			  subLed0[2].navigation_list = &subLed0[3];

  			  strcpy(subLed0[3].name, (const char*)" BACK");
  			  strcpy(subLed0[3].text, led[0].name);
  			  subLed0[3].ddram_name = 0x4B;
  			  subLed0[3].ddram_text = 0x00;
  			  subLed0[3].state_item = BACK;
  			  subLed0[3].PWM_lvl = 0;
  			  subLed0[3].subItem = &led[0];
  			  subLed0[3].parentalItem = &MainMenu;
  			  subLed0[3].navigation_list = &subLed0[0];
  			  subLed0[3].itemFunction = backFunc;


  		  led[1].PWM_lvl = 0;
  		  sprintf(led[1].name, " Ld2:");
  		  sprintf(led[1].text, " Ld2:%d", led[1].PWM_lvl);
  		  led[1].ddram_name = 0x08;
  		  led[1].ddram_text = 0;
  		  led[1].state_item = CHOOSED_LED;
  		  led[1].subItem = &subLed1[0];
  		  led[1].parentalItem = &MainMenu;
  		  led[1].navigation_list = &led[2];
  		  led[1].itemFunction = writeSubLedMenu;
  		  led[1].PWM_Reg = &(TIM3->CCR3);

  		  	  strcpy(subLed1[0].name, (const char*)" -");
  		  	  sprintf(subLed1[0].text, "%s", led[1].name);
			  subLed1[0].ddram_name = 0x44;
			  subLed1[0].ddram_text = 0x00;
			  subLed1[0].state_item = MINUS;
			  subLed1[0].PWM_lvl = 0;
			  subLed1[0].subItem = &led[1];
			  subLed1[0].parentalItem = &MainMenu;
			  subLed1[0].navigation_list = &subLed1[1];
			  subLed1[0].itemFunction = reWrite;

			  strcpy(subLed1[1].name, (const char*)" +");
			  sprintf(subLed1[1].text, "%s", led[1].name);
			  subLed1[1].ddram_name = 0x48;
			  subLed1[1].ddram_text = 0x00;
			  subLed1[1].state_item = PLUS;
			  subLed1[1].PWM_lvl = 0;
			  subLed1[1].subItem = &led[1];
			  subLed1[1].parentalItem = &MainMenu;
			  subLed1[1].navigation_list = &subLed1[2];
			  subLed1[1].itemFunction = reWrite;

			  strcpy(subLed1[2].name, (const char*)" SET");
			  strcpy(subLed1[2].text, led[1].name);
			  subLed1[2].ddram_name = 0x0B;
			  subLed1[2].ddram_text = 0x00;
			  subLed1[2].state_item = SET_V;
			  subLed1[2].PWM_lvl = 0;
			  subLed1[2].subItem = &led[1];
			  subLed1[2].parentalItem = &MainMenu;
			  subLed1[2].navigation_list = &subLed1[3];

			  strcpy(subLed1[3].name, (const char*)" BACK");
			  strcpy(subLed1[3].text, led[1].name);
			  subLed1[3].ddram_name = 0x4B;
			  subLed1[3].ddram_text = 0x00;
			  subLed1[3].state_item = BACK;
			  subLed1[3].PWM_lvl = 0;
			  subLed1[3].subItem = &led[1];
			  subLed1[3].parentalItem = &MainMenu;
			  subLed1[3].navigation_list = &subLed1[0];
			  subLed1[3].itemFunction = backFunc;


		  led[2].PWM_lvl = 0;
    	  sprintf(led[2].name, " Ld3:");
		  sprintf(led[2].text, " Ld3:%d", led[2].PWM_lvl);
  		  led[2].ddram_name = 0x40;
  		  led[2].ddram_text = 0;
  		  led[2].state_item = CHOOSED_LED;
  		  led[2].subItem = &subLed2[0];
  		  led[2].parentalItem = &MainMenu;
  		  led[2].navigation_list = &led[3];
  		  led[2].itemFunction = writeSubLedMenu;
  		  led[2].PWM_Reg = &(TIM3->CCR4);

  		  	  strcpy(subLed2[0].name, (const char*)" -");
  		  	  sprintf(subLed2[0].text, "%s", led[2].name);
			  subLed2[0].ddram_name = 0x44;
			  subLed2[0].ddram_text = 0x00;
			  subLed2[0].state_item = MINUS;
			  subLed2[0].PWM_lvl = 0;
			  subLed2[0].subItem = &led[2];
			  subLed2[0].parentalItem = &MainMenu;
			  subLed2[0].navigation_list = &subLed2[1];
			  subLed2[0].itemFunction = reWrite;

			  strcpy(subLed2[1].name, (const char*)" +");
			  sprintf(subLed2[1].text, "%s", led[2].name);
			  subLed2[1].ddram_name = 0x48;
			  subLed2[1].ddram_text = 0x00;
			  subLed2[1].state_item = PLUS;
			  subLed2[1].PWM_lvl = 0;
			  subLed2[1].subItem = &led[2];
			  subLed2[1].parentalItem = &MainMenu;
			  subLed2[1].navigation_list = &subLed2[2];
			  subLed2[1].itemFunction = reWrite;

			  strcpy(subLed2[2].name, (const char*)" SET");
			  strcpy(subLed2[2].text, led[2].name);
			  subLed2[2].ddram_name = 0x0B;
			  subLed2[2].ddram_text = 0x00;
			  subLed2[2].state_item = SET_V;
			  subLed2[2].PWM_lvl = 0;
			  subLed2[2].subItem = &led[2];
			  subLed2[2].parentalItem = &MainMenu;
			  subLed2[2].navigation_list = &subLed2[3];

			  strcpy(subLed2[3].name, (const char*)" BACK");
			  strcpy(subLed2[3].text, led[2].name);
			  subLed2[3].ddram_name = 0x4B;
			  subLed2[3].ddram_text = 0x00;
			  subLed2[3].state_item = BACK;
			  subLed2[3].PWM_lvl = 0;
			  subLed2[3].subItem = &led[2];
			  subLed2[3].parentalItem = &MainMenu;
			  subLed2[3].navigation_list = &subLed2[0];
			  subLed2[3].itemFunction = backFunc;


		  led[3].PWM_lvl = 0;
		  sprintf(led[3].name, " Ld4:");
		  sprintf(led[3].text, " Ld4:%d", led[3].PWM_lvl);
  		  led[3].ddram_name = 0x48;
  		  led[3].ddram_text = 0;
  		  led[3].state_item = CHOOSED_LED;
  		  led[3].subItem = &subLed3[0];
  		  led[3].parentalItem = &MainMenu;
  		  led[3].navigation_list = &led[0];
  		  led[3].itemFunction = writeSubLedMenu;
  		  led[3].PWM_Reg = &(TIM3->CCR1);

  		  	  strcpy(subLed3[0].name, (const char*)" -");
			  sprintf(subLed3[0].text, "%s", led[3].name);
			  subLed3[0].ddram_name = 0x44;
			  subLed3[0].ddram_text = 0x00;
			  subLed3[0].state_item = MINUS;
			  subLed3[0].PWM_lvl = 0;
			  subLed3[0].subItem = &led[3];
			  subLed3[0].parentalItem = &MainMenu;
			  subLed3[0].navigation_list = &subLed3[1];
			  subLed3[0].itemFunction = reWrite;

			  strcpy(subLed3[1].name, (const char*)" +");
			  sprintf(subLed3[1].text, "%s", led[3].name);
			  subLed3[1].ddram_name = 0x48;
			  subLed3[1].ddram_text = 0x00;
			  subLed3[1].state_item = PLUS;
			  subLed3[1].PWM_lvl = 0;
			  subLed3[1].subItem = &led[3];
			  subLed3[1].parentalItem = &MainMenu;
			  subLed3[1].navigation_list = &subLed3[2];
			  subLed3[1].itemFunction = reWrite;

			  strcpy(subLed3[2].name, (const char*)" SET");
			  strcpy(subLed3[2].text, led[3].name);
			  subLed3[2].ddram_name = 0x0B;
			  subLed3[2].ddram_text = 0x00;
			  subLed3[2].state_item = SET_V;
			  subLed3[2].PWM_lvl = 0;
			  subLed3[2].subItem = &led[3];
			  subLed3[2].parentalItem = &MainMenu;
			  subLed3[2].navigation_list = &subLed3[3];

			  strcpy(subLed3[3].name, (const char*)" BACK");
			  strcpy(subLed3[3].text, led[3].name);
			  subLed3[3].ddram_name = 0x4B;
			  subLed3[3].ddram_text = 0x00;
			  subLed3[3].state_item = BACK;
			  subLed3[3].PWM_lvl = 0;
			  subLed3[3].subItem = &led[3];
			  subLed3[3].parentalItem = &MainMenu;
			  subLed3[3].navigation_list = &subLed3[0];
			  subLed3[3].itemFunction = backFunc;






  MainMenu.itemFunction(led, NULL);

  const struct MenuItem *current_item = &led[0],
		  	  	        *previous_item = NULL;

  uint8_t PWM = 70;

  setCursor(current_item);
/*
  *(led[0].PWM_Reg) = 100;
  TIM3->CCR1 = 3999;
  TIM3->CCR3 = 0;
  TIM3->CCR4 = 100;
*/
  while (1)
  {
	 switch(button)
	 {
	 case CHANGE:
		 button = 0;

		 previous_item = current_item;

		 switchCursor(previous_item, previous_item->navigation_list);

		 current_item = previous_item->navigation_list;

		 break;

	 case SELECT:
		 button = 0;

		 switch(current_item->state_item)
		 {
		 case CHOOSED_LED:

			 PWM = current_item->PWM_lvl;

			 current_item = current_item->itemFunction(current_item->subItem, NULL);
	//		 PWM = current_item->PWM_lvl;

			 break;

		 case SET_V:

			 current_item->subItem->PWM_lvl = PWM;

			 *(current_item->subItem->PWM_Reg) = ((4000 * current_item->subItem->PWM_lvl) / 100);
//			 current_item->subItem->PWM_Reg = ((4000 * current_item->subItem->PWM_lvl) / 100);

			 sprintf(current_item->subItem->text, "%s%d", current_item->subItem->name, current_item->subItem->PWM_lvl);

//			 current_item = current_item->itemFunction(current_item->parentalItem, NULL);
			 current_item = backFunc(current_item->parentalItem);


			 break;

		 case BACK:

			 current_item = current_item->itemFunction(current_item->parentalItem, NULL);
//			 current_item = backFunc(current_item->parentalItem);

			 break;

		 case MINUS:

			 if(PWM == 100)
			 {
				 clearChar(0x07);
			 }

			 PWM -= 5;

			 if(PWM > 100)
			 {
				 PWM = 0;
			 }

			 reWrite(current_item, &PWM);

			 if(PWM < 10)
			 {
				 clearChar(0x06);
			 }

			 break;

		 case PLUS:

			 if(PWM == 0)
			 {
				 clearChar(0x06);
			 }

			 PWM += 5;

			 if(PWM > 100)
			 {
				 PWM = 100;
			 }

			 reWrite(current_item, &PWM);

			 break;

		 }


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
  * @brief TIM2 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM2_Init(void)
{

  /* USER CODE BEGIN TIM2_Init 0 */

  /* USER CODE END TIM2_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM2_Init 1 */

  /* USER CODE END TIM2_Init 1 */
  htim2.Instance = TIM2;
  htim2.Init.Prescaler = 20;
  htim2.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim2.Init.Period = 4000;
  htim2.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim2.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_ENABLE;
  if (HAL_TIM_PWM_Init(&htim2) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim2, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim2, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM2_Init 2 */

  /* USER CODE END TIM2_Init 2 */
  HAL_TIM_MspPostInit(&htim2);

}

/**
  * @brief TIM3 Initialization Function
  * @param None
  * @retval None
  */
static void MX_TIM3_Init(void)
{

  /* USER CODE BEGIN TIM3_Init 0 */

  /* USER CODE END TIM3_Init 0 */

  TIM_MasterConfigTypeDef sMasterConfig = {0};
  TIM_OC_InitTypeDef sConfigOC = {0};

  /* USER CODE BEGIN TIM3_Init 1 */

  /* USER CODE END TIM3_Init 1 */
  htim3.Instance = TIM3;
  htim3.Init.Prescaler = 20;
  htim3.Init.CounterMode = TIM_COUNTERMODE_UP;
  htim3.Init.Period = 4000;
  htim3.Init.ClockDivision = TIM_CLOCKDIVISION_DIV1;
  htim3.Init.AutoReloadPreload = TIM_AUTORELOAD_PRELOAD_DISABLE;
  if (HAL_TIM_PWM_Init(&htim3) != HAL_OK)
  {
    Error_Handler();
  }
  sMasterConfig.MasterOutputTrigger = TIM_TRGO_RESET;
  sMasterConfig.MasterSlaveMode = TIM_MASTERSLAVEMODE_DISABLE;
  if (HAL_TIMEx_MasterConfigSynchronization(&htim3, &sMasterConfig) != HAL_OK)
  {
    Error_Handler();
  }
  sConfigOC.OCMode = TIM_OCMODE_PWM1;
  sConfigOC.Pulse = 0;
  sConfigOC.OCPolarity = TIM_OCPOLARITY_HIGH;
  sConfigOC.OCFastMode = TIM_OCFAST_DISABLE;
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_1) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_3) != HAL_OK)
  {
    Error_Handler();
  }
  if (HAL_TIM_PWM_ConfigChannel(&htim3, &sConfigOC, TIM_CHANNEL_4) != HAL_OK)
  {
    Error_Handler();
  }
  /* USER CODE BEGIN TIM3_Init 2 */

  /* USER CODE END TIM3_Init 2 */
  HAL_TIM_MspPostInit(&htim3);

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
