#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int main(){
    char *p[100];
    char text[100];
    int i;

    printf("Please enter the text(the size shold be less than 100):\n");
    fgets(text, sizeof(text), stdin);

    int size = strlen(text);
    if(text[size-1] == '\n'){
        text[size-1] = '\0';
        size--;
    }

    for(i=0; i<size; i++){
        p[i] = (char*)malloc((size+1)*sizeof(char));

        if(p[i] == NULL){
        printf("ERROR");
        exit(0); 
        }
        strcpy(p[i], text);
    }


    printf("The new form:\n");
    for(i=0; i<size; i++){
        printf("%s\n", p[i]);
    }

    for(i=0; i<size; i++){
        free(p[i]);
    }

    return 0;
}