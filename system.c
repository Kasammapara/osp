#include<stdio.h>
#include<unistd.h>
int main(){
int n;
printf("Hello \n");
n=fork();
printf("World \n");
if(n>0){
printf("parent procees id : %d",getpid());
}
else if(n=0){
printf("child process id is: %d",getpid());
}
else{
printf("error creating child process");
}
/*fork();
printf("Crew ");*/
return 0;
}


#include<stdio.h>
#include<unistd.h>
int main(){
fork();
fork();
fork();
fork();
printf("Hello \n");
return 0;
}


#include <stdio.h>
#include <unistd.h>
int main()
{
pid_t pid;
pid = getpid();
printf("Process ID: %d\n", pid);
return 0;
}
#include<stdio.h>
#include<unistd.h>
int main(){
int x=1;
if(fork()==0){
printf("child has x=%d \n",++x);
}
else{
printf("child has x=%d \n",--x);
}
return 0;
}