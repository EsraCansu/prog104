/* #include<stdio.h>
#include<string.h>
//write a c program to read from random password.txt and to find password having 5 or more numerical chars

int pass_num_count(char *p){
    int i, count=0;

    for(i=0; i<strlen(p); i++){
        if(p[i]>='0' && p[i]<='9'){
            count++;
        }
    }
    return count;
}

int main(){
    char p[22];
    int i;
    FILE* f;

    f = fopen("password.txt", "r");

    // checking if the file is created
    if (f == NULL){
        printf("The file is not opened. The program will exit now");
        exit(0);
    }
    printf("The file is opened Successfully.");

    int count;
    while(!feof(f)){
        if(fgets(f, 22,p)){
            count = pass_num_count(p);
        }
        if(count>=5){
            printf("%s",p);
        }
    }
    fclose(f);
    return 0;
}
 */


#include<stdio.h>
#include<string.h>
//write a c program to read from random password.txt and to find how many char and num

void pass_num_count(char *p, int *num_count, int *alp_count){
    int i, count1=0, count2=0;

    for(i=0; i<strlen(p); i++){
        if(p[i]>='0' && p[i]<='9'){
            count1++;
        }
        else{
            count2++;
        }
    }
    *num_count = count1;
    *alp_count = count2;
}

int main(){
    char p[22];
    int i, num_count, alp_count, sum_num_count, sum_alp_count;
    FILE* f;

    f = fopen("password.txt", "r");

    // checking if the file is created
    if (f == NULL){
        printf("The file is not opened. The program will exit now");
        exit(0);
    }
    printf("The file is opened Successfully.");

    int count;
    while(!feof(f)){
        if(fgets(f, 22,p)){
            pass_num_count(p, &num_count, &alp_count);
            sum_num_count += num_count;
            sum_alp_count += alp_count;
        }
    }
    printf("Total number of numerical char: %d\n", sum_num_count);
    printf("Total number of alph char: %d\n", sum_alp_count);

    fclose(f);
    return 0;
}