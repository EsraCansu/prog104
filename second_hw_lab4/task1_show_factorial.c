#include<stdio.h>
#include<stdlib.h>
#include<time.h>

void factorial(int *p, int *fact, int n);

int main(){
    int *p, *fact;
    int i, n;

    while(n<=0){
        printf("Please enter a number for create a random number:\n ");
        scanf("%d", &n);
    }
    
    p = (int*)malloc(sizeof(int) * n);
    fact = (int*)malloc(sizeof(int) * n);

    if(p == NULL || fact == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));

    printf("The random numbers:\t");
    for(i=0; i<n; i++){
        p[i] = rand()%10 + 1;
    }
    printf("\n");

    factorial(p, fact, n);

    printf("The factorial of numbers: ");
    for(i=0; i<n; i++){
        printf("the number: %d\t Factorial: %d\n", p[i], fact[i]);
    }

    free(p);
    free(fact);
    return 0;
}

void factorial(int *p, int *fact, int n){
    int i, j;

    for(i=0; i<n; i++){
        fact[i] = 1;
        for(j=1; j<=p[i]; j++){
            fact[i] *= j;
        }
    }    
}