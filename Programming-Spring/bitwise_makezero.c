// C Program to demonstrate use of bitwise operators
#include <stdio.h>
void showbits(char *s,int number)
{   int i;
    unsigned int mask = 0x80;
	for(i=0;i<=7;i++)
	{
		if (number&mask)
		  s[i]='1';
		else
		  s[i]='0';
		mask=mask/2;
	} 
	s[8] ='\0'; 
}
int main()
{   //how to make a bit zero
    // Hex decimals: 0..9 A B C D E F
    // 1111--->F
    // mask  = 0xEF(1110 1111)
    // b     =0xB8 (1011 1000)
    
    int  b=0xB8,i, mask=0xEF;
    //unsigned char---->byte :0..255 8bits
    char s[9];
    showbits(s,b);
    printf("%s\n",s);  
    b=b&mask;
    showbits(s,b);
    printf("%s\n",s);    
    return 0;    
}
