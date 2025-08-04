#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *source_f, *target_f;
    int count, sum=0;
    unsigned char buffer[100];
    char source_file_name[100];
    
    printf("Please enter the name of file:\n");
    gets(source_file_name);

    source_f = fopen(source_f,"rb");
    target_f = fopen("$$temp.dat","wb");

    if(source_f == NULL || target_f == NULL){
        printf("ERROR");
        exit(0);
    }

    int file_length =filelength(fileno(source_f));
    while(sum<(file_length/2) && sum>(file_length/2)+100){
        count = fread(buffer, sizeof(unsigned char), 100, source_f);
        fwrite(buffer, sizeof(unsigned char), count, target_f);
        sum++;
    }

    fclose(source_f);
    fclose(target_f);
    remove(source_f);
    rename("$$.temp.dat", source_f);
    return 0;
}