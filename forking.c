#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>


int main(){
  srand(time(NULL));

  printf("Pre-fork: I'm a parent and here is my PID: %d \n", getpid() );
  int f1, f2;
  f1 = fork();
  if (f1 == 0){
    printf("I’m child 1 and here is my PID: %d \t parent PID: %d\n", getpid(), getppid() );
    int r = (rand() % 16) + 5;
    sleep(r);
    printf("Child 1 is finished\n");
    return r; }
  else{
    f2 = fork(); //forking off two chuld processes
    if (f2 == 0){
      printf("I’m child 2 and here is my PID: %d \t parent PID: %d\n", getpid(), getppid() );
      rand(); //seed new rand
      int r = (rand() % 16) + 5;
      sleep(r);
      printf("Child 2 is finished \n");
      return r; }
    else{
        int status;
        printf("Child process just finished, here is my PID: %d\t sleep time: %d \n", wait(&status), WEXITSTATUS(status));
        printf("Parent process is done, end the program \n");
        exit(0); }
  }

}
