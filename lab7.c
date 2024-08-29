//Kshitij Tiwari MT2024080
//program to copy file1 to file2
#include<stdlib.h>

int main()
{
  const	char *comm = "cp sourceFile DesFile";//copy the contents of sourcefile in destination file
  int final = system(comm);//system call will help us execute above command directly within program

  return 0;

}

//Output :- data in sourcefile :- Kshitij Tiwari here
//          data in Desfile :- Kshitij Tiwari here


