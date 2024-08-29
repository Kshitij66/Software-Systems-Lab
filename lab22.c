//Kshitij Tiwari MT2024080
//Lab22-program to open a file, call fork and then write using both child and parent process
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{
    int fide;
    pid_t proid;

    fide = open("testFile.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
   
    proid = fork();

    if (proid ==-1) 
    {      
        perror("problem in implementing fork");
    } 
    else if (proid == 0)
    {
        const char *c_displays = "Child is writing right now\n";
        write(fide, c_displays, sizeof(c_displays));
        printf("this file is written by child\n");
    } 
    else 
    {
        const char *p_displays = "Parent is writing right now\n";
        write(fide, p_displays, sizeof(p_displays));
        printf("this file is written by parent\n");
    }

    close(fide);
    return 0;
}

//Output obtained:- this file is written by parent  this file is written by child


