#include<stdio.h>
#include<stdlib.h>

int main(){
    int i,sum=0;
    int nums[5];

    printf("Please enter five numbers: \n");

    for(i=0; i<5; i++){
        scanf("%d",&nums[i]);
    }

    for(i=0; i<5; i++){
        sum +=nums[i];

    }
    printf("The sum of your arrays: %d\n",sum);

    return 0;
}