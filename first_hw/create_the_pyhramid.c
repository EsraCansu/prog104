#include <stdio.h>

void pyramid(int row);

int main() {
    int row;

    printf("Please enter the value for triangle:\n");
    scanf("%d", &row);

    pyramid(row);
    return 0;
}

void pyramid(int row) {
    int i, j;
    
    for (i = 1; i <= row; i++) {

        for (j = 1; j <=i; j++) {
            printf("*");
        }

        printf("\n");
    }
}