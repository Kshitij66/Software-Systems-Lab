//Kshitij Tiwari MT2024080
//program for the creation of fifo type file using myfifo system call
#include<sys/types.h>
#include<sys/stat.h>
#include<stdio.h>

int main()
{
        if(mkfifo("fifoo1",0666)== -1)
        {
                perror("mkfifo has not been created");
        }
return 0;
}

//Output :- Here a file "fifoo1" is created(we can see using ls command) which act as a pipe for interprocess communication i.e. one process can write to this file while another process canread what's written

