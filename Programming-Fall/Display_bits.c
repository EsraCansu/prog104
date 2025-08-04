#include <stdio.h>
#include <string.h>
//0x --->hex
int number=0x1A; //0001 1010
//0001 1010
//1000 0000 &
//0000 0000

//1001 1010
//1000 0000 & mask=128=0x80
//1000 0000

//1001 1010
//0100 0000 & mask=128=0x80
//0000 0000

main(){
int i;
int mask=128;//7th bit

for (i=7;i>=0;i--){
	if (number&mask)
	   printf("1");
	else
	   printf("0");
	mask=mask/2;
}
  getch();
}
