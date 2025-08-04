/* Write a C program to copy a text file to a target file */
#include <stdio.h>

main()
{
	char source_file_name[100],target_file_name[100];
	char line[100];
	char c;
	FILE * source_file, * target_file;
	printf("source file:");
	gets(source_file_name);
	printf("target file:");
	gets(target_file_name);
	source_file=fopen(source_file_name,"r");
	if (source_file==NULL)
	{
		printf ("we cannot open the source file \n");
		exit(1);
	}
	target_file=fopen(target_file_name,"w");
	if (target_file==NULL)
	{
		printf ("we cannot write the target file \n");
		exit(0);
	}
	while(1)
	{	
	  c=fgetc(source_file);
	  if (!feof(source_file)) 
	    fputc(c,target_file);
	  else
	    break;
	}
	fclose(source_file);
	fclose(target_file);		
}
