//Kshitij Tiwari MT2024080
//program for the creation of three records
#include <stdio.h>
#include <stdlib.h>

typedef struct 
{
    int jerseyno;
    char cricname[15];
    int age;
} Record;

int main()
{
    FILE *fl = fopen("plstats.dat", "wb");
    
    Record plstats[3] = {
        {66, "JoeRoot", 33},
        {49, "SteveSmith", 34},
        {33, "Cummins", 31}
    };

    fwrite(plstats, sizeof(Record), 3, fl);
    fclose(fl);
    printf("Stats recorded \n");

    return 1;
}
//Output :- This will create three records in plstats.dat file
