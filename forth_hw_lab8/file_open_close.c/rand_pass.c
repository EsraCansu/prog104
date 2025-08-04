#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<time.h>

// create a rand password and sum the numbers

void rand_pass(char *p){
    int cat,i;

    for(i=0; i<20;i++){
        cat=rand()%3;
        if(cat==0){
            p[i]=rand()%26 + 'a';
        }
        else if(cat==1){
            p[i]=rand()%26 + 'A';
        }
        else{
            p[i]=rand()%10 + '0';
        }
    }
    p[20]='\0';
}

int rand_num_sum(char *p){
    int i, j;
    int num=0, sum=0;
    for(i=0; i<20; i++){
        if(p[i]>='0' && p[i]<='9'){
            num = num*10+(p[i]-'0');
        }
        else{
            sum+=num;
            num=0;
        }
    }
    sum+=num;
    return sum;
}

int main(){
    char *p[100];
    int i, sum=0;
    FILE *f;

    f= fopen("rand_pass", "w");
    if(f == NULL){
        printf("ERROR");
        exit(0);
    }

    for(i=0; i<100; i++){
        p[i]=(char*)malloc(sizeof(char)*21);
        if(p==NULL){
            printf("ERROR");
            fclose(f);
            exit(0);
        }
    }
    printf("The text created successfully!\n");

    srand(time(NULL));
    for(i=0; i<100; i++){
        rand_pass(p[i]);
        sum = rand_num_sum(p[i]);
        fprintf(f,"%s\t the sum of password: %d\n", p[i], sum);
        //total_sum += rand_num_sum(p[i]);
    }

    close(f);
    for(i=0; i<100; i++){
        free(p[i]);
    }
    return 0;
}