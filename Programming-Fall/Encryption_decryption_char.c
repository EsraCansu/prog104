#include <stdio.h>
main()
{
	char message[100];
	int i;
	
	printf("message:");
	gets(message);
	//encryption
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
	printf("encrypted message:%s\n",message);
	
	//decryption
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
	printf("decrypted message:%s\n",message);
	getch();
}
