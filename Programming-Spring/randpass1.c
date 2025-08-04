#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
char pass[21];//strings are ended with null char '\0'

// '\0':0
// '0' :48
// '9' :57
// 'A' :65
main()
{
	srand(time(0));
	int category;
	int randnumber;
	char ch;
	int i;
	for(i=0;i<20;i++)
	{
	
		category=rand()%2;//0-1
	
		if (category==0) //a-z
	  		randnumber=rand()%26+97;
		else  //A-Z
		//generate a random password of length 20, including chars between a-z or A-Z
	  		randnumber=rand()%26+65;
	  		pass[i]=randnumber;	    
    }
    pass[20]='\0'; //null char
    printf("%s\n",pass);
}
