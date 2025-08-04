#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//write a c program to produce 100 random password of length 20 and to write then to a text file
void rand_pass(char *f){
    int i;

    for(i=0; i<20; i++){
        int category=rand()%3;
        if(category==0)
            f[i]= rand()%26+'a';
        
        else if(category==1)
            f[i]= rand()%26+ 'A';

        else
            f[i]= rand()%10 +'0';
    }

    f[20]='\0';
}


int main(){
    char p[21];
    int i;
    srand(time(NULL));
    FILE* f;

    f = fopen("password.txt", "w");

    // checking if the file is created
    if (f == NULL){
        printf("The file is not opened. The program will exit now");
        exit(0);
    }
    printf("The file is created Successfully.");

    for(i=0; i<100; i++){
        rand_pass(p);
        fprintf(f,"%s\n", p);
    }
    
    fclose(f);
    return 0;
}