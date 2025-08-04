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
int rotate_right(int b,int n)
{
	int i;
	int mask_and=0x01;
	int mask_or=0x80;
	for (i=0;i<n;i++)
	{
	
	   if (b&mask_and)
	   {
		  b=b>>1;
		  b=b|mask_or;
	   }
	   else
	     b=b>>1;
    }
	return b;	
}
int main()
{   //b=10010001
    
    int  b=0x91,i;
    //unsigned char---->byte :0..255 8bits
    char s[9];
    showbits(s,b);
    printf("%s\n",s);  
    //right rotate      
	b=rotate_right(b,4);
    showbits(s,b);
    printf("%s\n",s);   
	
	printf("\n");
	for(i=0;i<4;i++)   
	{
       b=rotate_right(b,1);
       showbits(s,b);
       printf("%s\n",s);  
	}
    
    return 0;    
}
