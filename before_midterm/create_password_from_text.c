// texteki ilk 10 elemanı sil
#include<stdio.h>
#include<stdlib.h>

int main(){
    int counter=0;
    FILE *f;
    FILE *new_file;
    char c[21];

    f=fopen("password.txt", "r");
    new_file=fopen("new_form.txt", "w");

    if(f == NULL){
        printf("Error");
        exit(0);
    }
    if(new_file == NULL){
        printf("ERROR");
        exit(0);
    }

    while((fscanf(f, "%s", c))!=EOF){
        counter++;
        if(counter>20){
            fputs(c,new_file);
            fputc('\n',new_file);
        }
    }
    printf("First 10 charactes have been removed and saved to new_form file\n");
    fclose(f);
    fclose(new_file);
    return 0;
}
