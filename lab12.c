//Kshitij Tiwari MT2024080
//program to find out the opening mode of a file using fcntl
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>

void obtainfile_mode(int fide) 
{
    int fl = fcntl(fide, F_GETFL);  //F_GETFL command to obtain opening mode of file retrieves status flag 

    int access_mode = fl & O_ACCMODE; //masking other bits so only opening mode will be visible

    printf("FIDE %d is opened in ", fide);
    switch (access_mode) {
        case O_RDONLY:
            printf("read only mode \n");
            break;
        case O_WRONLY:
            printf("write only mode \n");
            break;
        case O_RDWR:
            printf("read write mode \n");
            break;
        default:
            printf("unrecognized mode \n");
            break;
    }

    if (fl & O_APPEND) {
        printf("The file is opened in append mode \n");
    }
    if (fl & O_NONBLOCK) {
        printf("The file is opened in non-blocking mode \n");
    }
    if (fl & O_SYNC) {
        printf("The file is opened in synchronous mode \n");
    }
    if (fl & O_CREAT) {
        printf("The file was opened with the O_CREAT flag \n");
    }
    if (fl & O_TRUNC) {
        printf("The file was opened with the O_TRUNC flag \n");
    }
    if (fl & O_EXCL) {
        printf("The file was opened with the O_EXCL flag \n");
    }
}

int main() {
    const char *filename = "newFile.txt";
    
    int fide = open(filename, O_RDWR | O_CREAT | O_APPEND, 0644);//opening of file in read write mode

    obtainfile_mode(fide);

    close(fide);

    return 0;
}

//Output:- FIDE 3 is opened in read write mode 
//The file is opened in append mode 

