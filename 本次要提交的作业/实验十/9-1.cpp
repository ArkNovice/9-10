#include<stdio.h>
#include<errno.h>
#include<fcntl.h>
int main()
{
	int fh = open("C:\\abc.abc", O_RDONLY | O_BINARY);
	if(fh==-1)
	{
		perror("Can't open C:\\abc.abc. Error");
		return -1;
	}
	return 0;
 } 
