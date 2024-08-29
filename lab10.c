//Kshitij Tiwari MT2024080
//program to open a file in read write mode first write ten bytes move the pointer by ten bytes and then write again
#include<stdio.h>
#include<stdlib.h>
#include<fcntl.h>
#include<unistd.h>
#include<string.h>

#define FILE_NAME "sourceFile"
#define Write1 "KshitijTiw"
#define Write2 "JosephRoot"
#define Length 10

int main()
{
	int fide;
	off_t offsetvalue;
	ssize_t writtenv;

	fide=open(FILE_NAME,O_RDWR|O_CREAT|O_TRUNC,0644);//open the file in read write mode
	
	writtenv=write(fide,Write1,Length);//write ten bytes as defined in Length part

	offsetvalue=lseek(fide,10,SEEK_CUR);//moving the file pointer by ten byte
	if (offsetvalue == (off_t)-1)
       	{
        perror("problem in seeking in the given file");
        close(fide);
        return 1;
        } 
	else
       	{
        printf("lseek was successfull and  new offset is: %ld\n", (long)offsetvalue);
        }				    
       
       	writtenv=write(fide,Write2,Length);//writing again ten byte
       close(fide);
      printf("All modifications are done correctly");
}

//Output :- lseek was successfull and  new offset is: 20
//All modifications are done correctly
//On opening the file in od(octal dump) and checking for empty spaces we obtained
//0000000   K   s   h   i   t   i   j   T   i   w  \0  \0  \0  \0  \0  \0
0000020  \0  \0  \0  \0   J   o   s   e   p   h   R   o   o   t
0000036

