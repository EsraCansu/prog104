#include <stdio.h>
#include <stdlib.h>
 
int main()
{
	char s[10];
	int i;
	printf("%d \n",'0');
	printf("%d \n",'\0');
	/* null =\0 backspace=8 space=32 enter=13 A=65 0=48 ... a=97...*//* ascii table: 256 chars 
	between 0 and 255
	*/
	for (i=0;i<256;i++)
	  printf("%d:%c ",i,i);
	getch();
	printf("enter your password:");
	gets(s);//null terminated char array-->string
	printf("%s \n",s);
	getch();
	printf('%d \n',rand()%10+1);
	printf('%c \n',rand()%26+65);
	getch();
	}
