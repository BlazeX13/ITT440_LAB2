#include<stdio.h>
#include<stdlib.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<unistd.h>
void name()
{
char name[20];
printf("Please enter your name:");
fgets(name,20,stdin);
printf("Your name is %s\n",name);
}
int main(void)
{
for(int i=1;i<5;i++)
{
pid_t pid=fork();
if(pid==0)
{
name();
printf("Child process=>PPID=%d,PID=%d\n",getppid(),getpid());
exit(0);
}
else
{
printf("Parent process=>PID=%d\n",getpid());
wait(NULL);
}
}
return EXIT_SUCCESS;
}
