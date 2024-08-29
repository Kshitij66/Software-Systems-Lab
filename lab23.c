//Kshitij Tiwari MT2024080
//Program to create zombie state of current running process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
    pid_t proid;

    proid = fork();

    if(proid == -1)
    {
        perror("problem in implementing fork");
        exit(1);
    } 
    else if (proid > 0)
    {
       
        printf("obtain the parent processid = %d\n", getpid());
        printf("created child processid = %d\n", proid);
        
        sleep(25); // let parent sleep for 25s by the time child process will be exited
        
        printf("Now parent will exit \n");
    } 
    else
    {
        printf("obtain the child processid = %d\n", getpid());
        printf("child immediately exits \n");
        exit(0);
    }

    return 0;
}

//Output will be :- obtain the parent processid = 20304
//created child processid = 20305
//obtain the child processid = 20305
//child immediately exits 
//After 25s parent process will wake up and exits removing the zombie process
//Now parent will exit
