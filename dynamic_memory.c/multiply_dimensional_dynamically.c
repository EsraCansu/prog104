#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void found_the_largest_smallest_num_in_row();
void found_the_largest_smallest_num_in_column();


int main(){
    int **p;
    int i, j; 
    int largest_c, smallest_c, largest_r, smallest_r;
    p = (int**)malloc(sizeof(int*)*6); 

    printf("the matrix:\n");

    srand(time(NULL));
    for(i=0; i<10; i++){
        p[i] = (int*)malloc(sizeof(int)*6); 
        for(j=0; j<6; j++){
            p[i][j]=rand()%100;
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }

    found_the_largest_smallest_num_in_column(p, &largest_c, &smallest_c);
    found_the_largest_smallest_num_in_row(p, &largest_r, &smallest_r);

    printf("The largest num in the row: %d\nThe smallest num in the row:%d\n", largest_r, smallest_r);
    printf("The largest num in the column: %d\nThe smallest num in the column:%d\n", largest_c, smallest_c);

    return 0;
}

void found_the_largest_smallest_num_in_row(int *p, int *largest_r, int *smallest_r){
    int i, j;
    *largest_r=0;
    *smallest_r=0;
    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
        printf("\n");
    }

}
void found_the_largest_smallest_num_in_column(int *p, int *largest_c, int *smallest_c){
    int i, j;
    *largest_c=0;
    *smallest_c=0;

    for(i=0; i<10; i++){
        p[i][0];
        for(j=0; j<6; j++){
            p[i][j]=rand()%100;
            printf("%d\t", p[i][j]);
        }
        printf("\n");
    }
}