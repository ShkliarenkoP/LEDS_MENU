#include "LCD_Lib.h"
#include "menu_Lib.h"
#include "stdio.h"

/*############################################################################################################*/


void writeText(uint8_t *name_item, uint8_t ddram_item)
{
	setDDRAM(ddram_item);

	sendText(name_item);
}

/*############################################################################################################*/

const struct MenuItem *writeMainMenu(const struct MenuItem *items)
{
	clearDisplay();

	for(uint8_t count = 0; count < 4; count++)
	{
		writeText(items[count].text, items[count].ddram_name);
	}

	setCursor(items);

	return items;
}

const struct MenuItem *writeSubLedMenu(const struct MenuItem *items)
{
	clearDisplay();

	for(uint8_t count = 0; count < 4; count++)
	{
			writeText(items[count].name, items[count].ddram_name);
			writeText(items[count].text, items[count].ddram_text);
	}

	setCursor(items);

	return items;
}

void reWrite(const struct MenuItem const *items, const uint8_t *PWM)
{
	sprintf(items->text, "%s%d", items->subItem->name, *PWM);
	writeText(items->text, 0x00);
}

/*############################################################################################################*/

void switchCursor(const struct MenuItem *items_prev, const struct MenuItem *item_curr)
{
	clearCursor(items_prev);
	setCursor(item_curr);

}

void clearCursor(const struct MenuItem *item_clr)
{
	setDDRAM(item_clr->ddram_name);

	sendData(' ');
}

void setCursor(const struct MenuItem *item_st)
{

	setDDRAM(item_st->ddram_name);

	sendData('>');
}

void clearChar(uint8_t clear_ddram)
{
	setDDRAM(clear_ddram);

	sendData(' ');
}

/*############################################################################################################*/

const struct MenuItem *backFunc(const struct MenuItem *back_item)
{
	return back_item->itemFunction(back_item->subItem, NULL);
}

