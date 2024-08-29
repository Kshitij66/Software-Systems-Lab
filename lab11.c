//Kshitij Tiwari MT2024080
//open the file and duplicate the file descriptor append and check if file is updated correctly or not
#include<stdio.h>
#include<unistd.h>
#include<fcntl.h>
#include<stdlib.h>
#include<string.h>

void file_details(const char *filename)
{
 FILE *file=fopen(filename,"r");

    if (file == NULL)
    {
        perror("problem in opening the file");
        
    }

    printf("details of the file provided:\n");
    char c;
    while ((c = fgetc(file)) != EOF)
    {
        putchar(c);
    }
    fclose(file);
}




int main()
{
const char *filename="newFile.txt";
int fide1,fide2,fide3,fide4;
fide1=open(filename, O_RDWR|O_APPEND|O_CREAT,0644);//opening the file and obtaining a file descriptor
if(fide1<0)
{
	perror("problem in opening the file");
	return 1;
}
fide2=dup(fide1);//duplicating the original fide using dup()
if(fide2<0)
{
	perror("problem in duplicating fide using dup");
	return 1;
}
fide3=dup2(fide1,fide2+1);//duplicating the original fide using dup2()
if(fide3<0)
{
	perror("problem in duplicating fide using dup2");
	return 1;
}
fide4= fcntl(fide1,F_DUPFD,fide2+2);//duplicating the original fide using fcntl()
if(fide4<0)
{
	perror("problem in duplicating fide uding fcntl");
	return 1;
}

    //writing with the help dupicate fide obtained through dup,dup2 and fcntl function
    const char *value1 ="Please write something using fide1\n";
    if (write(fide1, value1, strlen(value1)) < 0)
{
        perror("problem in writing  using fide1");
        return 1;
}


    const char *value2 = "Please write something using fide2\n";
    if (write(fide2, value2, strlen(value2)) < 0)
{
        perror("problem in writing  using fide2");
        return 1;
}


    const char *value3 = "Please write something using fide3\n";
    if (write(fide3, value3, strlen(value3)) < 0)
{
        perror("problem in writing using fide3");
        return 1;
}

    
    const char *value4 = "Please write something using fide4\n";
    if (write(fide4, value4, strlen(value4)) < 0)
{
        perror("Problem in writing using fide4");
        return 1;
}

    
    close(fide1);
    close(fide2);
    close(fide3);
    close(fide4);

 
    file_details(filename);

    return 0;
}
//Output:- details of the file provided:
//we are working on this
//using fide1
//Please write something using fide2
//Please write something using fide3
//Please write something using fide4



