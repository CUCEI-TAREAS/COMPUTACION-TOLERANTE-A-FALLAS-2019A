#include <cstdlib>
#include <limits>
#include <iostream>
#include <chrono>

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

void Menu::doAction(short option) {

	long long int number = 0;

	auto start = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

	switch(option) {
	case CHECK_NUMBER :
		
		system(CLEAR);
		cin.ignore();
		cin.clear();

		cout<<"TYPE A NUMBER: ";
		cin>>number;

		cout<<endl<<"ESTIMATE TIME: "<<estimateTime(number)<<endl<<endl;

		start = std::chrono::high_resolution_clock::now();

		if (isMagicNumber(number, true)){
			cout<<endl<<"HAPPY NUMBER"<<endl;
		} else {
			cout<<endl<<"UNHAPPY NUMBER"<<endl;
		}

		elapsed = std::chrono::high_resolution_clock::now() - start;
		microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

		cout<<endl<<"REAL TIME MICROSECONDS: "<<microseconds<<endl;

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

	system(CLEAR);
	short option;
	while ( option != 3 ) {
	//while ( option != 3 !std::cin.eof() or option != 3) {

		printMenu();

		cout<< "CHOOSE A OPTION: ";

		if( std::cin >> option ) {

			if(option < CHECK_NUMBER or option > EXIT ) {
				cout<<endl<<"INVALID OPTION"<<endl;
				continue;
			}

			doAction(option);

		} else {
			std::cin.clear();    // reset the fail state
			if (std::cin.peek() == '|') {
				cout<<endl<<"INVALID OPTION"<<endl;
			} else {
				cout<<endl<<"INVALID OPTION"<<endl;
		}
		// skip all characters in the stream up to the end of the current line.
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');
		system(CLEAR);
		}
	}
}


