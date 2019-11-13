#include <sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
int main(){
  int result;
  struct stat *buffer=malloc(sizeof(struct stat));
  result=stat("hello.txt", buffer);
  if (result==-1) {
    printf("You failed.\n");
    return 0;
  }
  printf("%0d\n",buffer->st_mode);
  return 0;
}
