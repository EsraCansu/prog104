#include<stdio.h>
#include<stdlib.h>
/*Take a 5-element array from the user and find the average of its elements. 
Note: do it using function.*/

int found_average(int *arrays, int *sum, int *average);

int main(){
    int i, sum = 0, average;
    int arrays[5];

    for(i = 0; i < 5; i++){
        int invalid_input = 1; //eğer değeri 0 yazsaydım hiç while döngüsüne girilmeyeceğimden kod çalışmazdı

        while(invalid_input){
            printf("Please enter number %d between(0-100): \n", i+1);
            scanf("%d", &arrays[i]);
            
            if(arrays[i]>= 0 && arrays[i]<= 100){
                printf("Calculating...\n");
                invalid_input = 0;
            }
            else{
                printf("İnvalid input! Please enter a number between 0 to 100\n");
            }
        }
    
    }

    found_average(arrays, &sum, &average);

    printf("The sum of arrays: %d, the average of arrays: %d\n", sum, average);

    return 0;
}

int found_average(int *arrays, int *sum, int *average){
    int i;

    for(i = 0; i < 5; i++){
        *sum += arrays[i];  
    }

    *average = *sum / 5;   

    return *average;
}
