#include <stdio.h>
#include <string.h>
void encryption(char * message){
    int i;	
	for (i=0;i<strlen(message);i++){
		if (message[i]=='A')
		   message[i]='Z';
		else if (message[i]=='B')
		   message[i]='Y';
		else if (message[i]=='Z')
		   message[i]='A';
		else if (message[i]=='Y')
		   message[i]='B';
	} 
}

void decryption(char * message){
     int i;	
	 for (i=0;i<strlen(message);i++){
		if (message[i]=='Z')
		   message[i]='A';
		else if (message[i]=='Y')
		   message[i]='B';
		else if (message[i]=='A')
		   message[i]='Z';
		else if (message[i]=='B')
		   message[i]='Y';   
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
	decryption(message);
	printf("decrypted message:%s\n",message);
	getch();
}
