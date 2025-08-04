#include <stdio.h>
#include <string.h>
//0x --->hex
int number=0xF1; //1111 0001

//AND mask:- bit control
//         - make the bit zero :
//0111 1111  mask=0x7F
//1111 0001 &
//0111 0001 0x71

//OR mask:-make the bit 1
//0000 1000 OR mask 0x08
//1111 0001 |
//1111 1001 0xF9

main(){
int i;
number=0xF1;
int mask=0x7F;
printf("0x%x\n",number&mask);

number=0xF1;
mask=0x08;
printf("0x%x\n",number|mask);
getch();
}
