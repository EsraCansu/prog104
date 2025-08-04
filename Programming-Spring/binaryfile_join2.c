/* Write a C program to join two binary files*/
/* file1=file1+file2*/
#include <stdio.h>

main()
{
	char file_name1[100],file_name2[100];
	unsigned char buffer[100];//byte
	long int file_length,written_bytes,read_bytes;
	
	FILE * file1, * file2,* temp_file;
	printf("file1:");	
	gets(file_name1);
	
	printf("file2:");	
	gets(file_name2);
	
	file1=fopen(file_name1,"rb");
	if (file1==NULL)
	{
		printf ("we cannot open the first file \n");
		exit(1);
	}
	file2=fopen(file_name2,"rb");
	if (file2==NULL)
	{
		printf ("we cannot open the second file \n");
		exit(1);
	}
	temp_file=fopen("$$temp$$.dat","wb");
	if (temp_file==NULL)
	{
		printf ("we cannot write the temp file \n");
		exit(0);
	}
		
	while(!feof(file1))
	{
		read_bytes=fread(buffer,sizeof(unsigned char),sizeof(buffer),file1);		
		fwrite(buffer,sizeof(unsigned char),read_bytes,temp_file);		
	}
	while(!feof(file2))
	{
		read_bytes=fread(buffer,sizeof(unsigned char),sizeof(buffer),file2);		
		fwrite(buffer,sizeof(unsigned char),read_bytes,temp_file);		
	}
	fclose(file1);
	fclose(file2);
	fclose(temp_file);	
	remove(file_name1);
	rename("$$temp$$.dat",file_name1);
}
