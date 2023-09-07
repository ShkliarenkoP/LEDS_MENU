#include "LCD_Lib.h"
#include "menu_Lib.h"


void writeText(uint8_t *name_item, uint8_t ddram_item)
{
	setDDRAM(ddram_item);

	sendText(name_item);
}

void writeMainMenu(struct MenuItem *items)
{
	for(uint8_t count = 0; count < 4; count++)
	{
		writeText(items[count].name, items[count].ddram_name);
	}

}

void writeSubLedMenu(struct MenuItem *items)
{
	for(uint8_t count = 0; count < 2; count++)
	{
			writeText(items[count].name, items[count].ddram_name);
			writeText(items[count].text, items[count].ddram_text);
	}

//	writeText(led->text, led->ddram_text);
}

void switchCursor(struct MenuItem *items, uint8_t count)
{
	setDDRAM(items[count - 1].ddram_name);

	sendData(' ');


	setDDRAM(items[count].ddram_name);

	sendData('>');
}

