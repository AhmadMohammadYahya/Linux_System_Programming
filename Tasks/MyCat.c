#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define COUNT 1000

int main (int argc, char * argv[])
{
	if (argc != 2)
	{
		printf("Usage: %s filename\n", argv[0]);
		exit(-3);
	}
	int Buf[COUNT];
	int fd = open(argv[1], O_RDONLY);
	if(fd < 0)
	{
		printf("couldn't open");
		exit(-2);
	}
	
	int size;
	while ((size = read(fd, Buf, COUNT)) > 0)
	{

		if(write(1, Buf, size) < 0)
		{
			printf("Write Failure");
			exit(-4);
		}
	}


	int close_result = close(fd);
	if(close_result < 0)
	{
		printf("CLose failure");
		exit(-5);
	}



}
