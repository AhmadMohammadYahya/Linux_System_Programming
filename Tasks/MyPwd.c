/*
pwd: print working directory (check `man getcwd`).
*/

#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


#define CHAR_COUNT 1000
int main()
{
    char Buf_PWD[CHAR_COUNT] ;
    getcwd(Buf_PWD, CHAR_COUNT);

    if (write(1, Buf_PWD, strlen(Buf_PWD)) < 0)
    {
        printf("Error writing to Std_Out");
        exit(-1);
    }

    return 0;
}