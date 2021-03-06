#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(){
  printf("Pre-fork: I'm the parent and here is my PID: %d \n", getpid());
  //forking
  int f;
  int f2 = 0;
  f = fork();
  if(f){
    f = fork();
    //variable to distinguish the second child from the first
    f2 = f + 1;
  }
  //child instructions
  if (f == 0){
    printf("I’m a child: %d \t parent PID: %d\n", getpid(), getppid());
    int r = 0;
    //to make different sleeping times
    if(f2){
      srand(time(NULL) + 1);
      r = rand() % 16 + 5;
    }
    else{
      srand(time(NULL));
      r = rand() % 16 + 5;
    }
    printf("Sleeping for %d secs\n\n",r);
    sleep(r);
    printf("Child is finished\n");
    return r;
  }
  //parent instructions
  else{
    int status;
    int c = wait(&status);
    printf("Completed child: \t PID: %d \t Asleep for: %d secs \t \n", c, WEXITSTATUS(status));
    printf("Parent is finished\n");
    exit(0);
  }

}
