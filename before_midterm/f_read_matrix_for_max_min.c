#include<stdio.h>
#include<stdlib.h>

void max_min_in_row(int m[10][6], int *max_in_row, int *min_in_row){
    int i, j;

    for(i=0; i<10; i++){
        max_in_row[i] = m[i][0];
        min_in_row[i] = m[i][0];

        for(j=0; j<6; j++){
            if(max_in_row[i]>m[i][j])
                max_in_row[i] = m[i][j];

            if(min_in_row[i]<m[i][j])
                min_in_row[i] = m[i][j];
        }
    }
}

int main(){
    int i, j;
    FILE *f;
    int m[10][6];
    int max_in_row[10], min_in_row[10];

    f=fopen("matrix.txt", "r");
    if(f == NULL){
        printf("ERROR");
        exit(0);
    }

    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            fscanf(f, "%d", &m[i][j]);
        }
    }
    fclose(f);
    
    max_min_in_row(m, max_in_row, min_in_row);

    printf("Matrix's row and column values: \n");
    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            printf("%d\t", m[i][j]);
        }
        printf("Max: %d\tMin: %d\n", max_in_row[i], min_in_row[i]);
    }

    return 0;
}