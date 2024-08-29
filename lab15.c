//Kshitij Tiwari Roll-Mt2024080
//Lab15 display environmental variables of the user
//basically those values which affects the behaviour of the processes which are running on the system

#include <stdio.h>
#include <string.h>

extern char **environ;

int main()
{
    char **eval = environ; 

    
    while (*eval) 
    {
 
        if (strncmp(*eval, "USER=", 5) == 0 ||
            strncmp(*eval, "HOME=", 5) == 0 ||
            strncmp(*eval, "LOGNAME=", 8) == 0 ||
            strncmp(*eval, "SHELL=", 6) == 0)  //this is to check if variables is related to user
       	{
            printf("%s\n", *eval);
        }
        eval++;
    }

    return 0;
}

//Output:- these are user-related enviromental variables
//SHELL=/bin/bash
//LOGNAME=kshitij
//HOME=/home/kshitij
//USER=kshitij

