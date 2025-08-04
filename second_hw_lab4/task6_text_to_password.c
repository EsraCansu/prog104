#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

// generate rand pass till 99, store the entered text and consisting
// of equal numbers of lower letters, uppercase letters and numbers
/* kullanıcıdan text istenecek onun uzunluğunda ve eşit sayıda olacak şekilde
büyük-küçük harf ve number'dan oluşan en fazla 99 karakter içeren password
oluşturulmalı. Bu yüzden üçe bölünen sayıların uzunluğunda input alınmalı*/

int main(){
    char *p;
    char text[99];
    int i, size;
    int lower_letter_counter, upper_case_counter, number_counter;

    do{
        printf("Please enter the text(the length should be equal and less than 99): \n");
        fgets(text, sizeof(text), stdin);

        size = strlen(text);

        if(text[size-1] == '\n'){
            text[size-1] ='\0';
            size--;
        }

        if(size >= 99 || size%3 != 0){
            printf("Your input length is invalid. It must be divisible by 3 and less than 99.\n");
        }
    }
    while(size >= 99 || size%3 != 0);

    p = (char*)malloc(sizeof(char)*size);

    if(p == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));

    do{
        lower_letter_counter=0, upper_case_counter=0, number_counter=0;

         for(i=0; i<size; i++){
                int choice = rand()%3;

                if(choice == 0){
                    p[i] = rand()%26 + 'A';
                    upper_case_counter++;
                }
                else if(choice == 1){
                    p[i] = rand()%26 + 'a';
                    lower_letter_counter++;
                }
                else if(choice == 2){
                    p[i] = rand()%10 +'0';
                    number_counter++;
                }
            }
            p[size]='\0';
    }
    while(lower_letter_counter != size/3 || upper_case_counter != size/3 || number_counter != size/3);

    printf("Your password is:\n%s\n", p);

    free(p);
    return 0;
}