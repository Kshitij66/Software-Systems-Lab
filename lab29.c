#include <stdio.h>
#include <stdlib.h>
#include <sched.h>
#include <unistd.h>
#include <string.h>
#include <errno.h>

void p_schedpolicy(int ply)
{
    switch(ply)
    {
        case SCHED_OTHER:
            printf("Obtained Scheduling Policy is SCHED_OTHER\n");
            break;
        case SCHED_FIFO:
            printf("Obtained Scheduling Policy is SCHED_FIFO\n");
            break;
        case SCHED_RR:
            printf("Obtained Scheduling Policy is SCHED_RR\n");
            break;
        default:
            printf("Obtained Scheduling Policy is unrecognisable \n");
            break;
    }
}

int main(int argc, char *argv[]) {
    int ply;
    struct sched_param param;

    ply = sched_getscheduler(0); 
    if (ply == -1)
    {
        perror("can't be obtained");
    }

    p_schedpolicy(ply);

    if (argc > 1)
    {
        if (strcmp(argv[1], "fifo") == 0) 
	{
            ply = SCHED_FIFO; //set scheduling policy to FIFO
        
        }
       	else if (strcmp(argv[1], "rr") == 0) 
	{
            ply = SCHED_RR;//set scheduling policy to RR
        } 
	else
       	{
            fprintf(stderr, "Usage: %s [fifo|rr]\n", argv[0]);
        }

        param.sched_priority = 1;
        if (sched_setscheduler(0, ply, &param) == -1)
       	{
            perror("can't be set ");
        }

        p_schedpolicy(sched_getscheduler(0));
    }

    return 0;
}

//Output:- sudo ./lab29.out fifo 
//Obtained Scheduling Policy is SCHED_OTHER
//Obtained Scheduling Policy is SCHED_FIFO


