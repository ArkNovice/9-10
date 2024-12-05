#include<stdio.h>
#include<errno.h>
#include<io.h>
#include<fcntl.h>
#include<string.h>
#define FILENAME "test.bin"
#define MAX_STRING_LENGTH 3
int WriteData(int fh, void* buf, int len);
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
	memset(&block, 0, sizeof(block));
	block.i=100;
	block.f=100.0;
	strcpy(block.string, "100");
	strcpy(block.end, "END");
	fh=open(FILENAME,O_WRONLY|O_CREAT|O_TRUNC|O_BINARY, 0666);
	if(fh==-1)
	{
		perror(FILENAME);
		return -1;
	}
	rtn=WriteData(fh, &block, sizeof(block));
	if(rtn<0)
	{
		perror(FILENAME);
		return -1;
	}
	close(fh);
	return-1;
}
int WriteData(int fh, void* buf, int len)
{
	int written=0;
	int val;
	while(written<len)
	{
		val=write( fh, ((char*)buf)+written, len-written);
		if(val==-1)
		{
			return val;
		}
		written +=val;
	}
	return written;
}
