// C Program to illustrate the 2D array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
  
    // Create and initialize an array with 3 rows
      // and 2 columns
    int arr[10][6];
    int i,j;
    srand(time(0));
	// generate each array element's value randomly between 1-49
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 6; j++) {
            arr[i][j]=rand()%49+1;
        }          
    }
    for (i = 0; i < 10; i++) {
        for (j = 0; j < 6; j++) {
            printf("%d\t",arr[i][j]);
        }
          printf("\n");
    }
    return 0;
}
