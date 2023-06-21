#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
int main()
{
    printf("Before Fork\n");
    pid_t p = fork();
    // printf("%d",p);
    if(p==0)
    {
        printf("It's a child %d\n",getpid());
        printf("And parent is %d\n",getppid());
    }
    else
    {
        printf("It's parent %d\n",p);
        printf("It's child %d\n",getpid());
    }
}
