#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    int *matrix[10];
    int n, i, j;

    printf("Please enter the size of your matrix: \n");
    scanf("%d", &n);

    srand(time(NULL));

    for(i=0; i<n; i++){
        matrix[i]=(int*)malloc(n* sizeof(int));
        if(matrix==NULL)
            printf("ERROR");
            exit(0);

        for(j=0; j<n; j++){
            *matrix[j]=rand()%100+1;
            printf("%d\t", *matrix[j]);
        }
    }

    for(i=0; i<n; i++){
        free(matrix[i]);
    }
    return 0;
}