#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *f;
    int i;
    char sentence[100];
    char shown_sentence[100];

    f=fopen("output.txt", "w");
    if(f==NULL){
        printf("The text doesn't exist");
        exit(0);
    }

    printf("Please enter the sentence:\n");
    for(i=0; i<5; i++){
        fgets(sentence, sizeof(sentence), stdin);
        fprintf(f, "%s", sentence);
    }
    fclose(f);

    f = fopen("output.txt", "r");
    if(f == NULL){
        printf("The file didn't open");
        exit(0);
    }

    //while(!feof(f)){
      //  fgets(shown_sentence, sizeof(shown_sentence), f);
        // printf("%s", shown_sentence);
    //}
    printf("The content of your sentence:\n");
    while(fgets(shown_sentence, sizeof(shown_sentence),f) != NULL){ // dosyanın içeriğinin de kontrol edilmesini sağlar
        printf("%s", shown_sentence);
    }

    fclose(f);
    return 0;
}