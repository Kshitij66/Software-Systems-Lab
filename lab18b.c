//Kshitij Tiwari MT2024080
//program to implement write lock on three records created in previous program
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

typedef struct {
    int jerseyno;
    char cricname[15];
    int age;
} Record;

void w_lock(int fide, int stats_no) {
    struct flock lock;
    lock.l_type = F_WRLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = stats_no * sizeof(Record);
    lock.l_len = sizeof(Record);

    if (fcntl(fide, F_SETLKW, &lock) == -1) 
    {
        perror("problem while implementing write lock");
   
    }
}

void unlock(int fide, int stats_no) {
    struct flock lock;
    lock.l_type = F_UNLCK; 
    lock.l_whence = SEEK_SET;
    lock.l_start = stats_no * sizeof(Record);
    lock.l_len = sizeof(Record);

    if (fcntl(fide, F_SETLK, &lock) == -1)
    {
        perror("problem while unlocking the record");
    }
}

int main() 
{
    int fide = open("plstats.dat", O_RDWR);

    int stats_no = 1; 
    w_lock(fide, stats_no);

    Record plstats;
    lseek(fide, stats_no * sizeof(Record), SEEK_SET);
    read(fide, &plstats, sizeof(Record));

    strcpy(plstats.cricname, "SteveSmith Updated");
    plstats.age = 26;

  
    lseek(fide, stats_no * sizeof(Record), SEEK_SET);
    write(fide, &plstats, sizeof(Record));
    printf("record %d updated to : %s, %d\n", plstats.jerseyno, plstats.cricname, plstats.age);

    unlock(fide, stats_no);

    close(fide);
    return 1;
}

//Output:- write lock has been implemented age of 2nd record has been modified
//record 49 updated to : SteveSmith Update, 26

