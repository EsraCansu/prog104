#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void max_min_in_row(int **m, int *max_in_row, int *min_in_row);
void max_min_in_col(int **m, int *max_in_col, int *min_in_col);

int main(){
    int i, j, *m[10], *sm[10], max_in_col[6], min_in_col[6],max_in_row[10],min_in_row[10];
    FILE *f;
    f=fopen("matrix.txt","w");
    if(f==NULL){
        printf("File couldn't open\n");
        exit(0);
    }
    
    srand(time(NULL));
    for(i=0; i<10; i++){
        m[i] = (int*)malloc(6*sizeof(int));
        if(m[i] == NULL){
            printf("Memory couldn't allocated\n");
            exit(0);
        }
        for(j=0; j<6; j++){
            m[i][j] = rand()%50;
            printf("%d\t", m[i][j]);
            fprintf(f, "%d\t", m[i][j]);
        }
        printf("\n");
        fprintf(f,"\n");
    }
    fclose(f);

    f=fopen("matrix.txt","r");
    if(f==NULL){
        printf("File couldn't open\n");
        exit(0);
    }

    for(i=0; i<10; i++){
        sm[i] = (int*)malloc(6*sizeof(int));
        if(sm[i] == NULL){
            printf("Memory couldn't allocated\n");
            exit(0);
        }
        for(j=0; j<6; j++){
            if((!fscanf(f, "%d", &sm[i][j]))){
                printf("ERROR, reading file\n");
                exit(0);
            }
        }
    }
    fclose(f);

    max_min_in_row(m, max_in_row, min_in_row);
    max_min_in_col(m, max_in_col, min_in_col);

    for(i=0; i<10; i++){
        printf("Row %d. Max: %d and min: %d\n", i+1, max_in_row[i], min_in_row[i]);
    }
        
    for(i=0; i<6; i++){
        printf("Col %d. Max: %d and min: %d\n", i+1, max_in_col[i], min_in_col[i]);
    }

    for(i=0; i<10; i++){
        free(m);
        free(sm);
    }
    return 0;
}

void max_min_in_row(int **m, int *max_in_row, int *min_in_row){
    int i,j;
    for(i=0; i<10; i++){
        max_in_row[i]=m[i][0];
        min_in_row[i]=m[i][0];
        for(j=0; j<6; j++){
            if(m[i][j]>max_in_row[i]){
                max_in_row[i]=m[i][j];
            }
            if(m[i][j]<min_in_row[i]){
                min_in_row[i]=m[i][j];
            }
        }
    }
}
void max_min_in_col(int **m, int *max_in_col, int *min_in_col){
    int i,j;
    for(i=0; i<6; i++){
        max_in_col[i]=m[0][i];
        min_in_col[i]=m[0][i];
        for(j=0; j<10; j++){
            if(m[j][i]>max_in_col[i]){
                max_in_col[i]=m[j][i];
            }
            if(m[j][i]<min_in_col[i]){
                min_in_col[i]=m[j][i];
            }
        }
    }
}