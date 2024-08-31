//Kshitij Tiwari MT2024080
//program to execute ls-rl by some system calls like execl,execlp,execle,execv,execvp


#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

//exec function is important for process control they simply replace the current process image with a new process image which basically means that running a program within same process 

void exec_with_execl() 
{
    printf("\nsuccessful execution using execl:\n");
    execl("/bin/ls", "ls", "-Rl", NULL);//ls-Rl is basically here to show us how a real command can be run within this c program
    perror("execution unsuccessful through execl");
}

void exec_with_execlp() {
    printf("\nsuccessful execution using execlp:\n");
    execlp("ls", "ls", "-Rl", NULL);
    perror("execution unsuccessful through execlp");
}

void exec_with_execle()
{
    printf("\nsuccessful execution using execle:\n");
    char *envp[] = { "PATH=/bin:/usr/bin", NULL };
    execle("/bin/ls", "ls", "-Rl", NULL, envp);
    perror("execution unsuccessful through execle");
}

void exec_with_execv() 
{
    printf("\nsuccessful execution using execv:\n");
    char *args[] = { "ls", "-Rl", NULL };
    execv("/bin/ls", args);
    perror("execution unsuccessful through execv");
}

void exec_with_execvp()
{
    printf("\nsuccessful execution using execvp:\n");
    char *args[] = { "ls", "-Rl", NULL };
    execvp("ls", args);
    perror("execution unsuccessful through execvp ");
}

int main() 
{
    int execho;

    printf("select the exec function we want to test:\n");
    printf("1. execl\n");
    printf("2. execlp\n");
    printf("3. execle\n");
    printf("4. execv\n");
    printf("5. execvp\n");
    printf("Select your execution choice (1-5): ");
    scanf("%d", &execho);

    switch(execho) //switch cases to select which exec() to run at a particular time
    {
        case 1:
            exec_with_execl();
            break;
        case 2:
            exec_with_execlp();
            break;
        case 3:
            exec_with_execle();
            break;
        case 4:
            exec_with_execv();
            break;
        case 5:
            exec_with_execvp();
            break;
        default:
            printf("wrong choice entered\n");
            return 1;
    }

    return 0;
}


//Output:- I have shown output for 2 exec():- execl and execlp
//select the exec function we want to test:
//1. execl
2. execlp
3. execle
4. execv
5. execvp
Select your execution choice (1-5): 1

successful execution using execl:
.:
total 160
-rw-rw-r-- 1 kshitij kshitij  1396 Aug 29 23:59 10.c
-rw-rw-r-- 1 kshitij kshitij  2405 Aug 30 00:06 11.c
-rw-rw-r-- 1 kshitij kshitij  1660 Aug 30 00:15 12.c
-rw-rw-r-- 1 kshitij kshitij  1181 Aug 30 00:29 13.c
-rw-rw-r-- 1 kshitij kshitij   979 Aug 30 00:35 14.c
-rw-rw-r-- 1 kshitij kshitij   792 Aug 30 00:44 15.c
-rw-rw-r-- 1 kshitij kshitij  2057 Aug 30 00:47 16.c
-rw-rw-r-- 1 kshitij kshitij  1258 Aug 30 00:53 17b.c
-rw-rw-r-- 1 kshitij kshitij   456 Aug 30 00:49 17.c
-rw-rw-r-- 1 kshitij kshitij   551 Aug 30 00:56 18a.c
-rw-rw-r-- 1 kshitij kshitij  1608 Aug 30 01:00 18b.c
-rw-rw-r-- 1 kshitij kshitij  1364 Aug 30 01:03 18c.c
-rw-rw-r-- 1 kshitij kshitij   846 Aug 30 01:04 19.c
-rw-rw-r-- 1 kshitij kshitij   489 Aug 30 14:50 1a.c
-rw-rw-r-- 1 kshitij kshitij   510 Aug 30 14:50 1b.c
-rw-rw-r-- 1 kshitij kshitij   509 Aug 30 14:55 1c.c
-rw-rw-r-- 1 kshitij kshitij   760 Aug 30 01:06 20.c
-rw-rw-r-- 1 kshitij kshitij   669 Aug 30 01:06 21.c
-rw-rw-r-- 1 kshitij kshitij   946 Aug 30 01:07 22.c
-rw-rw-r-- 1 kshitij kshitij  1033 Aug 30 01:07 23.c
-rw-rw-r-- 1 kshitij kshitij  1263 Aug 30 01:07 24.c
-rw-rw-r-- 1 kshitij kshitij  1361 Aug 30 01:07 25.c
-rw-rw-r-- 1 kshitij kshitij   529 Aug 30 16:10 26.c
-rw-rw-r-- 1 kshitij kshitij  2740 Aug 31 12:27 27.c
-rwxrwxr-x 1 kshitij kshitij 16552 Aug 31 12:27 27.out
-rw-rw-r-- 1 kshitij kshitij   755 Aug 30 01:07 28.c
-rw-rw-r-- 1 kshitij kshitij  1518 Aug 30 01:27 29.c
-rw-rw-r-- 1 kshitij kshitij   476 Aug 29 20:45 2.c
-rw-rw-r-- 1 kshitij kshitij  1955 Aug 30 23:51 30.c
-rw-rw-r-- 1 kshitij kshitij   481 Aug 29 20:59 3.c
-rw-rw-r-- 1 kshitij kshitij  1112 Aug 30 14:30 4.c
-rw-rw-r-- 1 kshitij kshitij  1693 Aug 29 23:42 5.c
-rw-rw-r-- 1 kshitij kshitij   162 Aug 25 20:17 6.c
-rw-rw-r-- 1 kshitij kshitij   416 Aug 29 21:20 7.c
-rw-rw-r-- 1 kshitij kshitij   692 Aug 30 12:50 8.c
-rw-rw-r-- 1 kshitij kshitij  1665 Aug 30 13:58 9.c
kshitij@kshitij-Yoga-Slim-6-14IAP8:~/my-repo/Software-Systems-Lab$ ./27.out
select the exec function we want to test:
1. execl
2. execlp
3. execle
4. execv
5. execvp
Select your execution choice (1-5): 2

