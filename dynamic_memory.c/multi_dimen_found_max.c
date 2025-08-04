#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int p[10][6];
    int i, j;
    int max_nums_in_row[10];
    int min_nums_in_row[10];    
    srand(time(NULL));

    printf("The matrix:\n");
    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            p[i][j] = rand()%49 + 1;
            printf("%d\t",p[i][j]);
        }
        printf("\n");
    }

    found_max_min_value_in_row(p, max_nums_in_row, min_nums_in_row);

    for(i=0; i<10; i++){
        printf("%d. Max value in the row: %d\t", i+1, max_nums_in_row[i]);
        printf("and min value in the row %d\n", min_nums_in_row[i]);
    }
    return 0;
}

void found_max_min_value_in_row(int p[10][6], int *max_nums_in_row, int *min_nums_in_row){
    int i, j;
    int max_num_in_row=0;
    int min_num_in_row=0;    
    for(i=0; i<10; i++){
        max_num_in_row = p[i][0];
        min_num_in_row = p[i][0];
        for(j=0; j<6; j++){
            if(p[i][j]>max_num_in_row){
                max_num_in_row = p[i][j];
            }
            if(p[i][j]<min_num_in_row){
                min_num_in_row = p[i][j];
            }
        }
        max_nums_in_row[i] = max_num_in_row;
        min_nums_in_row[i] = min_num_in_row;
    }
}