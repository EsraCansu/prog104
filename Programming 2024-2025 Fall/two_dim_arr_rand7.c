// C Program to illustrate the 2D array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// write a c function to fill in 2 dimensional int array with 
//random numbers between -100 and -1

void fill_int_arr(int * arr,int r, int c){
	int i, j;
	for ( i = 0; i < r; i++) 
        for ( j = 0; j < c; j++)
             arr[i * c + j]=-1*(rand()%100+1);    
}

void main()
{
    int r = 10, c = 6;
    int i,j;
    int* ptr = (int *)malloc((r * c) * sizeof(int));
    srand(time(0));
    
    fill_int_arr(ptr,r,c);

    /* Accessing the array values as if it was a 2D array */
    for ( i = 0; i < r; i++) {
        for ( j = 0; j < c; j++)
            printf("%d ", ptr[i * c + j]);
        printf("\n");
    }

    free(ptr);
    
}
   

