#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    char character;
    char *new_pass;
    FILE *f;

    f=fopen("password.txt", "r");
    if(f == NULL){
        printf("ERROR");
        exit(0);
    }
    new_pass=fopen("new_pass.txt", "w");
    if(new_pass == NULL){
        printf("ERROR");
        exit(0);
    }

    while(!feof(f)){
        character=fgetc(f);
        if(character>='a' && character<='z')
            character += ('A'-'a');

        fputc(character, new_pass);
    }

    printf("The new form is written");
    fclose(f);
    fclose(new_pass);
    return 0;    
}