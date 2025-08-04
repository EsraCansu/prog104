#include <stdio.h>
int main()
{
    //AND masks
    //1. bit control
    //2. make the bit zero
    //bit control
    //mask=10000000=128 (decimal)=0x80 (hex) (7th bit control mask)
    //mask=01000000=64=0x40 (6th bit control mask)
    int and_mask=0x80;//7th bit control mask
    int number=0xC1; //1100 0001
    int number2=0x41;//0100 0001
    //check whether 7th is 1 or 0 (bits are numbered from 0 to 7, from right to left)
    //mask=  10000000=128 (decimal)=0x80 (hex) (7th bit control mask)
    //number=11000001
    //&
    //result=128--->true (7th bit of number 1!!!)
    if (number & and_mask)
       printf("7th bit of number is 1\n");
    else
       printf("7th bit of number is 0\n");
    
    return 0;
}
