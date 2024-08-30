//Kshitij Tiwari MT2024080
//program to open a file in read only mode, read line by line and display each line as it is being read at the end close the file

#include <stdio.h>
#include <stdlib.h>

int main()
{
    FILE *fl;
    char *l = NULL;
    size_t len = 0;
    ssize_t read;

    fl = fopen("testData.txt", "r");//open the file in readonly mode
    if (fl == NULL) 
    {
        perror("Problem in opening the file");
    }

    while ((read = getline(&l, &len, fl)) != -1) //To read and display each line
    {
        printf("%s", l);
    }

    free(l);
    fclose(fl);

    return 0;
}

//Output obtained is :- Kshitij Tiwari Here
//Studying In IIITB
//Originally from Varanasi

