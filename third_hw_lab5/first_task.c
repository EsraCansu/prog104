#include<stdio.h>
#include<stdlib.h>

int main(){
    int col1, row1, col2, row2, i, j, k;

    printf("Please enter the size of row for the first matrix:\n ");
    scanf("%d", &row1);

    printf("Please enter the size of column for first matrix:\n ");
    scanf("%d", &col1);

    printf("Please enter the size of row for the second matrix:\n ");
    scanf("%d", &row2);

    printf("Please enter the size of column for first matrix:\n ");
    scanf("%d", &col2);

    while(row1 != col2){
        printf("Your input is invalid, so please retry the values\n");

        printf("Please enter the size of row for the first matrix:\n ");
        scanf("%d", &row1);

        printf("Please enter the size of column for first matrix:\n ");
        scanf("%d", &col1);

        printf("Please enter the size of row for the second matrix:\n ");
        scanf("%d", &row2);

        printf("Please enter the size of column for first matrix:\n ");
        scanf("%d", &col2);
    }
    int m1[row1][col1];
    int m2[row2][col2];
    int result[row1][col2];

    printf("Please enter the elements for first matrix:\n");
    for(i=0; i<row1; i++){
        for(j=0; j<col1; j++){
            printf("m1[%d][%d]:", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Please enter the elements for first matrix:\n");
    for(i=0; i<row2; i++){
        for(j=0; j<col2; j++){
            printf("m2[%d][%d]:", i, j);
            scanf("%d", &m2[i][j]);
        }
    }

    for(i=0; i<row1; i++){
        for(j=0; j<col2; j++){
            result[i][j] = 0;
            for(k=0; k<row2; k++){
                result[i][j] += m1[i][k] * m2[k][j]; 
            }
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    return 0;
}