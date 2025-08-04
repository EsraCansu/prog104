#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//write a C function to generate a random serial number including chars a-z, A-Z,0-9
//length will be 16, 20, 24
//Ax12-BXJA-QWER-1234
void randpass(char *s)
{
	int length,i,j;
	int category;
	char ch;
	srand(time(0));
	length=rand()%3*4+16;
	length=length+length/4-1;
	j=0;
	for (i=0;i<length;i++)
	{		
		if (j==4)
		{		
		  ch='-';
		  j=0;
	    }
	    else
	    {		
		category=rand()%3;
		if (category==0)
		  ch=rand()%26+'a';
		else if (category==1)
		  ch=rand()%26+'A';
		else
		  ch=rand()%10+'0';		
		j++;
	   }
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
