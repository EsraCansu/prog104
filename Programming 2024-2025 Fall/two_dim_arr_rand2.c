// C Program to illustrate the 2D array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
    // Create and initialize an array with 3 rows
      // and 2 columns
    int arr[10][6];
    int i,j;
    int max_row[10];
    int max;
    
    srand(time(0));
	// generate each array element's value randomly between 1-49
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 6; j++) {
            arr[i][j]=rand()%49+1;
        }          
    }
    for (i = 0; i < 10; i++) {
    	max=arr[i][0];
        for (j = 0; j < 6; j++) {
            printf("%d\t",arr[i][j]);
            if(arr[i][j]>max)
              max=arr[i][j];
        }
          max_row[i]=max;
          printf("\n");
    }
    printf("\n");
    for (i = 0; i < 10; i++) 
      printf("%d\t",max_row[i]);
    return 0;
}
