#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int *p;
    int i, n, positive_sum=0, negative_sum=0;

    printf("Please enter the size of random numbers:\n");
    scanf("%d", &n);
    
    while(n<=0){
        printf("Please enter the size of random numbers:\n");
        scanf("%d", &n);
    }

    p = (int*)malloc(n*sizeof(int));

    if(p == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));

    printf("The random numbers:\n");
    for(i=0; i<n; i++){
        int choice = rand()%2;
        if(choice == 0){
            p[i] = rand()%101*(-1);
            negative_sum += p[i];
        }
        else{
            p[i] = rand()%101;
            positive_sum += p[i];
        }
        printf("%d\n", p[i]);
    }

    printf("The sum of negative numbers: %d\nThe sum of positive numbers: %d\n", negative_sum, positive_sum);

    free(p);
}