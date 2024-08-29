//Kshitij Tiwari MT2024080
//obtain child process id and parent process id using fork()
#include <stdio.h>
#include <unistd.h>

int main()
{
    pid_t proid; //pid_t is a data type for processids

    proid = fork();

    if (proid == -1)
    {
        fprintf(stderr, "problem in implementing fork\n");
        return 1;
    }
    else if (proid == 0)
    {
        printf("Child Process processid = %d, Parent processid = %d\n", getpid(), getppid());
    } 
    else
    {
        printf("Parent Process processid = %d, Child processid = %d\n", getpid(), proid);
    }

    return 0;
}

//Output obtained is Parent Process processid = 16071, Child processid = 16072

