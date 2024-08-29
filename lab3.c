// Kshitij Tiwari MT2024080
// create a file and obtain the file descriptor
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
int main()
{
const char *fname = "work.txt";
int fide = creat(fname, 0666);// create a file with initial permission as read and write for all
if(fide<0)
{
perror("problem in creating the file");
return 1;
}
printf("file descriptor obtained for '%s':%d\n", fname, fide);
close(fide);
return 0;
}

//Output :- file descriptor obtained is 'work.txt':3

