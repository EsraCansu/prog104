// C Program to illustrate the 2D array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


int main(void)
{
    int r = 10, c = 6;
    int i,j;
    int* ptr = (int *)malloc((r * c) * sizeof(int));
    srand(time(0));
    
    for (i = 0; i < r * c; i++)
        ptr[i] = rand()%49+1;

    /* Accessing the array values as if it was a 2D array */
    for ( i = 0; i < r; i++) {
        for ( j = 0; j < c; j++)
            printf("%d ", ptr[i * c + j]);
        printf("\n");
    }

    free(ptr);

    return 0;
}
   

