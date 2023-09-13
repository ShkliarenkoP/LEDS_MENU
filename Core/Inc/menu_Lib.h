#ifndef MENU_LIB

#define MENU_LIB


#define SELECT         1
#define CHANGE         2

#define BACK           3
#define SET_V          4
#define CHOOSED_LED    5

/*############################################################################################################*/


struct MenuItem
{
	uint8_t name[10];
	uint8_t text[10];
	uint8_t ddram_name;
	uint8_t ddram_text;
	uint8_t state_item;
	struct MenuItem *subItem;
	struct MenuItem *parentalItem;
	struct MenuItem *navigation_list;
	struct MenuItem *(*writeFunction)(const uint8_t const *);
};

/*############################################################################################################*/

void writeText(uint8_t *name_item, uint8_t ddram_item);
struct MenuItem *writeMainMenu(const struct MenuItem const *items);
struct MenuItem *writeSubLedMenu(const struct MenuItem const *items);
void clearCursor(const struct MenuItem const *item_clr);
void setCursor(const struct MenuItem const *item_st);
void switchCursor(const struct MenuItem const *items_curr, const struct MenuItem const *item_prev);
struct MenuItem *backFunc(const struct MenuItem *back_item);

/*############################################################################################################*/


#endif
