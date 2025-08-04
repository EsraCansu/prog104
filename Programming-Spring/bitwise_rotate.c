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
int rotate_left(int b)
{
	int mask1=0x80;
	int mask2=0x01;
	if (b&mask1)
	{
		b=b<<1;
		b=b|mask2;
	}
	else
	   b=b<<1;
	return b;	
}
int main()
{   //b=10010001
    
    int  b=0x91,i;
    //unsigned char---->byte :0..255 8bits
    char s[9];
    showbits(s,b);
    printf("%s\n",s);  
    //left rotate    
    for (i=0;i<=3;i++)
	{	
	   b=rotate_left(b);
       showbits(s,b);
       printf("%s\n",s);   
    }
    
    return 0;    
}
