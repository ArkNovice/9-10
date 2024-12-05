#include <stdio.h>
int CopyFile (const char* srcName, const char* dstName);
int main()
{
	char srcFilename[FILENAME_MAX]; 
	char dstFilename[FILENAME_MAX]; 
	printf("The source filename: ");
	scanf("%s", srcFilename);
	printf("The destination filename: ");
	scanf("%s", dstFilename);

	if (CopyFile(srcFilename, dstFilename))
	{
    	printf("Copy succeeded.\n");
    	return 0;
	}
	else
	{
		perror("Copy failed: ");
    	return -1;
	}
}
int CopyFile(const char* srcName, const char* dstName)
{
    FILE* fpSrc = NULL;
    FILE* fpDst = NULL;
    int ch, rval = 1;
    fpSrc = fopen(srcName, "rb");
    if (fpSrc == NULL)
    {
        goto ERROR;
    }
    fpDst = fopen(dstName, "wb");
    if (fpDst == NULL)
    {
        goto ERROR;
    }
    while ((ch = fgetc(fpSrc)) != EOF)
    {
        if (fputc(ch, fpDst) == EOF)
        {
            goto ERROR;
        }
        fflush(fpDst);
    }
    goto EXIT;

ERROR:
    rval = 0;

EXIT:
    if (fpSrc != NULL)
    {
        fclose(fpSrc);
    }
    if (fpDst != NULL)
    {
        fclose(fpDst);
    }
    return rval;
}

