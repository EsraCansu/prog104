#include<stdio.h>
#include<stdlib.h>
#include<time.h>

/* char password(char *p, int element);

int main(){
    int i, element, j;
    char *p;

    printf("Please enter the size of your password\n");
    scanf("%d", &element);

    p=(char*)malloc(element*sizeof(char));

    if(p==NULL){
        printf("Error!");
        exit(0);
    }

    srand(time(NULL));
    password(p, element);

    printf("Your password is: \n");

    for(i=0; i<element; i++){
        printf("%c", p[i]);
        if((i+1)%10 == 0){
            printf("\n");
        }
    }

    printf("\nThe new passwords: \n");

    for(i=0; i<element; i++){
        printf("%c", p[i]);
        if((i+1)%10 == 0){
            printf("\n");
        }
    }

    free(p);
    return 0;
}

char password(char *p, int element){
    int i;

    for(i=0; i<element; i++){
        int rand_password = rand()%62; // total of 62 alphanumeric characters
        if(rand_password<10){
            p[i]='0' + rand_password; //'0' to '9'
        }

        else if(rand_password<36){
            p[i]='A'+(rand_password - 10); // 
        }

        else{
            p[i]= 'a'+(rand_password -36); //
        }
    }
    return password;
}
 */


int rand_num(int *p, int element);
int most_repeated(int *p, int element);

int main(){
    int i ,element=0, counter=0;
    int *p;

    printf("Please enter for random numbers size: \n");
    scanf("%d", &element);

    p = (int*)malloc(element*sizeof(int));

    if(p == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));

    printf("The random numbers:\n");
    rand_num(p, element);
    for(i=0; i<element; i++){
        printf("%d\n", p[i]);
    }
    int most_num = most_repeated(p, element);
    printf("The most repeating number: %d\n", most_num);

    free(p);
    return 0;
}

int rand_num(int *p, int element){
    int i;

    for(i=0; i<element; i++){
        p[i]=rand()%100;
    }

    return 0;
}
int most_repeated(int *p, int element){
    int i, j;
    int max_count=0;
    int most_count=p[0];


    for(i=0; i<element; i++){
        int count = 0;
        for(j<0; j=element; j++){
            if(p[i] == p[j]){
                count++;
            }
        }
        if(count>max_count){
            max_count = count;
            most_count = p[i]; 
        }
    }

    return most_count;
}




