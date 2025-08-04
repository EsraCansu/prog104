#include<stdio.h>
#include<stdlib.h>
// 6. karakterin sıfır ya da bir olup olmadığını kontrol etme

void show_bits_str(unsigned char num, char *s);
unsigned char num;
char s[9];
int main(){
    printf("Please enter the number:\n");
    scanf("%hhu",&num);
    show_bits_str(num,s);

    printf("%s\n",s);
    unsigned mask_sixth = 0x40; //0100 0000 
    num = num|mask_sixth;
    show_bits_str(num,s);
    printf("%s\n", s);
    return 0;
}

void show_bits_str(unsigned char num, char *s){
    int i;
    unsigned char mask=0x80; //1000 0000
    for(i=0; i<=7; i++){
        if(num & mask){
            s[i] = '1';
        }
        else{
            s[i] = '0';
        }
        mask = mask/2;
    }
    s[8] = '\0';
}