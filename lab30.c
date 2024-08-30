//Kshitij Tiwari MT2024080
//Program to run a script at a specific time using a Daemon process

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <time.h>
#include <signal.h>

#define SCRIPT_PATH "/home/kshitij/shell1.sh"

void exe_script() 
{
    execl(SCRIPT_PATH, SCRIPT_PATH, (char *)NULL);
    perror("problem in execl execution");
}

void daen() {
    pid_t proid, sessid;
    int fide;

    proid = fork();
    if (proid < 0) {
        perror("fork call can't be executed");
    }
    if (proid > 0)
    {
        exit(0);
    }

    sessid = setsid();
    if (sessid < 0)
    {
        perror("sessionid can't be created");
    }

    proid = fork();//another fork just to make sure terminal can't be acquired
    if (proid < 0)
    {
        perror("fork can't be executed");
    }
    if (proid > 0) 
    {
        exit(0);
    }

   
    if (chdir("/") < 0)//change directory to root
    {
        perror("change of directory failed");
        
    }

    close(STDIN_FILENO);//all std fds will be closed(0,1,2)
    close(STDOUT_FILENO);
    close(STDERR_FILENO);

    fide = open("/dev/null", O_RDWR);//redirect all std fds to /dev/null using dup2()
    dup2(fide, STDIN_FILENO);
    dup2(fide, STDOUT_FILENO);
    dup2(fide, STDERR_FILENO);
    close(fide);
}

void script_time(time_t rt) //when to run the daemon script
{
    time_t ct;
    double sec_towait;

    while (1) 
    {
        ct = time(NULL);
        if (ct >= rt)
       	{
            exe_script();
        }

        sec_towait = difftime(rt, ct);
        if (sec_towait > 0)
       	{
            sleep((unsigned int)sec_towait);
        } 
	else
       	{
            break;
        }
    }
}

int main() 
{	
	
    time_t rt;

    rt = time(NULL) + 100;//set the time after which daemon process will run the script here it is 100 sec   
    daen();

    script_time(rt);

    return 0;
}


