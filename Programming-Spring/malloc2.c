#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int length;
int randnumber;
int * p;
int i,j;
int counter[49];// counter[0] ...counter[48]
int max;
// allocate a dynamic array of int having random length between 100-1000.
// fill this array with random numbers between 1-49. 
//find the number having the highest frequency
void main()
{  

	for(i=0;i<length;i++)
	  counter[i]=0;
	  
	srand(time(0));//before loop	
	length=rand()%901+100;
	p=(int *) malloc(length*sizeof(int));
	for(i=0;i<length;i++)
	{
		p[i]=rand()%49+1;
		counter[p[i]-1]++;
	}
	for(i=0;i<length;i++)
	{
		printf("%d ",p[i]);
	}
	printf("\n");
	getch();
	for(i=0;i<49;i++)
	{
		printf("%d:%d\n",i+1,counter[i] );
	}
	max=counter[0];
	for(i=1;i<49;i++)
	{
		if (counter[i]>max)
		{		
		  max=counter[i];
		  j=i;
	    }
	}
	printf("%d:%d",j+1,max);
	getch();
	free(p);
}
