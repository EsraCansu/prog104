#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
	char *s;
	s=(char *)malloc(sizeof(char)*1001);//0-999 1000:\n
	if (s==NULL){
		printf("out of memory\n");
		exit(0);
	}
	int i, category;
	srand(time(0));//before loop
	
	for(i=0;i<1000;i++){
	   category=rand()%3; //0-2
	   if (category==0)	   
		   s[i]=rand()%10+48;
	   else if (category==1)	   
		   s[i]=rand()%26+65;
	   else
	       s[i]=rand()%26+97;			
		
	}	   
	s[1000]='\0';//null char
	printf("%s\n",s);
	getch();
	}
