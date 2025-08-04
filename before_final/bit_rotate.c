 #include<stdio.h>
#include<stdlib.h>
//0100 0100 = 4+64=68
int left_rotate(unsigned int num);
int right_rotate(unsigned int num);
void showbits(unsigned char num, char *s);
char s[9];
unsigned int num;
int main(){
    int i;
    printf("Please enter the num:\n");
    scanf("%hhu", &num);

    showbits(num,s);
    printf("Your nums binary form is:\n%s\n", s);

    for(i=0; i<=7; i++){
        num = left_rotate(num);
        showbits(num,s);
        printf("%d. left rotate: %s\n", i+1,s);
        }
    for(i=0; i<=7; i++){
        num = right_rotate(num);
        showbits(num,s);
        printf("%d.right rotate: %s\n", i+1,s);
    }
    return 0;
}
void showbits(unsigned char num, char *s){
    int i;
    unsigned int mask = 0x80;

    for(i=0; i<=7; i++){
        if(mask & num)
            s[i] = '1';
        else 
            s[i] = '0';
        
        mask = mask/2;
    }
    s[8] = '\0';
}

int left_rotate(unsigned int num){
    int mask1 = 0x80;
    int mask2 = 0x01;
    if(num & mask1){//yani mesela mask 1100 0001 ise mask1 de zaten 1000 0000  olduğu için bunu andledik ve 1 çıktı döngüye girdi
        num = num<<1; //1100 0001 i 1000 0010 yaptık
        num = num|mask2; // 1000 0010 or 0000 0001 yaptık 1000 0011 oldu çünkü zaten başta en başındaki bir mi onu kontrol etmiştik
    } 
    else{
        num = num<<1;
    }
    return num;
}

int right_rotate(unsigned int num){
    int mask1 = 0x80;
    int mask2 = 0x01;
    if(num & mask2){ // masklar yer değiştirdi dikkat etmekn gerek 
        num = num>>1;
        num = num|mask1;
    }
    else{
        num = num>>1;
    }
    return num;
}
