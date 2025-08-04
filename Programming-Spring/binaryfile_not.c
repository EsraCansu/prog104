/* Write a C program to change the bytes of  a binary file 
   by NOT bit operation */
#include <stdio.h>

main()
{
	char source_file_name[100],target_file_name[100];
	unsigned char buffer[1000];
	int read_bytes,i;
	FILE * source_file, * target_file;
	printf("source file:");
	gets(source_file_name);
	
	source_file=fopen(source_file_name,"rb");
	if (source_file==NULL)
	{
		printf ("we cannot open the source file \n");
		exit(1);
	}
	target_file=fopen("$$temp$$.bin","wb");
	if (target_file==NULL)
	{
		printf ("we cannot write the target file \n");
		exit(0);
	}
	while(!feof(source_file))
	{
		read_bytes=fread(buffer,sizeof(unsigned char),sizeof(buffer),source_file);
		for (i=0;i<read_bytes;i++)
		   buffer[i]=~buffer[i];
		fwrite(buffer,sizeof(unsigned char),read_bytes,target_file);
	}
	fclose(source_file);
	fclose(target_file);
	remove(source_file_name);
	rename("$$temp$$.bin",source_file_name);		
}
