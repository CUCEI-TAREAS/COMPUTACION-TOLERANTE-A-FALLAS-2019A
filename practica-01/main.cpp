#include <iostream>
#include <cstdio>
#include <list>
#include <csignal>

#include "menu.hpp"
#include "prevent-close.hpp"

using namespace std;

void signalHandler( int signum  = 0 ) {

}

int main(){

	setup_terminal();

	signal(SIGINT, signalHandler);
	signal(SIGABRT, signalHandler);
	signal(SIGSTOP, signalHandler);
	signal(SIGTSTP, signalHandler);
	signal(EOF, signalHandler);

	Menu mainMenu = Menu();
	mainMenu.mainMenu();

	reset_terminal();

	exit(EXIT_SUCCESS);
}
