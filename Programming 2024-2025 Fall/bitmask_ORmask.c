#include <stdio.h>
void show_bits_str(unsigned char number, char *s)
{
	unsigned char and_mask=128;//0x80
	int i;
	for (i=0;i<8;i++){
		if (number & and_mask)
		  s[i]='1';
		else
		  s[i]='0';
		and_mask=and_mask/2;
	}
	s[8]='\0';
}
unsigned char number;
unsigned char mask=0x80;
char s[9];
int main()
{
    printf("number:");
    scanf("%d",&number);
    show_bits_str(number,s);
    printf("\n%s\n",s);
    //make the bit 1
    //1000 0000=0x80 (the mask to make "7th bit"  1)
    //0111 1111=0x7F
    //|
    //1111 1111=0xFF   
    number=number | mask;//make 7th bit 1
    show_bits_str(number,s);
    printf("\n%s\n",s);
    //mask=0100 0000=0x40
    mask=0x40;
    number=number | mask;//make 6th bit 1
    show_bits_str(number,s);
    printf("\n%s\n",s);
    
    return 0;
}
