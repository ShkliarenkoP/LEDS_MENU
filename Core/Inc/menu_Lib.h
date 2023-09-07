#ifndef MENU_LIB

#define MENU_LIB


#define SELECT         1
#define CHANGE         2

struct MenuItem
{
	uint8_t name[10];
	uint8_t text[10];
	uint8_t ddram_name;
	uint8_t ddram_text;
	void (*writeFunction)(uint8_t *, uint8_t);
	struct MenuItem *subItem;
	struct MenuItem *parentalItem;
};

void writeText(uint8_t *name_item, uint8_t ddram_item);
void writeMainMenu(struct MenuItem *items);
void writeSubLedMenu(struct MenuItem *items);
void switchCursor(struct MenuItem *items, uint8_t count);

#endif
