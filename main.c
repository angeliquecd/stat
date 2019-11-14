#include <sys/stat.h>
#include<unistd.h>
#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include <math.h>
void printpermissions(int permissions){
  char usery[3];
  usery[0]='-';
  usery[1]='-';
  usery[2]='-';
  int user = permissions%8;
//  printf("%o",user);
  if (user>=4) {usery[0]='r';
  user=user-4;}
  if (user>=2) {
    usery[1]='w';
    user=user-2;}
  if (user==1) usery[2]='x';

  char groupy[3];
  groupy[0]='-';
  groupy[1]='-';
  groupy[2]='-';
   user = ((permissions-user)/8)%8;
  // printf("%o",user);
   if (user>=4) {groupy[0]='r';
   user=user-4;}
   if (user>=2) {
     groupy[1]='w';
     user=user-2;}
   if (user==1) groupy[2]='x';

  char owner[3];
   user = permissions/64;
    //  printf("%o",user);
   if (user>=4) {owner[0]='r';
   user=user-4;}
   else owner[0]='-';
   if (user>=2) {
     owner[1]='w';
     user=user-2;}
    else owner[1]='-';
   if (user==1) owner[2]='x';
   else owner[2]='-';
   //printf("%s\n",owner);
  //if (user>=
  printf("%s%s\n",owner ,groupy);
}
int main(){
  printf("Using main.c as file.\n");
  int result;
  char info[100];
  struct stat *buffer=malloc(sizeof(struct stat));
  result=stat("main.c", buffer);
  if (result==-1) {
    printf("You failed.\n");
    return 0;
  }
  int permissions = buffer->st_mode;
permissions-=pow(8,5);
//printpermissions(permissions);
  int filesize=buffer->st_size;
  if (filesize<1000) sprintf(info,"%dB",filesize);
  if (filesize>1000 && filesize<1000000) sprintf(info,"%dKB",filesize/1000);
  if (filesize>1000000 && filesize<1000000000) sprintf(info,"%dMB",filesize/1000000);
  if (filesize>1000000000)sprintf(info,"%dGB",filesize/1000000000);
  printf("Printing the size of the file: %s\n",info);
  //printf("Printing the size of the file: %ld B\n",buffer->st_size);
  printf("Printing the permissions of the file: (%o) ",permissions);
  printpermissions(permissions);
  printf("Printing the time of last acces: %s",ctime(&(buffer->st_atime)));
  //printf("%0d\n",buffer->st_mode);
  return 0;
}
