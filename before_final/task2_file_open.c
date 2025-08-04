#include<stdio.h>
#include<stdlib.h>
//çalışmıyor.
int main(){
    FILE *f;
    char text[500];
    char text1[500];
    int i;

    f=fopen("output.txt", "w");
    if(f==NULL){
        printf("ERROR");
        exit(0);
    }

    printf("please enter the text 5 lines:\n");
    for(i=0; i<5; i++){
        printf("%d. Line:", i+1);
        fgets(text, sizeof(text), stdin);

        printf(f,"%s",text);
    }

    fclose(f);

    printf("Your text has been written\n");

    f=fopen("output.txt", "r");
    if(f==NULL){
        printf("ERROR");
        exit(0);
    }

    while(!feof(f)){
        fgets(text1, sizeof(text1), f);
        printf("%s", text1);
    }

    fclose(f);
    return 0;
}