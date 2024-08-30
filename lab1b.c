//Kshitij Tiwari MT2024080
//Program for the creation of hardlink using link system call 
#include<unistd.h>
#include<stdio.h>

int main()
{
	if(link("shell1.sh","hardlink1")==-1)
	{
		perror("problem in creating the hardlink");
	}
	return 0;
}

//Output:-On compiling and executing the program and after that if we use "ls" command to list out the files then we will observe a "hardlink1" present in list of files and if we obtain the contents of hardlink1 it will be same as shell1.sh to which it is linked.
