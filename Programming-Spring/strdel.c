/* write a C function to delete the chars between A-Z inside a give string.*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/* string: null terminated char array*/
void strdelAZ(char *s)
{
	char * str;//temporary string
	int length;
	int i,j;
	length=strlen(s);
	str=(char *) malloc(length*sizeof(char));
	if (str==NULL)	
	{
		printf("out of memory!!!");
		exit(1);
	}
	j=0;
	for (i=0;i<length;i++)
	{
		if (!(s[i]>='A'&&s[i]<='Z')) //not between
		{
			str[j]=s[i];
			j++;
		}
	}
	str[j]='\0';
	strcpy(s,str);
	free(str);
}
main()
{
  char str[100];  
  printf("str:");
  gets(str);
  strdelAZ(str);  
  printf("str:%s\n",str); 
}
