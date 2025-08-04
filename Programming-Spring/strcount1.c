/* write a C function to count the chars between A-Z inside a give string.*/
#include <stdio.h>
/* string: null terminated char array*/
int strAZcount(char *s)
{
	int count=0;
	while(*s) //*s!='\0'
	{
		if (*s>='A'&&*s<='Z')
		  count++;
		s++;		  
	}
	return count;
}
main()
{
  char str[100];
  int count=0;
  printf("str:");
  gets(str);
  count=strAZcount(str);
  printf("count of A-Z:%d\n",count);
	
}
