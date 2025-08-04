#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
	char s[10];
	int i, category;
	srand(time(0));//before loop
	printf("%c \n",rand()%10+48);//0-9:10 chars 0:48    category 0
	printf("%c \n",rand()%26+65);//A-Z:26 letters A:65  category 1
	printf("%c \n",rand()%26+97);//a-z:26 letters a:97  category 2
	for(i=0;i<9;i++){
	   category=rand()%3; //0-2
	   if (category==0)	   
		   s[i]=rand()%10+48;
	   else if (category==1)	   
		   s[i]=rand()%26+65;
	   else
	       s[i]=rand()%26+97;			
		
	}	   
	s[9]='\0';//null char
	printf("%s\n",s);
	getch();
	}
