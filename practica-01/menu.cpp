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
	cout<< CHECK_100 <<"\t"<< TITLE_CHECK_1000 <<endl;
	cout<< EXIT <<"\t"<< TITLE_EXIT<<endl<<endl;
}

void Menu::doAction(char option) {

	long long int number = 0;
	switch(option) {
	case CHECK_NUMBER :
		
		system(CLEAR);
		cin.clear();

		cout<<"TYPE A NUMBER: ";
		cin>>number;

		if (isMagicNumber(number, true)){
			cout<<endl<<"HAPPY NUMBER"<<endl;
		} else {
			cout<<endl<<"UNHAPPY NUMBER"<<endl;
		}

		cout<<endl<<"PRESS ENTER TO RETURN MAIN MENU"<<endl;

		cin.ignore();
		cin.clear();
		cin.get();

		break;
	case CHECK_100 :

		cout<<endl<<TITLE_CHECK_1000<<endl;
		for( int i = 1; i < 1000 ; i++){
			if(isMagicNumber(i)){
				cout<<i<<endl;
			}
		}

		cout<<endl<<"PRESS ENTER TO RETURN MAIN MENU"<<endl;

		cin.ignore();
		cin.clear();
		cin.get();

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
