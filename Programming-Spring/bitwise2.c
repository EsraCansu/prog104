// C Program to demonstrate use of bitwise operators
#include <stdio.h>
int main()
{
    // a = 0x80(1000 0000), b = 9(00001001) c=0xC8(1100 1000)
    unsigned char a = 0x80, b = 9;
    //0x80 is a AND mask to check 7th bit (7 6..0)
    // The result is 00000000
    printf("a = %d, b = %d\n", a, b);
    printf("a&b = %d\n", a & b);
 // The result is 10000000
    printf("a = %d, c= %d\n", a, c);
    printf("a&c = %d\n", a & c);    
    
    return 0;
    
}
