#include<stdio.h>
#include<time.h>
#include<stdio.h>

void generate_password(char *pass, int length);

int main(){
    int length;
    char *pass;

    printf("Please enter the size of password:\n");
    scanf("%d", &length);

  
    pass = (char*)malloc((length+1)*sizeof(char));
    if(pass==NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));
    generate_password(pass, length);
    printf("Generated password: %s\n", pass);

    free(pass);
    return 0;
}

void generate_password(char *pass, int length){
    int i, choice;
    
    for(i=0; i<length; i++){
        choice = rand()%3;
        if(choice==0){
            pass[i]=rand()%26 + 'a';
        }
        else if(choice==1){
            pass[i]=rand()%26 + 'A';
        }
        else{
            pass[i]=rand()%10 + '0';
        }
    }
    pass[length]='\0';
}