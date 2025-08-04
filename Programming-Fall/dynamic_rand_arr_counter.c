#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
	char *s;
	int counter_AZ[26];
	int counter_az[26];
	int counter_09[10];
	s=(char *)malloc(sizeof(char)*1001);//0-999 1000:\n
	if (s==NULL){
		printf("out of memory\n");
		exit(0);
	}
	int i, category;
	srand(time(0));//before loop
	//initialize counters
	for (i=0;i<26;i++){
	   counter_AZ[i]=0;
	   counter_az[i]=0;
	}
	for (i=0;i<10;i++)
	   counter_09[i]=0;	   
	
	for(i=0;i<1000;i++){
	   category=rand()%3; //0-2
	   if (category==0)	   
		   s[i]=rand()%10+48;//48-57  0-9
	   else if (category==1)	   
		   s[i]=rand()%26+65;//65-90 A-Z
	   else
	       s[i]=rand()%26+97;//97-122 a-z
	   if (category==0)		
	      counter_09[s[i]-48]++;
	   else if (category==1)		
	      counter_AZ[s[i]-65]++;
	   else	
	      counter_az[s[i]-97]++;
	}	   
	s[1000]='\0';//null char
	printf("%s\n",s);
	//show counters:frequecies of different chars
	for(i=0;i<26;i++)
		printf("%c:%d ",i+65,counter_AZ[i]);
	printf("\n");
	for(i=0;i<26;i++)
		printf("%c:%d ",i+97,counter_az[i]);
	printf("\n");
	for(i=0;i<10;i++)
		printf("%c:%d ",i+48,counter_09[i]);	
	printf("\n");
	getch();
	}
