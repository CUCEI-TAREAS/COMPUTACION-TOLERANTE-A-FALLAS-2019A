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

	 long long number = 0;

	auto start = std::chrono::high_resolution_clock::now();
	auto elapsed = std::chrono::high_resolution_clock::now() - start;
	long long microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

	list<int> values ;

	switch(option) {
	case CHECK_NUMBER :
		
		system(CLEAR);
		cout<<"TYPE A NUMBER: ";
		cout<<std::flush;
		
		// not ready
		//values = next_input_square();
		
		values = next_input();
		//isMagicNumberDirectly(values, true);
		//

		/*
		cin>>tmp;
		*/
		//cout<<endl<<"ESTIMATE TIME: "<<estimateTime(number)<<endl<<endl;

		start = std::chrono::high_resolution_clock::now();

		//if (isMagicNumber(number, true)){
		if (isMagicNumberDirectly(values, true)){
			cout<<endl<<"HAPPY NUMBER"<<endl;
		} else {
			cout<<endl<<"UNHAPPY NUMBER"<<endl;
		}

		elapsed = std::chrono::high_resolution_clock::now() - start;
		microseconds = std::chrono::duration_cast<std::chrono::microseconds>(elapsed).count();

		cout<<endl<<"REAL TIME MICROSECONDS: "<<microseconds<<endl;

		cout<<endl<<"PRESS ENTER TO RETURN MAIN MENU"<<endl;
		cout << std::flush;

		//cin.ignore();
		//cin.clear();
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
		cout << std::flush;

		//cin.ignore();
		//cin.clear();
		cin.get();

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
/*
			cout<<key;
			if (key != -1) {
				if ((key == ENTER_KEY )) {
					break;
				}
				option = key - 48;
				++x;
				//temporal[x++] = option;
				//
		}
*/
	}
}

		/*
		if( std::cin >> option ) {

			if(option < CHECK_NUMBER or option > EXIT ) {
				cout<<endl<<"INVALID OPTION"<<endl;
				continue;
			}

			doAction(option);
			continue;

		} else {
			std::cin.clear();    // reset the fail state
			if (std::cin.peek() == '|') {
				//cout<<endl<<"INVALID OPTION"<<endl;
			} else {
				//cout<<endl<<"INVALID OPTION"<<endl;
		}
		// skip all characters in the stream up to the end of the current line.
		std::cin.ignore(std::numeric_limits<streamsize>::max(), '\n');

	}
		 if (std::cin.eof()) break;


*/
