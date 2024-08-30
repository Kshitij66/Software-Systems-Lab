//Kshitij Tiwari MT2024080
//Softlink creation using symlink system call
#include<stdio.h>
#include<unistd.h>

int main()
{
	if(symlink("shell1.sh","solink")==-1)
	{
		perror("problem in creating the softlink");
	}
	return 0;
}

//Output:-On compiling and executing the program and after that if we use "ls" command to list out the files then we will observe a "solink" present in list of files and if we obtain the contents of solink it will be same as shell1.sh to which it is linked.
 
