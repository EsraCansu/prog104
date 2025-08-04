#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

void found_the_max_min_in_row(int **m, int row, int column, int *max_in_row, int *min_in_row);
void found_the_max_min_in_column(int **m, int row, int column, int *max_in_row, int *min_in_row);

int main(){
    int row, column, i, j, max_in_row, min_in_row, max_in_col, min_in_col;

    printf("Please enter the size of row:\n");
    scanf("%d", &row);
    printf("Please enter the size of column:\n");
    scanf("%d", &column);

    int **m= (int**)malloc(row*sizeof(int*));
    for(i=0; i<row; i++){
        m[i] = (int*)malloc(column*sizeof(int));
    }

    srand(time(NULL));
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            m[i][j] = rand()%99 + 1;
        }
    }

    found_the_max_min_in_row(m, &row, &column, &max_in_row, &min_in_row);
    found_the_max_min_in_column(m, &row, &column, &max_in_col, &min_in_col);

    printf("Generated matrix:\n");
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            printf("%d\t", m[i][j]);
        }
        printf("\n");
    }
    printf("The max value of row: \n%d\n", &max_in_row);
    printf("The max value of column: \n%d\n", &max_in_col);
    printf("The min value of row: \n%d\n", &min_in_row);
    printf("The max value of row: \n%d\n", &min_in_col);

    for(i=0; i<row; i++){
        free(m[i]);
    }

    free(m);
    return 0;
}

void found_the_max_min_in_row(int **m, int row, int column, int *max_in_row, int *min_in_row){
    int i, j;
    *min_in_row = m[0][column];
    *max_in_row = m[0][column];
    
    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            if(m[i][j] <= *min_in_row)
                *min_in_row = m[i][j];

            if(m[i][j] >= *max_in_row){
                *max_in_row = m[i][j];
            }
        }
    }
}

void found_the_max_min_in_column(int **m, int row, int column, int *max_in_col, int *min_in_col){
    int i, j;
    *min_in_col = m[row][0];
    *max_in_col = m[row][0];

    for(i=0; i<row; i++){
        for(j=0; j<column; j++){
            if(m[i][j] <= *min_in_col)
                *min_in_col = m[i][j];

            if(m[i][j] >= *max_in_col){
                *max_in_col = m[i][j];
            }
        }
    }
}