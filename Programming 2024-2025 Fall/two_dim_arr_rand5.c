// C Program to illustrate the 2D array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void arr_col_min_max(int arr[10][6],int col,int * min, int * max)
{
	int i;
	*max=arr[0][col];
    *min=arr[0][col];
    
    for (i = 0; i < 10; i++) {            
       if(arr[i][col]>*max)
         *max=arr[i][col];
              
        if(arr[i][col]<*min)
          *min=arr[i][col];
    }          
}
int main() {
  
    // Create and initialize an array with 3 rows
      // and 2 columns
    int arr[10][6];
    int i,j;    
    int max,min;	
    
    srand(time(0));
	// generate each array element's value randomly between 1-49
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 6; j++) {
            arr[i][j]=rand()%49+1;
        }          
    }
    //print array
    for (i = 0; i < 10; i++) {    	
        for (j = 0; j < 6; j++) {
            printf("%d\t",arr[i][j]);            
        }
        printf("\n");
    }
    //find max and min of col 0
    arr_col_min_max(arr,0,&min,&max);
    printf("min:%d\t max:%d\n",min,max);
    return 0;
}
