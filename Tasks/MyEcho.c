/*
echo: print a user input string on stdout (for example: `echo Hello World`).
*/
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define CHAR_COUNT 30

int main(int argc, char *argv[])
{
    for(int i = 1; i < argc; i++)
    {
        if (write(1, argv[i], strlen(argv[i])) < 0)
        {
            printf("Write Error\n");
            exit(-2);
        }
        write(1, " ", 1);

    }
    return 0;
}