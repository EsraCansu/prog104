#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<string.h>

int rand_pass(int *p, int size){
    int choice, i;

    for(i=0; i<size; i++){
        choice = rand()%3;
        if(choice==0)
            p[i] = rand()%26 + 'a';

        else if(choice==1)
            p[i] = rand()%26 + 'A';

        else
            p[i] = rand()%10 + '0';
    }
    p[size]='\0';
}
int main(){
    int size;
    FILE *f;
    char *p;
    printf("Please enter the size of your password:\n");
    scanf("%d", &size);

    p = (char*)malloc((size+1)*sizeof(char));
    if(p==NULL){
        printf("ERROR");
        exit(0);
    }

    f=fopen("PassWords.txt", "w");
    if(f==NULL){
        printf("ERROR");
        free(p);
        exit(0);
    }

    srand(time(NULL));
    rand_pass(p, size);
    fprintf(f, "%s\n", p);

    printf("The passwords written successfully");
    fclose(f);
    free(p);
    return 0;
}

