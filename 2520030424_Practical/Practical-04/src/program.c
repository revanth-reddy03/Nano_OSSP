#include<stdio.h>
#include<unistd.h>
#include<sys/wait.h>//used for wait() and waitpid() system calls
#include<stdlib.h>//used for exit() systemcall
int main(){
int pid[3];//initializing 3 childs
for(int i=0;i<3;i++){//loops which runs for 3 childs
pid[i]=fork();//creating 3 childs
if(pid[i]==0){//indicates a child process
printf("Child %d pid=%d\n",i+1,getpid());
sleep(i+1);//giving a pause after every child
exit(0);//exiting the std input
}
}
wait(NULL);//waiting for anyone child
printf("parent: one child is completed with wait()\n");
waitpid(pid[2],NULL,0);//waiting for specific pid
printf("parent: child 3 has completed with waitpid()\n");
wait(NULL);//waiting for last child to be completed
printf("parent: all are completed\n");//parent is chking the last child
}
