/* timer.c */
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>
#include <stdbool.h>


int count = 0;
bool condition = false;
void handler(int signum)
{ //signal handler
  printf("Hello World!\n");
  condition = true;
  
 
}

void sigintHandler(int sig_num)
{
    // signal(SIGINT, sigintHandler);
    printf("\n  Ctrl+C is clicked \n");
    printf("\n %d number of alarms delivered for %d seconds\n", count, count);

    exit(1);
    
}

int main(int argc, char * argv[])
{
  signal(SIGALRM,handler); //register handler to handle SIGALRM
  signal(SIGINT, sigintHandler);
  alarm(1);
  while(true){
    if (condition){
      printf("Turing was right!\n");
      condition = false;
      alarm(1); //Schedule a SIGALRM for 1 second
      count += 1;

    }
    
    
    
    
    

  }; //busy wait for signal to be delivered
  return 0; //never reached
}

