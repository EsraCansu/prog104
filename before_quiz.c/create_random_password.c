#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

/* int main(){
    char *p;
    int n, i, upper_counter, lower_counter, number_counter;

    printf("Please enter the size of your password(Size should be between 8-20):\n");
    scanf("%d", &n);
    while(n<8 || n>20){
        printf("Your size is invalid input, so please enter valid value:\n");
        scanf("%d",&n);
    }
    p = (char*)malloc((n+1)*sizeof(int));

    if(p==NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));

    while(upper_counter != n/3 || lower_counter != n/3 || number_counter != n/3){
        for(i=0; i<n; i++){
            int choice = rand()%3;
            if(choice == 0){
                p[i] = rand()%26 + 'a';
                upper_counter++;
            }
            else if(choice == 1){
                p[i] = rand()%26 + 'A';
                lower_counter++;
            }
            else if(choice == 2){
                p[i] = rand()%10 +'0';
                number_counter++;
            }
            p[n] = '\0';
        }
    }

    printf("Generated password: %s\n", p);

    free(p);
    return 0;
} */

int main(){
    char *p;
    char text[100];
    int i, size, lower_counter, upper_counter, number_counter;

    printf("Please enter the text for the size of password:\n");
    fgets(text, sizeof(text), stdin);

    size = strlen(text);

    p = (char*)malloc((size+1)* sizeof(char));

    if(p == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));

    do{
        lower_counter = 0, upper_counter = 0, number_counter = 0;
        for(i=0; i<size; i++){
            int choice = rand()%3;
            if(choice == 0){
                p[i] = rand()%26 + 'A';
                upper_counter++;
            }
            else if(choice == 1){
                p[i] = rand()%26 + 'a';
                lower_counter++;
            }
            else if(choice == 2){
                p[i] = rand()%10 + '0';
                number_counter++;
            }
        }
        p[size] = '\0';
    }
    while(lower_counter != size/3 || upper_counter != size/3 || number_counter != size/3);

    printf("generated password is:\n%s\n", p);

    free(p);
    return 0;
}