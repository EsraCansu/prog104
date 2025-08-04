#include <stdio.h>
#include <string.h>

//if the 7th bit of a number (0-255) entered from keyboard is 1 then make 5th bit 1 and make 3rd bit 0
void display_bits(unsigned char number,char * s)
{
int i,j;
int mask=128; //7th

for (j=0,i=7;i>=0;i--,j++){
	if (number&mask)
	   s[j]='1';
	else
	   s[j]='0';
	mask=mask/2;
}
s[j]='\0';//null char
}
unsigned char number;
char s[9];
int mask;
main(){
  printf("number (0-255):");
  scanf("%d",&number);
  display_bits(number,s);
  printf("%s\n",s);
  
  mask=128;//and mask to control 7th bit 
  if (number&mask){
  	//0010 0000=0x20 or mask to make 5th bit 1
  	mask=0x20;
  	number=number|mask;
  	//1111 0111=0xF7 and mask to make 3rd bit 0
  	mask=0xF7;
  	number=number&mask;
  	
	display_bits(number,s);
    printf("%s\n",s);
  }

  getch();
}
