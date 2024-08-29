//Kshitij Tiwari MT2024080
//program to execute ls-rl by some system calls like execl,execlp,execle,execv,execvp
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main() 
{
  
    printf("By successful usage of execl:\n");
    execl("/bin/ls", "ls", "-Rl", (char *)NULL);
    perror("problem in execl execution");

    printf("By successful usage of execlp:\n");
    execlp("ls", "ls", "-Rl", (char *)NULL);
    perror("problem in execlp execution");

    printf("By successful usage of execle:\n");
    execle("/bin/ls", "ls", "-Rl", (char *)NULL, NULL);
    perror("problem in execle execution");

    printf("By succeesful usage of execv:\n");
    char *args_v[] = {"ls", "-Rl", NULL};
    execv("/bin/ls", args_v);
    perror("problem in execv execution");

    printf("By succeesful usage of execvp:\n");
    char *args_p[] = {"ls", "-Rl", NULL};
    execvp("ls", args_p);
    perror("problem in execvp execution");

    return 0;
}

//Output:- By successful usage of execl:
.:
//total 736
//-rw-rw-r-- 1 kshitij kshitij   152 Aug 29 19:25 1a.c
//-rwxrwxr-x 1 kshitij kshitij 15992 Aug 29 19:20 1a.out
//-rw-rw-r-- 1 kshitij kshitij   251 Aug 29 19:46 1c.c
//-rwxrwxr-x 1 kshitij kshitij 16000 Aug 29 19:44 a.out
//drwxr-xr-x 2 kshitij kshitij  4096 Jul 13 05:13 Desktop
//-rw-rw-r-- 1 kshitij kshitij     0 Aug  9 08:18 diii
//-rw-rw-r-- 1 kshitij kshitij     0 Aug  9 08:18 diii.c and much more
//

