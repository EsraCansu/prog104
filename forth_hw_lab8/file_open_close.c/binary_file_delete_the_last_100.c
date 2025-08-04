#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *source_f, *target_f;
    int count, size=0;
    char source_file_name[100], target_file_name[100];
    long int file_size;
    unsigned char buffer[100];

    printf("Please enter the name of file:\n");
    fgets(source_file_name, sizeof(char), stdin);

    printf("Please enter the name of target file:\n");
    fgets(target_file_name, sizeof(char), stdin);

    source_f = fopen(source_file_name, "rb");
    if(source_f==NULL){
        printf("ERROR");
        exit(0);
    }

    fseek(source_f, 0, SEEK_END);
    file_size = ftell(source_f); //ftell:dosya işaretçisinin bulunduğu yerin başlangıçtan itibaren kaç bayt uzaklıkta olduğunu belirtir
    rewind(source_f); // dosyayı tekrar dosyanın başına getirir

    if(file_size <= 100){
        printf("ERROR: file size is less or equal tthan 100 bytes");
        fclose(source_f);
        exit(0);
    }
    
    target_f = fopen(target_file_name, "wb");
    if(target_f==NULL){
        printf("ERROR");
        exit(0);
    }
    while(size<(file_size-100)){
        count=fread(buffer,sizeof(unsigned char),100,source_f);
        fwrite(buffer,sizeof(unsigned char), count, target_f);
        size++;
    }

    fclose(source_f);
    fclose(target_f);
    return 0;
}