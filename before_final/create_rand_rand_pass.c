#include<stdio.h>
#include<time.h>

void create_pass(char *s, int size);

/*int main(){ //text file 
    int i, size;
    char *s;
    FILE *f;

    f=fopen("final_pass.txt", "w");
    if(f == NULL){
        printf("File doesnt't open");
        exit(0);
    }
    srand(time(NULL));
    for(i=0; i<10; i++){
        size=rand()%10;
        s =(char*)malloc((size+1)*sizeof(char));

        if(s==NULL){
            printf("Memory allocation failed");
            exit(0);
        }
        create_pass(s, size);
        printf("%s\n",s);
        fprintf(f, "%s\n",s);
        free(s);    
    }
    fclose(f);

    f=fopen("final_pass.txt", "r");
    if(f == NULL){
        printf("File doesnt't open");
        exit(0);
    }

    printf("Password is written:\n");
    while(fgets(s, sizeof(s),f) != NULL){
        printf("%s",s);
    }

    fclose(f);
    return 0;
}*/


int main(){ //binary file 
    int i, size;
    char *s;
    FILE *f;

    f=fopen("final_pass.txt", "wb");
    if(f == NULL){
        printf("File doesnt't open");
        exit(0);
    }
    srand(time(NULL));
    for(i=0; i<10; i++){
        size=rand()%10+1;
        s =(char*)malloc((size+1)*sizeof(char));
        if(s==NULL){
            printf("Memory allocation failed");
            exit(0);
        }
        create_pass(s, size);
        printf("%s\n",s);
        fwrite(s, sizeof(char), size,f);
        free(s);    
    }
    fclose(f);

    f=fopen("final_pass.txt", "rb");
    if(f == NULL){
        printf("File doesnt't open");
        exit(0);
    }
    
    char buffer[100];
    printf("Password is written:\n");
    while(fread(buffer, sizeof(char), sizeof(buffer)-1, f)>0){
        buffer[sizeof(buffer)-1] = '\0';
        printf("%s\n",buffer);
    }

    fclose(f);
    return 0;
}

void create_pass(char *s, int size){
    int choice, i;

    for(i=0; i<size; i++){
        choice=rand()%3;

        if(choice == 0){
            s[i] = rand()%26 + 'a';
        }
        if(choice == 1){
            s[i] = rand()%26 + 'A';
        }
        else{
            s[i] = rand()%10 + '0';
        }
    }
    s[size] = '\0';
}