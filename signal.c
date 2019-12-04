/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include "timer.h"

void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  increment_alarm();
}

int main(int argc, char * argv[])
{
  signal(SIGINT,sigint_handler); 
  signal(SIGALRM,handler); 
  while(0) //Keeps running indefinitly
  {
    alarm(1); // Schedule executable to 1 second
    sleep(1);
    printf("Turing was right!\n");
  }
  return 0; // Never reached.
}
