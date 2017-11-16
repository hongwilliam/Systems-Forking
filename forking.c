#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(){

  printf("pre-fork \n");
  int f = -1;
  printf("I'm the parent: %d \n\n", getpid());
  f = fork();
  if(f)
    f = fork();
  if (f == 0){
    printf("I’m a child: %d \n", getpid());
    srand(time(NULL));
    int r = (rand() % 16) + 5;
    printf("Sleeping for %d secs...\n\n",r);
    sleep(r);
    printf("Child is finished\n\n");
    return r;
  }
  else{
    int status;
    int c = wait(&status);
    printf("Completed child: \t PID: %d \t Asleep for: %d secs \t \n", c, WEXITSTATUS(status));
    printf("Parent is finished\n");
    exit(0);
  }




}
