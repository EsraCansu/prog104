#include<stdio.h>

int main(){
    int i;
    int num[10];
    int result;

    printf("Please enter 10 integers:\n");

    for(i = 0; i < 10; i++){
        result = scanf("%d", &num[i]);

        while(result != 1){
            printf("Invalid input! Please enter an integer: ");
            while(getchar() != '\n');
            result = scanf("%d", &num[i]);
        }
    }
    
    for(i = 0; i < 10; i++){
        if(num[i] % 2 == 0){
            printf("%d is an even number\n", num[i]);
        }
        else{
            printf("%d is an odd number\n", num[i]);
        }
    }

    return 0;
}