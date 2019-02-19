#ifndef MENU_H_INCLUDED
#define MENU_H_INCLUDED

#define CLEAR "clear"

#define TITLE_MAIN_MENU     "WELCOME TO HAPPY NUMBERS"

#define TITLE_CHECK_NUMBER     "CHECK HAPPY NUMBER"
#define TITLE_CHECK_1000     "CHECK HAPPY NUMBERS FROM 1 UNTIL 1000"
#define TITLE_EXIT          "EXIT"

#define CHECK_NUMBER '1'
#define CHECK_100 '2'
#define EXIT '3'

class Menu {

public:
	Menu();
	~Menu();

	void printMenu(void);
	void doAction(char);
	void mainMenu(void);
};

#endif // MENU_H_INCLUDED
