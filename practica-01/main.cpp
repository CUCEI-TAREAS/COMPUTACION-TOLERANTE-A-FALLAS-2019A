#include <iostream>
#include <cstdio>
#include <list>
#include <csignal>

#include "menu.hpp"

using namespace std;

void signalHandler( int signum  = 0 ) {

}

int main(){

	signal(SIGINT, signalHandler);

	Menu mainMenu = Menu();
	mainMenu.mainMenu();

	exit(EXIT_SUCCESS);
}
