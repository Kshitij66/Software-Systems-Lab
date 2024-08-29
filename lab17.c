//Kshitij Tiwari MT2024080
//program to open a file and initially store the ticketno
#include <stdio.h>
#include <stdlib.h>

int main() {
    FILE *fl = fopen("storeTno.txt", "w");
    if (fl == NULL)
    {
        perror("problem in opening the file");
  
    }

    int t_no = 49; 
    fprintf(fl, "%d\n", t_no);
    fclose(fl);

    printf("Initially a tno %d is stored \n", t_no);
    return 1;
}

//Output obtained is :-Initially a tno49 is stored 


