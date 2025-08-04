#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *source_file;
    FILE *target_file;
    char source_file_name[100], target_file_name[100];
    int i, count=0;
    unsigned char buffer[100];

    printf("Please enter the name of source file:\n");
    fgets(source_file_name, sizeof(source_file_name), stdin);
    source_file = fopen(source_file_name, "rb");
    if(source_file_name==NULL){
        printf("ERROR");
        exit(0);
    }

    printf("Please enter the name of target file:\n");
    fgets(target_file_name, sizeof(target_file_name), stdin);
    target_file = fopen(target_file_name, "wb");
    if(target_file_name==NULL){
        printf("ERROR");
        exit(0);
    }
    
    while(feof(source_file)){
        count = fread(buffer, sizeof(unsigned char), 1, source_file);
        fwrite(buffer, sizeof(unsigned char), count, target_file);
    }

    printf("The source file written in target file\n");
    fclose(source_file);
    fclose(target_file);
    return 0;
}