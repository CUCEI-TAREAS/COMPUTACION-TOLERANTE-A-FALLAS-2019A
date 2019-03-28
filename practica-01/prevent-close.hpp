#ifndef PREVENT_CLOSE_H_INCLUDED
#define PREVENT_CLOSE_H_INCLUDED

#define ENTER_KEY 10
#define N0_KEY 48 
#define N9_KEY 57

#define STDIN_FILENO 0

#include <list>

/** Select to check if stdin has pending input */
int pending_input(void);

/** Input terminal mode; save old, setup new */
void setup_terminal(void);
void main_terminal(void);

/** Shutdown terminal mode */
void reset_terminal(void);

/** Return next input or -1 if none */
std::list<int> next_input(void);
unsigned long long next_input_square(void);

/*
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

#endif // PREVENT_CLOSE_INCLUDED
