//Kshitij Tiwari MT2024080
//Create three child process and parent will wait for one particular child process using waitpid() system call
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main() 
{
    pid_t proid1, proid2, proid3;
    pid_t proid_towait;

    proid1 = fork();

    if (proid1 == 0)
    {
        printf("obtained the processid of first child %d\n", getpid());
        sleep(3); 
        exit(0);
    }

    proid2 = fork();

    if (proid2 == 0)
    {  
        printf("obtained the processid of second child %d\n", getpid());
        sleep(7);
        exit(0);
    }

    proid3 = fork();

    if (proid3 == 0)
    {
        printf("obtained the processid of third child %d\n", getpid());
        sleep(10);
        exit(0);
    }

    proid_towait = waitpid(proid1, NULL, 0);

    if (proid_towait == -1)
    {
        perror("waitpid couldn't be executed");
        exit(1);
    }

    printf("child processid for which parent has waited %d\n", proid_towait);

    wait(NULL);
    wait(NULL); 

    printf("now the parent process has exited \n");

    return 0;
}

//Output :- obtained the processid of second child 24182
//obtained the processid of first child 24181
//obtained the processid of third child 24183
//child processid for which parent has waited 24181
//now the parent process has exited 

