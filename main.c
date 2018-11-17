#define EXIT_FILE_NOT_PROVIDED 2
#define EXIT_UNABLE_TO_OPEN_FILE 1
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char * argv[])
{
    if(argc == 1) //if no file name is given
    {
        printf("\n%s [filename]\n", argv[0]);
        exit(EXIT_FILE_NOT_PROVIDED);
    }
    char *buffer = (char *)malloc(30000); //initializing with a memory space of 30KB
    bzero(buffer, 30000); //initializes the memory space as all 0
    FILE *in = NULL;
    in = fopen(argv[1], "r"); //opening for reading
    if(in == NULL)
        exit(EXIT_UNABLE_TO_OPEN_FILE);
    fseek(in, 0, SEEK_END); //to find out the size of the file, in turn to allocate buffer
    long filesize = ftell(in);
    fseek(in, 0, SEEK_SET);
    char *program = (char *)malloc(filesize); //allocating memory for the file in program buffer
    bzero(program, filesize); //initializing as 0, why not
    while((*program++ = fgetc(in)) != EOF); //copies all bytes of the file into program buffer
    fclose(in); //closing file
    program -= filesize;
    program(*(++)
    //at this point the program is loaded into the program buffer, and the file is closed


}
