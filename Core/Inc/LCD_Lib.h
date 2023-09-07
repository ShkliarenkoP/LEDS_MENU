#ifndef LCD_Lib
#define LCD_Lib

#include "stm32f4xx_hal.h"

#define RS GPIO_PIN_3
#define RW GPIO_PIN_4
#define En GPIO_PIN_5

#define D0_PIN GPIO_PIN_9
#define D1_PIN GPIO_PIN_1
#define D2_PIN GPIO_PIN_8
#define D3_PIN GPIO_PIN_10
#define D4_PIN GPIO_PIN_4
#define D5_PIN GPIO_PIN_5
#define D6_PIN GPIO_PIN_6
#define D7_PIN GPIO_PIN_7

#define MANAGE_PORT GPIOB
#define DATA_PORT   GPIOA

#define NUM_BIT         8


#define SET_DDRAM    0x80
//uint16_t LCD_bus[8] = {D0_PIN, D1_PIN, D2_PIN, D3_PIN, D4_PIN, D5_PIN, D6_PIN, D7_PIN};

void strub();
void sendBite(uint8_t bite);
void sendData(uint8_t data);
void init_8bit_interface();
void sendText(uint8_t *text);


#endif
