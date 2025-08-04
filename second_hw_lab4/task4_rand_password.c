#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int size, i, choice;
    char *password;
    int upper_counter=0, lower_counter=0, number_counter=0;

    printf("Please enter a size of password, it's should be greater than 8: ");
    scanf("%d", &size);

    while(size<8){
        printf("Please enter a size of at least 8: \n");
        scanf("%d", &size);
    }

    password = (char*)malloc(size*sizeof(char));

    if(password == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));

    while(upper_counter ==0 || lower_counter == 0|| number_counter == 0){
        for(i=0; i<size; i++){
            choice = rand()%3;
            if(choice == 0){
                password[i] = rand()%26 + 'a';
                lower_counter++;
            }
            else if(choice == 1){
                password[i] = rand()%26 + 'A';
                upper_counter++;
            }
            else if(choice == 2){
                password[i] = rand()%10 + '0';
                number_counter++;
            }
            password[size] = '\0';
        }
    }

    printf("Generated password: %s\n", password);

    free(password);
    return 0;
}
