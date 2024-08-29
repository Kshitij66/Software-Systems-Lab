//Kshitij Tiwari MT2024080
//Lab16
// program to implement read and write lock 
#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>

void lo_set(int fide, int lo_type) {
    struct flock lock;

    lock.l_type = lo_type;          
    lock.l_whence = SEEK_SET;    
    lock.l_start = 0;              
    lock.l_len = 0;                   
    lock.l_pid = getpid();      

 
    if (fcntl(fide, F_SETLKW, &lock) == -1)
    {
        perror("problem in setting the lock");
       
    }
    printf("lock has been set by the process  %d\n", getpid());
}

void re_lock(int fide) {
    struct flock lock;

  
    lock.l_type = F_UNLCK;          
    lock.l_whence = SEEK_SET;
    lock.l_start = 0;
    lock.l_len = 0;
    lock.l_pid = getpid();

    
    if (fcntl(fide, F_SETLK, &lock) == -1)
    {
        perror("problem in releasing the lock");
        
    }
    printf("lock has been released by process %d\n", getpid());
}

int main() 
{
    int fide;
    const char *fi_path = "newFile.txt";

    fide = open(fi_path, O_RDWR);
    if (fide == -1) 
    {
        perror("can't open the file");
       
    }

    lo_set(fide, F_WRLCK);
    printf("start writing to the file \n");
    write(fide, "we are working on this\n", strlen("we are working on this\n"));
    sleep(15);
    re_lock(fide);

    lo_set(fide, F_RDLCK);
    printf("start reading from the file \n");
    char buffer[200];
    lseek(fide, 0, SEEK_SET);  //this will reset the cursor to the beginning
    read(fide, buffer, sizeof(buffer));
    printf("read the specified content  %s\n", buffer);
    sleep(15);  
    re_lock(fide);

   
    close(fide);
    return 0;
}
//Output :- First we implement read lock in one terminal it will hold the lock for specified seconds and on implementing read lock in another terminal it will be allowed and they will also hold the lock/
//But for write lock if one terminal is holding the lock for specified seconds then another terminal will not be allowed to enter the file as well as hold the lock

