#include "LCD_Lib.h"

uint16_t LCD_bus[8] = {D7_PIN, D6_PIN, D5_PIN, D4_PIN, D3_PIN, D2_PIN, D1_PIN, D0_PIN};

void strub()
{
	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 1); //state of pin MUST BE INVERSE
	HAL_Delay(10);

	HAL_GPIO_WritePin(GPIOB, GPIO_PIN_5, 0); //state of pin MUST BE INVERSE
	HAL_Delay(30);
}

void sendBite(uint8_t bite)
{
	HAL_GPIO_WritePin(MANAGE_PORT, RS, 0); //state of pin MUST BE INVERSE

	for(uint8_t count = 0; count < NUM_BIT; count++)
	{
		HAL_GPIO_WritePin(DATA_PORT, LCD_bus[count], (0b10000000 & (bite << count)));
	}

	strub();
}

void sendData(uint8_t data)
{
	HAL_GPIO_WritePin(MANAGE_PORT, RS, 1); //state of pin MUST BE INVERSE

	for(uint8_t count = 0; count < NUM_BIT; count++)
	{
		HAL_GPIO_WritePin(DATA_PORT, LCD_bus[count], (0b10000000 & (data << count)));
	}

	strub();
}

void sendText(uint8_t *text)
{
//	uint8_t count = 0;

	while(*text != '\0')
	{
		sendData(*text);

		*text++;
	}
}

void setDDRAM(uint8_t DDRAM)
{
	sendBite(SET_DDRAM | DDRAM);
}

void init_8bit_interface()
{/*
	HAL_Delay(50);

	sendBite(0x30);
	HAL_Delay(5);
	sendBite(0x30);
	HAL_Delay(1);
	sendBite(0x30);
	HAL_Delay(1);

	sendBite(0x38);
	HAL_Delay(1);
	sendBite(0x0C);
	HAL_Delay(1);
	sendBite(0x01);
	HAL_Delay(2);
*/
/*############################*/

	HAL_Delay(50);
	sendBite(0x30);
	HAL_Delay(1);
	sendBite(0x30);
	HAL_Delay(1);
	sendBite(0x08);
	HAL_Delay(1);
	sendBite(0x01);
	HAL_Delay(2);
	sendBite(0x04);

	sendBite(0x38);
	HAL_Delay(5);
	sendBite(0x06);
	HAL_Delay(5);
	sendBite(0x10);
	HAL_Delay(5);
	sendBite(0x0F);
	HAL_Delay(5);
	sendBite(0x02);
	HAL_Delay(5);


}
