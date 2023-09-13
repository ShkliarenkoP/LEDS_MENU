#include "LCD_Lib.h"
#include "menu_Lib.h"

/*############################################################################################################*/


void writeText(uint8_t *name_item, uint8_t ddram_item)
{
	setDDRAM(ddram_item);

	sendText(name_item);
}

/*############################################################################################################*/

struct MenuItem *writeMainMenu(const struct MenuItem const *items)
{
	clearDisplay();

	for(uint8_t count = 0; count < 4; count++)
	{
		writeText(items[count].name, items[count].ddram_name);
	}

	setCursor(items);

	return items;
}

struct MenuItem *writeSubLedMenu(const struct MenuItem const *items)
{
	clearDisplay();

	for(uint8_t count = 0; count < 2; count++)
	{
			writeText(items[count].name, items[count].ddram_name);
			writeText(items[count].text, items[count].ddram_text);
	}

	setCursor(items);

	return items;
}

/*############################################################################################################*/

void switchCursor(const struct MenuItem const *items_prev, const struct MenuItem const *item_curr)
{
	clearCursor(items_prev);
	setCursor(item_curr);

}

void clearCursor(const struct MenuItem const *item_clr)
{
	setDDRAM(item_clr->ddram_name);

	sendData(' ');
}

void setCursor(const struct MenuItem const *item_st)
{

	setDDRAM(item_st->ddram_name);

	sendData('>');
}

/*############################################################################################################*/

struct MenuItem *backFunc(const struct MenuItem *back_item)
{
	return back_item->writeFunction(back_item->subItem);
}