successful execution using execlp:
.:
total 160
-rw-rw-r-- 1 kshitij kshitij  1396 Aug 29 23:59 10.c
-rw-rw-r-- 1 kshitij kshitij  2405 Aug 30 00:06 11.c
-rw-rw-r-- 1 kshitij kshitij  1660 Aug 30 00:15 12.c
-rw-rw-r-- 1 kshitij kshitij  1181 Aug 30 00:29 13.c
-rw-rw-r-- 1 kshitij kshitij   979 Aug 30 00:35 14.c
-rw-rw-r-- 1 kshitij kshitij   792 Aug 30 00:44 15.c
-rw-rw-r-- 1 kshitij kshitij  2057 Aug 30 00:47 16.c
-rw-rw-r-- 1 kshitij kshitij  1258 Aug 30 00:53 17b.c
-rw-rw-r-- 1 kshitij kshitij   456 Aug 30 00:49 17.c
-rw-rw-r-- 1 kshitij kshitij   551 Aug 30 00:56 18a.c
-rw-rw-r-- 1 kshitij kshitij  1608 Aug 30 01:00 18b.c
-rw-rw-r-- 1 kshitij kshitij  1364 Aug 30 01:03 18c.c
-rw-rw-r-- 1 kshitij kshitij   846 Aug 30 01:04 19.c
-rw-rw-r-- 1 kshitij kshitij   489 Aug 30 14:50 1a.c
-rw-rw-r-- 1 kshitij kshitij   510 Aug 30 14:50 1b.c
-rw-rw-r-- 1 kshitij kshitij   509 Aug 30 14:55 1c.c
-rw-rw-r-- 1 kshitij kshitij   760 Aug 30 01:06 20.c
-rw-rw-r-- 1 kshitij kshitij   669 Aug 30 01:06 21.c
-rw-rw-r-- 1 kshitij kshitij   946 Aug 30 01:07 22.c
-rw-rw-r-- 1 kshitij kshitij  1033 Aug 30 01:07 23.c
-rw-rw-r-- 1 kshitij kshitij  1263 Aug 30 01:07 24.c
-rw-rw-r-- 1 kshitij kshitij  1361 Aug 30 01:07 25.c
-rw-rw-r-- 1 kshitij kshitij   529 Aug 30 16:10 26.c
-rw-rw-r-- 1 kshitij kshitij  2740 Aug 31 12:27 27.c
-rwxrwxr-x 1 kshitij kshitij 16552 Aug 31 12:27 27.out
-rw-rw-r-- 1 kshitij kshitij   755 Aug 30 01:07 28.c
-rw-rw-r-- 1 kshitij kshitij  1518 Aug 30 01:27 29.c
-rw-rw-r-- 1 kshitij kshitij   476 Aug 29 20:45 2.c
-rw-rw-r-- 1 kshitij kshitij  1955 Aug 30 23:51 30.c
-rw-rw-r-- 1 kshitij kshitij   481 Aug 29 20:59 3.c
-rw-rw-r-- 1 kshitij kshitij  1112 Aug 30 14:30 4.c
-rw-rw-r-- 1 kshitij kshitij  1693 Aug 29 23:42 5.c
-rw-rw-r-- 1 kshitij kshitij   162 Aug 25 20:17 6.c
-rw-rw-r-- 1 kshitij kshitij   416 Aug 29 21:20 7.c
-rw-rw-r-- 1 kshitij kshitij   692 Aug 30 12:50 8.c
-rw-rw-r-- 1 kshitij kshitij  1665 Aug 30 13:58 9.c


