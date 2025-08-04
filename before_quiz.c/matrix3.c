#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int col, row, i, j, k;

    printf("Please enter the size of your first maxtrix's row:\n");
    scanf("%d", &row);

    printf("Please enter the size of your first maxtrix's column:\n");
    scanf("%d", &col);

    int m1[row][col];
    int mT[col][row];
    int result[row][row];

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("m1[%d][%d]: ", i, j);
            scanf("%d", &m1[i][j]);
        }
    }

    printf("Your matrix and its transpoze:\n");
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            mT[j][i] = m1[i][j];
        }
    }

    for(i=0; i<col; i++){
        for(j=0; j<row; j++){
            printf("%d\t", mT[i][j]);
        }
        printf("\n");
    }

    printf("\nProduct of matrixand its transpoze\n");
    for(i<0; i<row; i++){
        for(j=0; j<row; j++){
            result[i][j] = 0;
            for(k=0; k<col; k++){
                result[i][j] += m1[i][k]*mT[k][j]; 
            }
            printf("%d\t", result[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}