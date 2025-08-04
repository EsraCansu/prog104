#include<stdio.h>
#include<stdlib.h>
/*Create a 10-element array. Sort the elements of this array in simple order from largest to smallest.
 Display the sorted array on the screen. Then display the largest number.*/

int main(){
    int i, j, largest_num;
    int arrays[10];

    printf("Enter 10 numbers:\n");

    for(i=0; i<10; i++){
        scanf("%d", &arrays[i]);
    }

    for(i=0; i<10-1; i++){
        for(j=i+1; j<10; j++){
            if(arrays[i] <= arrays[j]){
                largest_num = arrays[i];
                arrays[i] = arrays[j];
                arrays[j] = largest_num;
            }
        }
    }

    printf("Sorted array from largest to smallest:\n");

    for(i=0; i<10; i++){
        printf("%d\t", arrays[i]);
    }

    printf("\nThe largest number is: %d\n", arrays[0]);

    return 0;
}