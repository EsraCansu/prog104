/* Write a C program to delete the bytes between  100-199 offset of  a binary file*/
/* 0..99 100..199 200...*/
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
	//write first 100 bytes
	read_bytes=fread(buffer,sizeof(unsigned char),sizeof(buffer),source_file);		
	fwrite(buffer,sizeof(unsigned char),read_bytes,target_file);
	//skip next 100 bytes
	fseek(source_file,200,SEEK_SET);
	while(!feof(source_file))
	{
		read_bytes=fread(buffer,sizeof(unsigned char),sizeof(buffer),source_file);		
		fwrite(buffer,sizeof(unsigned char),read_bytes,target_file);		
	}
	fclose(source_file);
	fclose(target_file);	
	remove(source_file_name);
	rename(target_file_name,source_file_name);
}
