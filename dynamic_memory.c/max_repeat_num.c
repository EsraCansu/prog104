#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int *p;
    int i, max, max_repeated_number ;
    int counter[49]; //50'ye kadar 1-49

    p = (int*)malloc(1000*sizeof(int));

    if(p == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));

    for(i=0; i<1000; i++){
        p[i] = rand()%49 + 1;
        counter[p[i]-1]++;
    }

    for(i=0; i<49; i++){
        printf("%d: %d\n", i+1, counter[i]);
    }

    for(i=0; i<49; i++){
        if(counter[i]>max){
            max=counter[i];
            max_repeated_number = i++;
        }
    }
    for(i=0; i<49; i++){
        printf("%d: %d\n", max_repeated_number, counter[i]);
    }

    free(p);
    return 0;
}