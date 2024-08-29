//Kshitij Tiwari MT2024080
//program to implement read lock on the records
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

typedef struct {
    int jerseyno;
    char cricname[15];
    int age;
} Record;

void r_lock(int fide, int stats_no)
{
    struct flock lock;
    lock.l_type = F_RDLCK;  
    lock.l_whence = SEEK_SET;
    lock.l_start = stats_no * sizeof(Record);
    lock.l_len = sizeof(Record);

    if (fcntl(fide, F_SETLKW, &lock) == -1)
    {
        perror("problem in implementing read lock");
        
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
        perror("problem in  unlocking the record");
   
    }
}

int main() {
    int fide = open("plstats.dat", O_RDONLY);

    int stats_no = 2; 
    r_lock(fide, stats_no);

    Record plstats;
    lseek(fide, stats_no * sizeof(Record), SEEK_SET);
    read(fide, &plstats, sizeof(Record));

    printf("records obtained %d: %s, %d\n", plstats.jerseyno, plstats.cricname, plstats.age);

   
    unlock(fide, stats_no);

    close(fide);
    return 1;
}
//Output :- Read lock has been implemented 
// 3rd record has been obtained with all it's description 

