#include<stdio.h>
#include<stdlib.h>

int main() {
    int element, i;
    int *array;

    printf("Please enter the number of Fibonnacci terms:\n");
    scanf("%d", &element);

    array = (int*)malloc(element * sizeof(int));
    if (array == NULL) {
        printf("Error allocating memory!\n");
        exit(1);
    }

    array[0] = 0;
    if (element > 1) {
        array[1] = 1;
    }

    for (i = 2; i < element; i++) {
        array[i] = array[i-1] + array[i-2];
    }

    printf("The Fibonnacci sequence: \n");
    for (i = 0; i < element; i++) {
        printf("%d ", array[i]);
    }
    
    printf("\n");

    free(array);
    return 0;
}