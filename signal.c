/* hello_signal.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>

bool condition = true;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  alarm(1); //Schedule a SIGALRM for 1 second
  
 
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  alarm(1);
  while(true){
    

    
    sleep(1);
    printf("Turing was right!\n");
    
    

  }; //busy wait for signal to be delivered
  return 0; //never reached
}