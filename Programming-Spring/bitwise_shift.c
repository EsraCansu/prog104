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
{   //b=10001000
    
    int  b=0x88,i;
    //unsigned char---->byte :0..255 8bits
    char s[9];
    showbits(s,b);
    printf("%s\n",s);  
    //right shift    
    showbits(s,b>>1);
    printf("%s\n",s);    
    //left shift    
    showbits(s,b<<1);
    printf("%s\n",s); 
    return 0;    
}
