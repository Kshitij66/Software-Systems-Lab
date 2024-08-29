//Kshitij Tiwari MT2024080
//program to wait for stdin for ten seconds and verify if the data is available within ten seconds
#include <stdio.h>
#include <stdlib.h>
#include <sys/select.h>
#include <unistd.h>

int main() 
{
    fd_set readfds;
    struct timeval timeout;
    int rval;

    FD_ZERO(&readfds);//clear the fds set
    
    FD_SET(STDIN_FILENO, &readfds);

    timeout.tv_sec = 10;//timeout has been set for 10 seconds
    timeout.tv_usec = 0;

    rval = select(STDIN_FILENO + 1, &readfds, NULL, NULL, &timeout);//input on standard fd for input 0

    if (rval == -1) 
    {
        perror("data is not available to read now");
    } 
    else if (rval)
    {
        printf("Data is available now.\n");

        char buff[100];                           //in another way we can read the data here
        read(STDIN_FILENO, buff, sizeof(buff));
        printf("data to be entered: %s\n", buff);
    } 
    else
    {
        printf("No data has arrived within 10 seconds \n");
    }

    return 0;
}

//Output:-If leave the program running without enter then :- No data has arrived within 10 seconds 
//If enter then :-Data is available now.data to be entered:
 
 
