#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(){
  printf("Pre-fork: I'm the parent and here is my PID: %d \n", getpid());
  int f = fork();
  if(f)
    f = fork();
  if (f == 0){
    printf("I’m a child: %d \t parent PID: %d\n\n", getpid(), getppid());
    srand(time(NULL));
    int r = (rand() % 16) + 5;
    sleep(r);
    printf("Child is finished\n");
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
