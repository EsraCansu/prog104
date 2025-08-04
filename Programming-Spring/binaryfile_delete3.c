/* Write a C program to delete the last 100 bytes of  a binary file*/
#include <stdio.h>
#include <io.h>

main()
{
	char source_file_name[100],target_file_name[100];
	unsigned char buffer[100];//byte
	long int file_length,written_bytes,read_bytes;
	
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
		read_bytes=fread(buffer,sizeof(unsigned char),sizeof(buffer),source_file);
		written_bytes=written_bytes+read_bytes;
		if (written_bytes>file_length-100)
		   read_bytes=read_bytes-(written_bytes-(file_length-100));
		fwrite(buffer,sizeof(unsigned char),read_bytes,target_file);		
	}
	fclose(source_file);
	fclose(target_file);	
	remove(source_file_name);
	rename(target_file_name,source_file_name);
}
