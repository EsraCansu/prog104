#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//generate a dynamic int array of length 1000.
//fill array with random number between 1-49.
//Find the most 6 repeated number.


void main()
{   
    int * p;
    int i,j;
    int counter[49];//counter[0]--->1 .. counter[48]-->49
    int max=0, max_repeated_number,last_max;  
    int max_repeated_numbers[6];
    
    // Dynamically allocate memory using malloc()
    p= (int *)malloc(1000* sizeof(int));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (p == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    
     srand(time(0));// initialize random seed before loop
     for (i = 0; i < 49; i++) 
       counter[i]=0;
     for (i = 0; i < 1000; i++) {
         *(p+i)=rand()%49+1;//1-49
         counter[p[i]-1]++; 
		          
     }
     for (i = 0; i < 49; i++) 
       printf("%d:%d\n",i+1,counter[i]);
	 last_max=0;
	 for (j=0;j<6;j++){	 
	   max=counter[0];
       max_repeated_number=1;
       for (i = 1; i < 49; i++) {
       	  if (j==0){			 
      	  if ((counter[i]>max)){
    		max=counter[i];
    		max_repeated_number=i+1;    		
		   }    	   
	     }  
	     else
	     {
	     	if ((counter[i]>max)&&(counter[i]<last_max)){
    		max=counter[i];
    		max_repeated_number=i+1;    		
		   }    
		 }
	   last_max=max;
	   max_repeated_numbers[j]=max_repeated_number;
	   printf("%d %d\n",max_repeated_number,max);
    }
     for (j=0;j<6;j++)
	    printf("%d\n",max_repeated_numbers[j]);
     free(p);
}
}

