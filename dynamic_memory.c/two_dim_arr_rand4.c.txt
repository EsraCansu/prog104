// C Program to illustrate the 2D array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
    // Create and initialize an array with 3 rows
      // and 2 columns
    int arr[10][6];
    int i,j;
    int max_col[6];
    int max;
	int min_col[6];
    int min;
    
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
    //find max and min of each column
    for (j = 0; j <6; j++) {
    	max=arr[0][j];
    	min=arr[0][j];
        for (i = 0; i < 10; i++) {            
            if(arr[i][j]>max)
              max=arr[i][j];
              
            if(arr[i][j]<min)
              min=arr[i][j];
        }
          max_col[j]=max;
          min_col[j]=min;
          printf("\n");
    }
    printf("\n");
    for (j = 0; j < 6; j++){	
      printf("%d\t",max_col[j]);      
    }
    printf("\n");
    for (j = 0; j < 6; j++){	
      printf("%d\t",min_col[j]);      
    }
    return 0;
}
