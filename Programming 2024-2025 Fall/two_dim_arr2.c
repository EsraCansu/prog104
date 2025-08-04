// C Program to illustrate the 2D array
#include <stdio.h>

int main() {
  
    // Create and initialize an array with 3 rows
      // and 2 columns
    int arr[3][2];
    int i,j;
	// Read each array element's value from keyboard
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            scanf("%d",&arr[i][j]);
        }          
    }
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 2; j++) {
            printf("%d\t",arr[i][j]);
        }
          printf("\n");
    }
    return 0;
}
