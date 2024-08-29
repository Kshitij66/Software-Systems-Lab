//Kshitij Tiwari MT2024080
//program to implement write lock,read ticketno increment the number and print new number 
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <errno.h>

int main()
{
   
    int fide = open("storeTno.txt", O_RDWR);//open the file
   

    //structure to implement write lock
    struct flock lock;
    lock.l_type = F_WRLCK;  
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;//from the beginning
    lock.l_len = 0; //lock the entire file

    if (fcntl(fide, F_SETLKW, &lock) == -1) {
        perror("problem in implementing write lock");
        close(fide);

    }

    int t_no;
    FILE *fl = fdopen(fide, "r+");

    fscanf(fl, "%d", &t_no);
    printf("At present tno is : %d\n", t_no);

    
    t_no++;
    rewind(fl); 
    fprintf(fl, "%d\n", t_no);
    fflush(fl); 

    printf("New tno obtained is : %d\n", t_no);

  
    lock.l_type = F_UNLCK;
    if (fcntl(fide, F_SETLK, &lock) == -1)
    {
       perror("problem during unlocking of file");
        close(fide);
    }

    fclose(fl);
    return 1;
}

//Output obtain on executing above program multiple times
//  At present tno is : 49
//New tno obtained is : 50
//At present tno is : 50
//New tno obtained is : 51 and so on
