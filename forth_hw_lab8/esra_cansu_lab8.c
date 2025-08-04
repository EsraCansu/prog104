#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i; 
    int *rand_pass;
    FILE *f;

    rand_pass = (int*)malloc(100000*sizeof(int));
    f = fopen("pass_word.txt", "w");

    if(f == NULL){
        printf("ERROR");
        exit(0);
    }

    if(rand_pass == NULL){
        printf("ERROR");
        fclose(f);
        exit(0);
    }

    srand(time(NULL));
    for(i=0; i<100000; i++){
        rand_pass[i] = rand()%49+1;
        fprintf(f,"%d\t",rand_pass[i]);
        if ((i + 1)% 10 == 0){
            fprintf(f, "\n");
        }
    }
    printf("Your password is written successfully!");

    free(rand_pass);
    fclose(f);
}