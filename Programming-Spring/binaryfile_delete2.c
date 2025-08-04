/* Write a C program to delete the last 100 bytes of  a binary file*/
#include <stdio.h>
#include <io.h>

main()
{
	char source_file_name[100],target_file_name[100];
	unsigned char buffer[1];
	long int file_length,written_bytes;
	
	FILE * source_file, * target_file;
	printf("source file:");	
	gets(source_file_name);
	strcpy(target_file_name,"$$temp$$.dat");
	source_file=fopen(source_file_name,"rb");
	if (source_file==NULL)
	{
		printf ("we cannot open the source file \n");
		exit(1);
	}
	target_file=fopen(target_file_name,"wb");
	if (target_file==NULL)
	{
		printf ("we cannot write the target file \n");
		exit(0);
	}
	file_length=filelength(fileno(source_file));
	
	written_bytes=0;
	while(written_bytes<file_length-100)
	{
		fread(buffer,sizeof(buffer),1,source_file);
		fwrite(buffer,sizeof(buffer),1,target_file);
		written_bytes++;
	}
	fclose(source_file);
	fclose(target_file);	
	remove(source_file_name);
	rename(target_file_name,source_file_name);
}
