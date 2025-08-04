#include <stdio.h>
void show_bits(unsigned char number)
{
	unsigned char and_mask=128;//0x80
	int i;
	for (i=0;i<8;i++){
		if (number & and_mask)
		  printf("1 ");
		else
		  printf("0 ");
		and_mask=and_mask/2;
	}
}
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
char s[9];
int main()
{
    printf("number:");
    scanf("%d",&number);
    show_bits(number);
    show_bits_str(number,s);
    printf("\n%s\n",s);
    return 0;
}
