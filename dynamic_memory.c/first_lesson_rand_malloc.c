#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int number_char_counter(char *p, int *counter){
    int i;
    for(i=0; i<1000; i++){
        if(p[i]>='0' && p[i]<='9')
            (*counter)++;
    }
    return counter;
}

int main(){
    int i, counter=0;
    char *p;

    p=(char*)malloc(100*sizeof(int));

    if(p==NULL){
        printf("Error!");
        exit(0);
    }

    srand(time(NULL));

    for(i=0; i<100; i++){ //0-255 arasında ascıı code olduğu için 256 yazdık çünkü 255. değere geldiği zaman sıfır olmasını istemeyiz
        p[i]= rand()%256;
    }
        
    printf("The randoms: ");
    for(i=0; i<100; i++){
        printf("%c\n", p[i]);
    }

    number_char_counter(&p, &counter);
    printf("The counting of the numbers: %d", counter );

    free(p);
    return 0;
}