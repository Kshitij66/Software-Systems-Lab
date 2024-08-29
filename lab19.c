//Kshitij Tiwari Roll-MT2024080 
//program to obtain time taken in order to execute getpid system call
#include <stdio.h>
#include <unistd.h>


unsigned long long rdtsc() //to read the time stamp counter
{
    unsigned int lower, higher;
    __asm__ __volatile__ ("rdtsc":"=a"(lower),"=d"(higher)); 
    return ((unsigned long long)higher << 32) | lower;
}

int main()
{
    unsigned long long begin, stop;//unsigned long long is required to store 64-bit timestamp counter
    
    begin = rdtsc();//read the timestamp counter before calling getpid() 
    getpid();
    stop = rdtsc();//read the timestamp counter after calling getpid()
    
    printf("In order to obtain process id %llu is amount of clock cycles required \n", stop - begin);
    
    return 0;
}
//Output:- In order to obtain process id 9841 is amount of clock cycles required
