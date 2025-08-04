#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int row,col,i,j;

    printf("Please enter the size of row:\n");
    scanf("%d",&row);

    printf("Please enter the size of column\n");
    scanf("%d",&col);

    int m[row][col];
    int mT[col][row];

    srand(time(NULL));
    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            m[i][j] = rand()%100;
        }
    }

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            mT[j][i]= m[i][j]; // the important things
        }
    }

    for(i=0; i<row; i++){
        for(j=0; j<col; j++){
            printf("%d\t",m[i][j]);
        }
        printf("\n");
    }

    printf("Transpose:\n\n");
    for(i=0; i<col; i++){
        for(j=0; j<row; j++){
            printf("%d\t",mT[i][j]);
        }
        printf("\n");
    }
    return 0;
}