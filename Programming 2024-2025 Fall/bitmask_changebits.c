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
unsigned char mask=0x7F;
char s[9];
int main()
{
    printf("number:");
    scanf("%d",&number);
    show_bits_str(number,s);
    printf("\n%s\n",s);
    //make the bit 0
    //0111 1111=0x7F (the mask to make "7th bit"  0)
    //1111 1111=0xFF
    //&
    //0111 1111=0x7F    
    number=number & mask;//make 7th bit 0
    show_bits_str(number,s);
    printf("\n%s\n",s);
    //mask=1111 1110=0xFE
	mask=0xFE;
    number=number & mask;//make 0th bit 0
    show_bits_str(number,s);
    printf("\n%s\n",s);
    return 0;
}
