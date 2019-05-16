#include <cstdlib>
#include <limits>
#include <iostream>
#include <chrono>

#include "menu.hpp"
#include "happy_number.hpp"
#include "prevent-close.hpp"

using namespace std;

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::printMenu() {

	cout<< TITLE_MAIN_MENU<<endl<<endl;
	cout<< CHECK_NUMBER <<"\t"<< TITLE_CHECK_NUMBER <<endl;
	cout<< CHECK_100 <<"\t"<< TITLE_CHECK_1000 <<endl;
	cout<< EXIT <<"\t"<< TITLE_EXIT<<endl<<endl;

	// wrong placed
	cout<<endl<< "CHOOSE A OPTION: "<<endl;
	cout<<flush;
}

void Menu::doAction(short option) {

	switch(option) {
	case CHECK_NUMBER :
		
		system(CLEAR);
		cout<<"TYPE A NUMBER: ";
		cout<<std::flush;
		
		
		values = next_input();


		cout<<endl<<"PRESS ENTER TO RETURN MAIN MENU"<<endl;
		cout << std::flush;
		cin.get();

		break;
	case CHECK_100 :

		cout<<endl<<"PRESS ENTER TO RETURN MAIN MENU"<<endl;
		cout << std::flush;
		cin.get();
		break;

	case EXIT :
		break;
	}
}

void Menu::mainMenu() {

	short option;
	while ( option != EXIT ) {

		system(CLEAR);
		printMenu();

		list<int> values = next_input();

		if ( values.size() > 1)
			continue;

		option = values.front();

		if ( option != EXIT) {
			doAction(option); 
		}
	}
}
