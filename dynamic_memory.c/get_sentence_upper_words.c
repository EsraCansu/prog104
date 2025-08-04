#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<ctype.h>

// kullanıcıdan cümle sayısı isteyin cümleleri girdileyin
// daha sonra cümleleri büyük yazarak çıktılayın

// çıktısı alınan harfler sesli harfse sayın
int sesli_harf_counter(char *text, int *size, int *counter);

int main(){
    int i, sentence_counter=0, counter=0;
    char *p[100];
    char text[100];

    printf("Please enter the num of your sentences:\n");
    scanf("%d\n", &sentence_counter);

    while(getchar() != '\n');

    for(i=0; i<sentence_counter; i++){
        printf("Please enter the text(the size should be less than 100):\n");
        fgets(text, sizeof(text), stdin);

        int size = strlen(text);
        if(text[size-1] ='\n'){
            text[size-1] ='\0';
        }

        p[i] = (char*)malloc((size+1)*sizeof(char));

        if(p == NULL){
            printf("ERROR");
            exit(0);
        }

        strcpy(p[i],text);
        sesli_harf_counter(text, &size, &counter);
    }

    for(i=0; i<sentence_counter; i++){
        printf("%s\n", p[i]);
    }

    printf("Counter is: %d\n", counter);

    for(i=0; i<sentence_counter; i++){
        free(p[i]);
    }

    return 0;
}

int sesli_harf_counter(char *text, int *size, int *counter){
    int i;
    *counter =0;

    for(i=0; text[i]; i++){
        text[i] = tolower(text[i]);
        if(text[i] == 'A'|| text[i] == 'E'|| text[i] == 'I'|| text[i] == 'U'|| text[i] == 'O'){
           *(counter++);
        }
    }
    return *counter;
}