#include<stdio.h>
#include<stdlib.h>
#include<time.h>
// kulllanıcıdan alınan sayıda password oluşturma ve yazma

void create_password(int num, char *pass);

int main(){
    int i, num, size;
    char *pass;
    FILE *f;

    printf("Please enter how many password:\n");
    scanf("%d", &num);
    printf("Please enter the size of your password:");
    scanf("%d", &size);

    pass = (char*) malloc((size+1)*sizeof(char));
    if(pass==NULL){
        printf("ERROR");
        exit(0);
    }

    f=fopen("final_pass.txt", "w");
    if(f==NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));
    printf("Your password is:\n");
    for(i=0; i<num; i++){
        create_password(size,pass);
        fputs(pass,f);
        fputc('\n',f);
        printf("%s\n", pass);
    }

    fclose(f);

    f=fopen("final_pass.txt", "r");
    if(f==NULL){
        printf("ERROR");
        exit(0);
    }

    char shown_pass[size+1];

    printf("Your password is:\n");
    while(!feof(f)){
        fgets(shown_pass, sizeof(shown_pass), f); // Dosyadan okuma
        if (shown_pass[0] != '\0') { // Eğer okunan satır boş değilse
            printf("%s", shown_pass); // Okunan şifreyi yazdırma
        }
    }
    fclose(f);
    free(pass);
    return 0;
}

void create_password(int size, char *pass){
    int choice, i;
    for(i=0; i<size; i++){
        choice = rand()%3;
        if(choice == 0)
            pass[i] = rand()%26 +'a';
        
        else if(choice == 1)
            pass[i] = rand()%26 +'A';

        else
            pass[i] = rand()%10 + '0';
    }
    pass[size]='\0';
}