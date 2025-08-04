#include<stdio.h>
#include<stdlib.h>

int main(){
    int array[10];
    int i, j, prime_nums[10], not_prime_nums[10];

    printf("Please enter 10 numbers for find the prime or not: \n");

    for(i=0; i<10; i++){
        scanf("%d", &array);
    }

    for(i=0; i<10; i++){
        for(j=0; j<array[i]/2; j++){

            if(array[i]%j != 0){
                prime_nums[i] = array[i]; 
            }

            else{
                not_prime_nums[i] = array[i];
            }
        }

    }
    printf("The prime numbers: %d\n The isn't prime numbers: %d", prime_nums[i], not_prime_nums[i]);

    return 0;
}