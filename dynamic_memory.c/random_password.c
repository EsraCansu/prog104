#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

//generate a synamic string including a-z A-Z 0-9 chars 
//a:97  A:65  9:57

void string_counter(char *p, int *cat1, int *cat2, int *cat3){
    int i=0;
    *cat1=0;
    *cat2=0;
    *cat3=0;

/*     while(p[i]){
        if(p[i]>='A' && p[i]<='Z'){
            (*cat1)++;
        }
        else if(p[i]>='a' && p[i]<='z'){
            (*cat2)++;
        }
        else if(p[i]>='0' && p[i]<='9'){
            (*cat3)++;
        }
        i++;
    } */
   for(i=0; i<100; i++){
    if(p[i]>='A' && p[i]<='Z'){
        (*cat1)++;
    }
    else if(p[i]>='a' && p[i]<='z'){
        (*cat2)++;
    }
    else if(p[i]>='0' && p[i]<='9')
        (*cat3)++;
   }

}

int main(){
    char *p;
    int i, category, cat1, cat2, cat3;

    p=(char*)malloc(101*sizeof(char));

    if(p == NULL){
        printf("Error!");
        exit(0);
    }

    srand(time(NULL));

    for(i=0; i<100; i++){
        category  = rand()%3;

        if(category == 0){
            p[i] = rand()%26 + 'A';
        }
        else if(category == 1){
            p[i] = rand()%26 + 'a';
        }
        else{
            p[i] = rand()%10 + '0';
        }
    }

    string_counter(p, &cat1, &cat2, &cat3); // catler integer ve tek değer oldukları için direkt adreslerini göndeririz

    p[100]='\0';

    printf("The passwords: \n%s\n", p);
    for(i=0; i<100; i++){
        printf("%c", p[i]);
        if((i+1)%10 == 0){
            printf("\n");
        }
    }
    printf("cat1: \n%d\ncat2:\n%d\ncat3:\n%d\n", cat1, cat2, cat3);

    free(p);
    return 0;
}