//Kshitij Tiwari MT2024080
//program to execute the executable program used an already present executable program and pass some input
#include <stdio.h>
#include <stdlib.h>

int main()
{
   
    const char *exec = "./lab29.out";//executable file has been provided
    const char *ip = "heree";//input to pass as argument
    char comm[512];
    snprintf(comm, sizeof(comm), "%s %s", exec, ip);
    
    int fl = system(comm);
    
    if (fl == -1)
    {
        perror("problem in running command");
    }
    
    return 1;
}

