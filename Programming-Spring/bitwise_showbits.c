// C Program to demonstrate use of bitwise operators
#include <stdio.h>
int main()
{
    // mask = 0x80(1000 0000)
    //             0100 0000
    //             0010 0000
    //..
    //             0000 0001
    
    unsigned int mask = 0x80, b,i;
    //unsigned char---->byte :0..255 8bits
    
    printf("b:");
    scanf("%d",&b);
    for(i=0;i<=7;i++)
	{
		if (b&mask)
		  printf("1");
		else
		  printf("0");
		mask=mask/2;
	}    
    
    return 0;    
}
