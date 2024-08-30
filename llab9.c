//Kshitij Tiwari MT2024080
//program to print certain information about file like inode,no of hard links,gid,uid,size,blocksize,no of block,time of last access,time of last modification,time of last change
#include<stdio.h>
#include<stdlib.h>
#include<sys/stat.h>
#include<unistd.h>
#include<time.h>

void required_info(const char *sourceFile)
{
        struct stat f_stat;
        if(stat(sourceFile, &f_stat)!=0)
        {
                perror("Problem in retrieving fileinfo");
        }


        printf("Inode of file:%ld\n",(long) f_stat.st_ino);
        printf("no of hard links in given file:%ld\n",(long) f_stat.st_nlink);
        printf("UID of the file:%u\n",f_stat.st_uid);
        printf("GID of the file:%u\n",f_stat.st_gid);
        printf("Size of the file:%ld bytes\n",(long)f_stat.st_size);
        printf("Block size of file:%ld bytes\n",(long)f_stat.st_blksize);
        printf("Number of blocks:%ld\n",(long)f_stat.st_blocks);
        printf("TIme of last access:%s\n",ctime(&f_stat.st_atime));
        printf("TIme of last modification:%s\n",ctime(&f_stat.st_mtime));
        printf("Time of last  change:%s\n",ctime(&f_stat.st_ctime));
}

        int main(int argc,char *argv[])
        {
        required_info(argv[1]);

        return 0;
        }


//Output of the above program obtained is :-Inode of file:64
//no of hard links in given file:8
//UID of the file:0
//GID of the file:2048
//Size of the file:32768 bytes
//Block size of file:14680064 bytes
//Number of blocks:14680064
//TIme of last access:Sun Jan 25 12:02:32 2024

//TIme of last modification:Tue Apr 22 07:00:32 4461321

//Time of last  change:Thu Jan  1 05:30:00 2024

