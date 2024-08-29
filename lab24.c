//Kshitij Tiwari MT2024080
//program to create orphan process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    pid_t proid;

    proid = fork();

    if (proid == -1)
    {
        perror("problem in implementing fork");
        exit(1);
    } 
    else if (proid > 0)
    {
        printf("obtained processid of parent = %d\n", getpid());
        printf("processid of child process = %d\n", proid);
        
        printf("exit the parent process \n");//parent process exits making child process orphan
        exit(0);
    }
    else
    {
        sleep(10);  // just to make that parent exits before child starts anything
        printf("Child processid obtained = %d, Parent process obtained = %d\n", getpid(), getppid());
        
        sleep(20); 
        printf("Child process is now getting finished \n");
    }

    return 0;
}

//Output obtained is obtained processid of parent = 22062
//processid of child process = 22063
//exit the parent process...so now the child process is orphan
//Child processid obtained = 21861, Parent process obtained = 2129  here it shwong 2129 instead of 1 because my "systemd" where i have run this is user session instance of systemd whose pid is 1
//Child process is now getting finished

