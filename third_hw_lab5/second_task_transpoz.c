#include<stdio.h>
#include<stdlib.h>

int main(){
    int m[3][2];
    int mT[2][3];
    int i, j;

    srand(time(NULL));

    printf("The original matrix is:\n");
    for(i=0; i<3; i++){
        for(j=0; j<2; j++){
            m[i][j] = rand()%10;
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }

    for(i=0; i<3; i++){
        for(j=0; j<2; j++){
            mT[j][i] = m[i][j];
        }
    }

    printf("The transpose of the matrix:\n");
    for(i=0; i<2; i++){
        for(j=0; j<3; j++){
            printf("%d\t", mT[i][j]);
        }
        printf("\n");
    }

    return 0;
}