#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int *p;
    int i, max=0, max_repeated_num;
    int counter[49]={0};

    p = (int*)malloc(1000*sizeof(int));

    if(p == NULL){
        printf("Error");
        exit(0);
    }

    srand(time(NULL));

    for(i=0; i<1000; i++){
        p[i] = rand()%49+1;

        counter[p[i]-1]++;
    }

    for(i=0; i<49; i++){
        if(counter[i]>max){
            max = counter[i];
            max_repeated_num = i+1; 
        }
    }

    printf("Most repeated number: %d (repeated %d times)\n", max_repeated_num, max);

    for(i=0; i<49; i++){
        printf("%d: %d\n", i+1, counter[i]);
    }

    free(p);
    return 0;
}