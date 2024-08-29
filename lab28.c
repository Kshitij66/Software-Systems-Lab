//Kshitij Tiwari MT2024080
//program to get max and min real time priorities
#include <stdio.h>
#include <sched.h>

int main() 
{
    int high_pty, low_pty;

    high_pty = sched_get_priority_max(SCHED_RR);//we are getting min max priorities for round robin scheduling..we can also get for other scheduling algo
    low_pty = sched_get_priority_min(SCHED_RR);

    if (high_pty < 0 || low_pty < 0)
    {
        perror("sched max min priority could n't be extracted");
        return 1;
    }

    printf("Maximum real-time priority for SCHED_RR: %d\n", high_pty);
    printf("Minimum real-time priority for SCHED_RR: %d\n", low_pty);


    return 0;
}

//Output:- Maximum real-time priority for SCHED_RR: 99
//Minimum real-time priority for SCHED_RR: 1

