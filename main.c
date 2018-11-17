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
    unsigned char *buffer = (unsigned char *)malloc(30000); //initializing with a memory space of 30KB
    bzero(buffer, 30000);
    char **loopStart = (char **)malloc(sizeof(char **) * 100);
    FILE *in = NULL;
    in = fopen(argv[1], "r"); //opening for reading
    if(in == NULL)
        exit(EXIT_UNABLE_TO_OPEN_FILE);
    fseek(in, 0, SEEK_END); //to find out the size of the file, in turn to allocate buffer
    long filesize = ftell(in);
    fseek(in, 0, SEEK_SET);
    char *program = (char *)malloc(filesize+1); //allocating memory for the file in program buffer, will also act as program counter
    bzero(program, filesize + 1); //initializing as 0, why not
    fread(program, 1, filesize,in); //reads the file into program buffer
    fclose(in); //closing file
    //at this point the program is loaded into the program buffer, and the file is closed
    putchar('\n'); //newline for clarity
    while(*program != 0)
    {
//        printf("%c", *program);
        switch(*program)
        {
        case '>' :
            buffer++;
            break;
        case '<' :
            buffer--;
            break;
        case '+' :
            ++(*buffer);
            break;
        case '-' :
            --(*buffer);
            break;
        case '.' :
            putchar(*buffer);
            break;
        case ',' :
            *buffer = getchar();
            break;
        case '[' :
            *(loopStart++) = program;
            break;
        case ']' :
            if(*buffer != 0)
                program = *(loopStart - 1);
            else
                *(--loopStart) = 0;
            break;
        }
        program++;
    }
    putchar('\n');

}
