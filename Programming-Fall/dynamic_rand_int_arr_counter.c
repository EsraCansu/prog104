#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
	/* generate 1000 random numbers between 1-49*/
	int *numbers;
	int counter[49];//index:0-48
	
	numbers=(char *)malloc(sizeof(int)*1000);//0-999 
	if (numbers==NULL){
		printf("out of memory\n");
		exit(0);
	}
	int i;
	srand(time(0));//before loop
	//initialize counters
	for (i=0;i<49;i++)
	   counter[i]=0;	
	
	for(i=0;i<1000;i++){	
	  
	   numbers[i]=rand()%49+1; 
	   printf("%d ",numbers[i]); 
	   counter[numbers[i]-1]++;//counter[0]-->1 ... counter[48]-->49
	}	   
	printf("\n\n");
	//show counters:frequecies of different numbers between 1-49
	for(i=0;i<49;i++)
		printf("%d:%d ",i+1,counter[i]);	
	
	getch();
	}
