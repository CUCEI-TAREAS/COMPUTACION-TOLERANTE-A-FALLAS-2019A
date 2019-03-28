#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <termios.h>
#include <time.h>
#include <sys/select.h>

#include <list>
#include <iostream>

#include "prevent-close.hpp"

#define STDIN_FILENO 0

using namespace std;

struct termios org_opts;
struct termios new_opts;

/** Select to check if stdin has pending input */
int pending_input(void) {
  struct timeval tv;
  fd_set fds;
  tv.tv_sec = 1;
  tv.tv_usec = 1000;
  FD_ZERO(&fds);
  FD_SET(STDIN_FILENO, &fds); //STDIN_FILENO is 0
  select(STDIN_FILENO+1, &fds, NULL, NULL, &tv);
  return FD_ISSET(STDIN_FILENO, &fds);
}

/** Input terminal mode; save old, setup new */
void setup_terminal(void) {
  tcgetattr(STDIN_FILENO, &org_opts);
  memcpy(&new_opts, &org_opts, sizeof(new_opts));
  //new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ISIG | ICRNL);
  new_opts.c_lflag &= ~( ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ISIG | IXON | ICRNL);
  //new_opts.c_lflag &= ~( ICANON |  ISIG | IXON | ICRNL);
  //new_opts.c_lflag &= ~(  ISIG | IXON | ICRNL);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
}

/** Input terminal mode; save old, setup new */
void main_terminal(void) {
  //new_opts.c_lflag &= ~(ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ISIG | ICRNL);
  //new_opts.c_lflag &= ~( ICANON | ECHO | ECHOE | ECHOK | ECHONL | ECHOPRT | ECHOKE | ISIG | IXON | ICRNL);
  //new_opts.c_lflag &= ~(  ISIG | IXON | ICRNL);
  tcsetattr(STDIN_FILENO, TCSANOW, &new_opts);
}

/** Shutdown terminal mode */
void reset_terminal(void) {
  tcsetattr(STDIN_FILENO, TCSANOW, &org_opts);
}

/** Return next input or -1 if none */
list<int> next_input(void) {

	list<int> values;

	while(1){

		if (!pending_input())
			continue;

		int rtn = fgetc(stdin);
		if ( rtn != ENTER_KEY ){
			
			if ( rtn >= N0_KEY and rtn <= N9_KEY ){
				int value = rtn -= N0_KEY;
				cout<<value;
				 cout<< std::flush;
				values.push_front(value);
			}

		} else {
			return values;
		}

	}
}

/*
	if ( rtn == 13 ) {
		printf("\nenter\n");
	}
	//if ((rtn >= 48 ) and (rtn <= 57 ) or rtn == 13 ) {
	if ((rtn >= 48 ) and (rtn <= 57 ) ) {
	}



int main()
{
  setup_terminal();

  printf("Press Q to quit...\n");
  for (;;) {
    int key = next_input();
    if (key != -1) {
      if ((key == 113) || (key == 81)) {
        printf("\nNormal exit\n");
        break;
      }
    }
  }

  reset_terminal();
  return 0;
}

*/
