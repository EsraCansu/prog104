#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int i, n, smallest_num=500, largest_num=0;
    int *p;

    printf("Please enter the size for random numbers:\n");
    scanf("%d", &n);

    while(n <= 0){
        printf("Invalid input, please enter a positive number:\n");
        scanf("%d", &n);
    }

    p =(int*)malloc(n*sizeof(int));
    if(p == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));
    printf("the random numbers:\n");
    for(i=0; i<n; i++){
        p[i] = rand()%501;
        printf("%d\n", p[i]);
    }

    for(i=0; i<n; i++){
        if(p[i]>=largest_num){
            largest_num = p[i];
        }
        if(p[i]<=smallest_num){
            smallest_num = p[i];
        }
    }
    printf("The largest num: %d\t The smallest num: %d", largest_num,smallest_num);

    free(p);
    return 0;
}