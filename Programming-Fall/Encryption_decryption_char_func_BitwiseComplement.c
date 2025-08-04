#include <stdio.h>
#include <string.h>
void encryption(char * message){
    int i;	
	for (i=0;i<strlen(message);i++){
		 message[i]=~message[i];//Bitwise complement
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
