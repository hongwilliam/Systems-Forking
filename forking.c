#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(){
  srand(time(NULL));

  printf("pre-fork \n");
  int f = -1;
  f = fork();
  if (f == 0){
    printf("I’m a child: %d \t f: %d \t parent: %d\n", getpid(), f, getppid() );
    int r = (rand() % 16) + 5;
    sleep(r);
    printf("Child is finished\n");
    return r; }
  else{
    printf("I’m a parent: %d \t \n", getpid() );
    int c = fork();
    int status;
    f = wait(&status);
    printf("Completed child: \t PID: %d \t how long asleep: %d \t \n", c, WEXITSTATUS(status));
    printf("Parent is finished\n");
    exit(0);
  }




}
