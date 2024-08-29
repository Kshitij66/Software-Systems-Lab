//Kshitij Tiwari MT2024080
//program to create five new files with infinite loop execute them in background
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

int main() 
{
    int fide[5];
    char fname[20];

    for (int i = 0; i < 5; i++)
    {
        snprintf(fname, sizeof(fname), "newFile%d.txt", i+1);
        fide[i] = open(fname, O_WRONLY | O_CREAT | O_TRUNC, 0644);//open the file with respective file descriptors
        if (fide[i] == -1)
       	{
            perror("problem in creating file");
            return 1;
        }
        printf("File has been created: %s with fide: %d\n", fname, fide[i]);
    }

    while (1)//infinite loop to keep programs running
    {
        sleep(1);
    }

    for (int i = 0; i < 5; i++)
    {
        close(fide[i]);
    }

    return 0;
}

//Output :-  File has been created: newFile1.txt with fide: 3
//File has been created: newFile2.txt with fide: 4
//File has been created: newFile3.txt with fide: 5
//File has been created: newFile4.txt with fide: 6
//File has been created: newFile5.txt with fide: 7
// On running command to check file descriptor table we got
// 0 -> /dev/pts/0
//lrwx------ 1 kshitij kshitij 64 Aug 29 23:38 1 -> /dev/pts/0
//lrwx------ 1 kshitij kshitij 64 Aug 29 23:38 2 -> /dev/pts/0
//l-wx------ 1 kshitij kshitij 64 Aug 29 23:38 3 -> /home/kshitij/newFile1.txt
//l-wx------ 1 kshitij kshitij 64 Aug 29 23:38 4 -> /home/kshitij/newFile2.txt
//l-wx------ 1 kshitij kshitij 64 Aug 29 23:38 5 -> /home/kshitij/newFile3.txt
//l-wx------ 1 kshitij kshitij 64 Aug 29 23:38 6 -> /home/kshitij/newFile4.txt
//l-wx------ 1 kshitij kshitij 64 Aug 29 23:38 7 -> /home/kshitij/newFile5.txt

