//Kshitij Tiwari Roll-MT2024080
//Lab14 
//Identify the file type for the given input file provided through command line

#include <stdio.h>
#include <stdlib.h>
#include <magic.h>

int main(int argc, char *argv[])
{
 
    if (argc != 2)
    {
        fprintf(stderr, "Usage: %s <filename>\n", argv[0]);
        return 1;
    }

    
    magic_t magic = magic_open(MAGIC_NONE);//MAGIC_NONE signifies default behaviour for the given call

    if (magic_load(magic, NULL) != 0) 
    {
        fprintf(stderr, "unable to load magic database: %s\n", magic_error(magic));
        magic_close(magic);
        return 1;
    }

    // 
    const char *f_type = magic_file(magic, argv[1]);//identify the file type for the input file
    if (f_type == NULL) {
        fprintf(stderr, "unrecognisable file type: %s\n", magic_error(magic));
        magic_close(magic);
        return 1;
    }

    printf("File type which is obtain: %s\n", f_type);

    magic_close(magic);
    return 0;
}


