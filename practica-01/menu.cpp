#include <cstdlib>
#include <iostream>

#include "menu.hpp"
#include "happy_number.hpp"

using namespace std;

Menu::Menu() {
}

Menu::~Menu() {
}

void Menu::printMenu() {

	cout<< TITLE_MAIN_MENU<<endl<<endl;
	cout<< CHECK_NUMBER <<"\t"<< TITLE_CHECK_NUMBER <<endl;
	cout<< EXIT <<"\t"<< TITLE_EXIT<<endl<<endl;
}

void Menu::doAction(char option) {

	long long int number = 0;
	switch(option) {
	case CHECK_NUMBER :
		
		cin.clear();
		cout<<"TYPE A NUMBER: ";
		cin>>number;
		isMagicNumber(number);
		cin.ignore();
		cin.clear();
		cin.get();

		break;
	case EXIT :
		break;
	}
}

void Menu::mainMenu() {

	char option;
	do {
		system(CLEAR);
		cin.clear();
		printMenu();

		cout<< "CHOOSE A OPTION: ";
		cin>>option;

		if(option < CHECK_NUMBER or option > EXIT ) {
			cout<<option<<"INVALID OPTION"<<endl;
			cin.ignore();
			cin.clear();
			cin.get();
		}
		doAction(option);
	} while(option != EXIT);
}
