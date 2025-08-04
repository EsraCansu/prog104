/* Write a C program to delete the first 100 bytes of  a binary file*/
#include <stdio.h>

main()
{
	char source_file_name[100],target_file_name[100];
	unsigned char buffer[1000];
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
	fseek(source_file,100,SEEK_SET);
	
	while(!feof(source_file))
	{
		fread(buffer,sizeof(buffer),1,source_file);
		fwrite(buffer,sizeof(buffer),1,target_file);
	}
	fclose(source_file);
	fclose(target_file);	
	remove(source_file_name);
	rename(target_file_name,source_file_name);
}
