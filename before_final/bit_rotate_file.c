#include<stdio.h>
#include<stdlib.h>
void showbits(unsigned char num, char *s);
unsigned char left_rotate(unsigned char num);
unsigned char right_rotate(unsigned char num);

int main(){
    int i;
    unsigned char num, rotated_num; 
    char buffer[9], buffer2[9];
    char s[9], source_file_name[100];
    FILE *source_file, *target_file;

    printf("Please enter the source file name: \n");
    fgets(source_file_name, sizeof(source_file_name), stdin);

    size_t len = strlen(source_file_name);
    if (len > 0 && source_file_name[len - 1] == '\n') {
        source_file_name[len - 1] = '\0';
    }

    source_file = fopen(source_file_name, "wb");
    if(source_file == NULL){
        printf("The file doesn't open.");
        exit(0);
    }

    printf("Please enter the num: \n"); //1001 0100 4+16+128=148
    scanf("%hhu", &num);

    printf("Initial number: ");
    showbits(num, s);
    printf("%s\n", s);
    
    rotated_num = num;
    for(i=0; i<4; i++){
        rotated_num=left_rotate(rotated_num);
        showbits(rotated_num, s);
        printf("%d. left rotate: %s\n", i+1, s);
        fwrite(s, sizeof(unsigned char), 8, source_file);
    }

    rotated_num = num;
    for(i=0; i<4; i++){
        rotated_num=right_rotate(rotated_num);
        showbits(rotated_num, s);
        printf("%d. right rotate: %s\n", i+1, s);
        fwrite(s, sizeof(unsigned char), 8, source_file);
    }
    fclose(source_file);

    source_file = fopen(source_file_name, "rb");
    if(source_file == NULL){
        printf("The file doesn't open.");
        exit(0);
    }

    target_file = fopen("$$temp$$.bin", "wb");
    if(target_file == NULL){
        printf("The file doesn't open.");
        exit(0);
    }

    printf("The file was written as:\n");
    while(fread(buffer, sizeof(unsigned char), 8, source_file)==8){
        fwrite(buffer, sizeof(unsigned char), 8, target_file);
        printf("%s\n", buffer);
    }

    fclose(source_file);
    fclose(target_file);

    remove(source_file_name);
    rename("$$temp$$.bin", source_file_name);
    return 0;
}

void showbits(unsigned char num, char *s){
    int i;
    unsigned char mask = 0x80;
    for(i=0; i<=7; i++){
        if(mask & num){
            s[i] = '1';
        }
        else{
            s[i] = '0';
        }
        mask = mask/2;
    }
    s[8] = '\0';
}
unsigned char left_rotate(unsigned char num){
    unsigned char and_mask = 0x80;
    unsigned char or_mask = 0x01;
    if(num &and_mask){
        num = num<<1;
        num = num|or_mask;
    }
    else{
        num = num<<1;
    }
    return num;
}
unsigned char right_rotate(unsigned char num){
    unsigned char and_mask = 0x80;
    unsigned char or_mask = 0x01;

    if(num & or_mask){
        num = num >>1;
        num = num|and_mask;
    }
    else{
        num = num>>1;
    }
    return num;
}
