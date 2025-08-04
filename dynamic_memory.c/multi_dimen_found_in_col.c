#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void found_max_min_value_in_column(int *p, int *max_nums_in_column, int *min_nums_in_column);

int main(){
    int p[10][6];
    int i, j;
    int max_nums_in_column[6];
    int min_nums_in_column[6];

    srand(time(NULL));
    printf("The matrix: \n");

    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            p[i][j] = rand()%49+1;
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    } 
    void found_max_min_value_in_column(p, max_nums_in_column, min_nums_in_column);
    
    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            printf("The max value of %d. column: %d\t", i+1, max_nums_in_column[i]);
            printf("The min value of %d. column\n", min_nums_in_column);
        }
    }
    return 0;
}

void found_max_min_value_in_column(int *p, int *max_nums_in_column, int *min_nums_in_column){
    int i, j;
    int max_num_in_column;
    int min_num_in_column;

    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            max_num_in_column = p[0][j];
            min_num_in_column = p[0][j];

            if(p[i][j]>max_num_in_column){
                max_num_in_column = p[i][j];
            }
            if(p[i][j]<min_num_in_column){
                min_num_in_column = p[i][j];
            }
        }
        max_nums_in_column[i] = max_num_in_column;
        min_nums_in_column[i] = min_num_in_column;  
    }
}