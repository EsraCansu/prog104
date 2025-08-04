#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int randnumber;

void main()
{
	srand(time(0));//before loop
	randnumber=rand();
	printf("%d\n",randnumber);
	//random number between 1-100
	printf("%d\n",randnumber%100);//0-99
	printf("%d\n",randnumber%100+1);
	/*random number between 1-10  10 numbers*/
	printf("%d\n",randnumber%10);//0-9
	printf("%d\n",randnumber%10+1);
	
	//random char between a-z  a:97 z:122 26 chars
	printf("%c\n",randnumber%26+97);
	//random char between A-Z  A:65 Z:90 26 chars
    printf("%c\n",randnumber%26+65);
    printf("%c\n",randnumber%(('Z'-'A')+1)'A');
	getch();
	
}
