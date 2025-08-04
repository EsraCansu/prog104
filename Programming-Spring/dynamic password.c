#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//write a C function to generate a random password including chars a-z, A-Z,0-9
//length will be between 10-20
void randpass(char *s)
{
	int length,i;
	int category;
	char ch;
	srand(time(0));
	length=rand()%11+10;
	for (i=0;i<length;i++)
	{
		category=rand()%3;
		if (category==0)
		  ch=rand()%26+'a';
		else if (category==1)
		  ch=rand()%26+'A';
		else
		  ch=rand()%10+'0';
		s[i]=ch;
	}
	s[length]='\0';//null char terminated string
}
main()
{
	char * s;
	s=(char *) malloc(100*sizeof(char));
	randpass(s);
	printf("pass:%s \n",s);
	free(s);
}
