#include<stdio.h>
#include<stdlib.h>
#include<time.h>

//random passwords

char *random_password(char *password);

int main(){
    int j;
    char *password;

    password=(char*)malloc(100*sizeof(char));

    if(password==NULL){
        printf("Error!");
        exit(0);
    }

    srand(time(NULL));
    password = random_password(password); //sorun yeniden tamlamamaktaymış

    
    printf("password:");
    for(j=0; j<100; j++){
        printf("%c",password[j]);
        if((j+1) % 10 == 0){
            printf("\n"); // burada sorun yaşanıyor
        }
    }
 
    free(password);
    return 0;
}

char *random_password(char *password){
    int i;

    for(i=0; i<100; i++){
        password[i]=rand()%(126-33+1)+33;
  
    }
    
    return password;
}