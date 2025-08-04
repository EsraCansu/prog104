#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    int array[10];

    printf("Please enter 10 arrays: \n");
    for(i=0; i<10; i++){
        scanf("%d",&array[i]);
    }

    for(i=0; i<10; i++){

        if(array[i] == array[i++]){
            
        }
    }
}