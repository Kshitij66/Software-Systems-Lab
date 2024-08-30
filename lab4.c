//Kshitij Tiwari MT2024080
//Program to open an existing file in read and write mode and also try O_EXCL Flag
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <errno.h>

int main()
{
    int fide;

    fide = open("work.txt", O_RDWR);//work.txt is an existing file which is getting opened
    if (fide<0)
    {
        perror("problem in opening the file in read write mode");
        return 1;
    } 
    else
    {
        printf("File has been successfully opened \n");
    }

    int fide_el = open("work.txt", O_RDWR | O_EXCL);//open the file again this time using O_EXCL flag 
    if (fide_el == -1) 
    {
        if (errno == EEXIST)
       	{
            printf("O_EXCL flag will show that file is present already so can't open\n");
        } 
	else
       	{
            perror("problem in O_EXCL flag display");
        }
    }
    else
    {
        printf("File has opened succussfully this time with O_EXCL \n");
        close(fide_el);
    }

    close(fide);

    return 0;
}

//Output:- File has been successfully opened 
//File has opened succussfully this time with O_EXCL 

