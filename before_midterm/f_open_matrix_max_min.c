#include<stdio.h>
#include<stdlib.h>
#include<time.h>
void rand_matrix(int m[10][6]){
    int i, j;
    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            m[i][j] = rand()%50+1;   
        }
    }
}

int main(){
    int i, j;
    int m[10][6];
    FILE *f;

    f=fopen("matrix.txt", "w");

    if(f==NULL){
        printf("ERROR");
        exit(0);
    }
    rand_matrix(m);
    for(i=0; i<10; i++){
        for(j=0; j<6; j++){
            fprintf(f,"%d\t",m[i][j]);
        }
        fprintf(f,"\n");
    }

    fclose(f);
    printf("Matrix is written");
    return 0;
}