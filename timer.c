/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>


int count = 0;
bool condition = true;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  printf("Turing was right!\n");
 
}

void sigintHandler(int sig_num)
{
    signal(SIGINT, sigintHandler);
    printf("\n  Ctrl+C is clicked \n");
    printf("\n %d number of alarms delivered\n", count );
    condition = false;
}

int main(int argc, char * argv[])
{
  
  while(condition){
    
    signal(SIGALRM,handler); //register handler to handle SIGALRM
    alarm(1); //Schedule a SIGALRM for 1 second
    sleep(1);
    signal(SIGINT, sigintHandler);
    count += 1;
    
    

  }; //busy wait for signal to be delivered
  return 0; //never reached
}

