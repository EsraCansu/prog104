#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int length;
int randnumber;
int * p;
int i,j,k;
long int n;
int counter[49];// counter[0] ...counter[48]
int numbers[6];
int frequency[6];
int max;
// allocate a dynamic array of int having random length between 100-1000.
// fill this array with random numbers between 1-49. 
//find the number having the highest frequency

void main()
{  

  srand(time(NULL));//before loop	    
  for (k=0;k<6;k++){   
	for(i=0;i<length;i++)
	  counter[i]=0;	  
		
	length=rand()%901+100;
	p=(int *) malloc(length*sizeof(int));
	for(i=0;i<length;i++)
	{
		p[i]=rand()%49+1;
		counter[p[i]-1]++;
	}
	
	max=counter[0];
	j=0;
	for(i=1;i<49;i++)
	{
		if (counter[i]>max)
		{		
		  max=counter[i];
		  j=i;
	    }
	}
   numbers[k]=j+1;
   frequency[k]=max;  
   printf("%d:%d:%d\n",k,numbers[k],frequency[k]);    
} 
 getch(); 
}
