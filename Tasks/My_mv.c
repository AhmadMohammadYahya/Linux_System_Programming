/*
mv: move a file to another place (might be with different name). For example,
mv /tmp/file.txt /tmp/new_name.txt
mv /tmp/file.txt /home/reda/new_name.txt
mv /tmp/file.txt /home/reda/file.txt
This is a simple version of Unix mv program that supports only moving files to an explicit destination as in the examples.
*/


#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>


#define CHAR_COUNT 100

int main(int argc, char* argv[])
{
    int fd_SrcFile, fd_DstFile;
    char Buf_SrcFile[CHAR_COUNT];

    if (argc != 3)
    {
        printf("Usage: %s SrcFile DstFile\n", argv[0]);
        exit(-2);
    }

    // opening SrcFile with RDONLY Flag option to be able to read from it
    if((fd_SrcFile = open(argv[1], O_RDONLY)) < 0)
    {
        printf("Error openning SrcFile\n");
        exit(-3);
    }

    // opening DstFile with Create Flag to create it if it doesn't exist, with RDWR options to be able to read and write it
    if((fd_DstFile = open(argv[2], O_RDWR | O_CREAT, 0644)) < 0)
    {
        printf("Error openning DestFile\n");
        exit(-4);
    }

    // read SrcFile
    while(read(fd_SrcFile, Buf_SrcFile, CHAR_COUNT) > 0)
    {
        // write to DstFile
        if(write(fd_DstFile, Buf_SrcFile, strlen(Buf_SrcFile)) < 0)
        {
            printf("Error openning DestFile\n");
            exit(-5);    
        }

    }

    //Delete SrcFile
    if(unlink(argv[1]) < 0)
    {
        printf("Error Deleting SrcFile\n");
        exit(-6);   
    }

    // Closing src aand Dst Files
    if(close(fd_DstFile) < 0 )
    {
        printf("Error Closing SrcFile or DestFile or Both\n");
        exit(-7);
    }
    
}