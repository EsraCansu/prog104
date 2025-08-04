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
{
    // mask = 0x80(1000 0000)
    //             0100 0000
    //             0010 0000
    //..
    //             0000 0001
    
    int  b,i;
    //unsigned char---->byte :0..255 8bits
    char s[9];
    printf("b:");
    scanf("%d",&b);
    showbits(s,b);
    printf("%s\n",s);    
    return 0;    
}
