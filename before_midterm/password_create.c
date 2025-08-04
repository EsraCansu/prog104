#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//create 1000 password in 100 line 
void rand_pass(int *pass, int lenght){
    int i, choice;

    for(i=0; i<lenght; i++){
        choice=rand()%3;
        if(choice == 0)
            pass[i] = rand()%26+ 'A';

        else if(choice == 1)
            pass[i] = rand()%26+ 'a';

        else
            pass[i] = rand()%10+ '0';
    }
    pass[lenght]='\0';
}

int main(){
    int i;
    FILE *f;
    char *pass;

    pass=(char*)malloc(1100*sizeof(char));
    if(pass == NULL){
        printf("ERROR");
        exit(0);
    }

    f=fopen("artik_pas.txt", "w");
    if(f == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));
    for(i=0; i<100; i++){
        rand_pass(pass,11);
        fprintf(f,"%c\t",pass[i]);
        if((i+1)%10 == 0)
            fprintf(f,"\n");
    }

    printf("Your password is written\n");
    fclose(f);
    free(pass);
    return 0;
}