#ifndef MENU_LIB

#define MENU_LIB


#define SELECT         1
#define CHANGE         2

#define BACK           3
#define SET_V          4
#define CHOOSED_LED    5
#define MINUS          6
#define PLUS           7

/*############################################################################################################*/


struct MenuItem
{
	char name[10];
	char text[10];
	uint8_t ddram_name;
	uint8_t ddram_text;
	uint8_t state_item;
	uint8_t PWM_lvl;
	uint32_t *PWM_Reg;
	struct MenuItem *subItem;
	struct MenuItem *parentalItem;
	struct MenuItem *navigation_list;
//	struct MenuItem *(*itemFunction)(const uint8_t const *);
	const struct MenuItem *(*itemFunction)(const struct MenuItem *, const uint8_t *PWM);
};

/*############################################################################################################*/

void writeText(uint8_t *name_item, uint8_t ddram_item);
const struct MenuItem *writeMainMenu(const struct MenuItem *items);
const struct MenuItem *writeSubLedMenu(const struct MenuItem *items);
void reWrite(const struct MenuItem const *items, const uint8_t *PWM);
void clearCursor(const struct MenuItem *item_clr);
void setCursor(const struct MenuItem *item_st);
void clearChar(uint8_t clear_ddram);
void switchCursor(const struct MenuItem *items_curr, const struct MenuItem  *item_prev);
const struct MenuItem *backFunc(const struct MenuItem *back_item);

/*############################################################################################################*/


#endif
