#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int length;
int randnumber;
int * p;
int i;
int counter[49];// counter[0] ...counter[48]
// allocate a dynamic array of int having random length between 100-1000.
// fill this array with random numbers between 1-49
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
	getch();
	free(p);
}
