/* write a C function to count the chars between A-Z and a-z inside a give string.*/
#include <stdio.h>
/* string: null terminated char array*/
void strAZazcount(char *s,int * count1,int *count2)
{
	*count1=0;
	*count2=0;
	
	while(*s) //*s!='\0'
	{
		if (*s>='A'&&*s<='Z')
		  (*count1)++;
		else if (*s>='a'&&*s<='z')
		  (*count2)++;
		s++;		  
	}	
}
main()
{
  char str[100];
  int count1=0,count2=0;
  printf("str:");
  gets(str);
  strAZazcount(str,&count1,&count2);
  printf("count of A-Z:%d\n",count1);  	
  printf("count of a-z:%d\n",count2); 
}
