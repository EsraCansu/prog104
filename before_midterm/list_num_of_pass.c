#include<stdio.h>
#include<stdlib.h>
// oluşturulan password dosyasından alınan şifrelerin satır satır sayıları listelenecek

int main(){
    char character;
    FILE *new_file, *new_file_num;
    FILE *f;

    f=fopen("password.txt", "r");
    if(f==NULL){
        printf("ERROR");
        exit(0);
    }

    new_file = fopen("new_password.txt", "w");
    if(new_file == NULL){
        printf("ERROR");
        exit(0);
    }

    new_file_num = fopen("new_num_password.txt", "w");
    if(new_file_num==NULL){
        printf("ERROR");
        exit(0);
    }

    while(!feof(f)){
        character = fgetc(f);
        if(!(character>='0' && character<='9'))
            fputc(character, new_file);

        if(character>='0' && character<='9')
            fputc(character, new_file_num);

        if(character == '\n')
            fputc('\n',new_file_num);
    }

    printf("Digits in the password file\n");

    fclose(f);
    fclose(new_file);
    fclose(new_file_num);
    return 0;    
}