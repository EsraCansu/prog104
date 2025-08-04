#include <stdio.h>
#include <string.h>
void encryption(char * message){
    int i;	
    //Hex: 0 1..9 A B C D E F
    char mask=0xFF;//1111 1111=0xFF=255  
	for (i=0;i<strlen(message);i++){
		 message[i]=message[i]^mask;//Bitwise XOR
	}
}
main()
{
	char message[100];
		
	printf("message:");
	gets(message);
	//encryption
	encryption(message);
	
	printf("encrypted message:%s\n",message);
	
	//decryption :reverse operations are carried out
	encryption(message);//apply bitwise complement again
	printf("decrypted message:%s\n",message);
	getch();
}
