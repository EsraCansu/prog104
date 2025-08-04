// 10x6 matrix oluşturup elemanları rastgele 100 ve -100 arasında oluşturun
//Satır ve sütunların toplamlarını bulacak fonk yazın
//Satır ve sütunlardaki max ve min değerlerinü bulacak fonk yazın 
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void max_min_in_row(int **m, int *min_in_row, int *max_in_row){
    int i, j;
    for(i=0; i<10; i++){
        min_in_row[i] = m[i][0];
        max_in_row[i] = m[i][0];
        for(j=0; j<6; j++){
            if(max_in_row[i]<m[i][j])
                max_in_row[i] = m[i][j];
            
            if(min_in_row[i]>m[i][j])
                max_in_row[i] = m[i][j];
        }
    }
}

void max_min_in_col(int **m, int *min_in_col, int *max_in_col){
    int i, j;
    for(j=0; j<6; j++){
        max_in_col[j] = m[0][j];
        min_in_col[j] = m[0][j];
        for(i=0; i<10; i++){
            if(max_in_col[j]<m[i][j])
                max_in_col[j] = m[i][j];

            if(min_in_col[j]>m[i][j])
                min_in_col[j] =m[i][j];
        }
    }
}

void sum_in_column(int **m, int *sum_in_col){ // m iki boyutlu olduğu için çift kat pointer kullanmayı unutma
    int i, j;
    for(j=0; j<6; j++){
        sum_in_col[j]=0;
        for(i=0; i<10; i++){
            sum_in_col[j] += m[i][j];
        }
    }
}

void sum_in_rows(int **m, int *sum_in_row){
    int i, j;

    for(i=0; i<10; i++){
        sum_in_row[i] = 0;
        for(j=0; j<10; j++){
            sum_in_row[i] += m[i][j];
        }
    }

}

int main(){
    int i, j; 
    int **m;
    int max_in_row[10], min_in_row[10], max_in_col[6],min_in_col[6];
    int sum_in_row[10], sum_in_col[6];

    m = (int**)malloc(10*sizeof(int*));
    for(i=0; i<10; i++){
        m[i] = (int*)malloc(6*sizeof(int));
    }

    if(m == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));

    max_min_in_row(m, min_in_row, max_in_row);
    max_min_in_col(m, min_in_col, max_in_col);
    sum_in_column(m, sum_in_col);
    sum_in_rows(m, sum_in_row);

    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            m[i][j] = rand()%201-100;
        }
    }

    printf("your matrix is: \n");
    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            printf("%d\t", m[i][j]);
        }
        printf("Max: %d\tMin: %d\tSum: %d\n", max_in_row[i], min_in_row[i], sum_in_row[i]);
    }

    printf("Max value in column:");
    for(i=0; i<6; i++){
        printf("%d\t", max_in_col[i]);
    }

    printf("\nMin value: ");
    for(i=0; i<6; i++){
        printf("%d\t", min_in_col[i]);
    }

    printf("\nSum of column: ");
    for(i=0; i<6; i++){
        printf("%d\t", sum_in_col[i]);
    }

    for(i=0; i<10; i++){
        free(m[i]);
    }
    free(m);
    return 0;
}