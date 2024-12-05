#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
#include<string.h>
#define FILENAME "test.bin"
#define MAX_STRING_LENGTH 3
int ReadData(int fh, void* buf, int len);
struct data
{
	int i;
	float f;
	char string[MAX_STRING_LENGTH+1];
	char end[4];
};
int main()
{
	struct data block;
	int fh, rtn;
	fh=open(FILENAME, O_RDONLY|O_BINARY);
	if(fh==-1)
	{
		perror(FILENAME);
		return -1;
	}
	rtn=ReadData(fh, &block, sizeof(block));
	if(rtn<0)
	{
		perror(FILENAME);
		close(fh);		return -1;
	}
	printf("The int is %d\n", block.i);
	printf("The float is %f\n", block.f);
	printf("The string is %s\n", block.string);
	printf("The end is %s\n", block.end);
	close(fh);
	return 0;
}
int ReadData(int fh, void* buf, int len)
{
	int readBytes = 0;
	int val;
	while(readBytes<len)
	{
		val=read(fh, ((char*)buf)+readBytes, len-readBytes);
		if(val==-1)
		{
			return val;
		}
		else if(val !=0)
		{
			readBytes += val;
		}
	}
	return readBytes;
}
