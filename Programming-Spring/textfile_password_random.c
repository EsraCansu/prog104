/* generate 100 passwords randomly. 
   each password will be length 20, including a-z,0-9 chars
   later, write all passwords to a text file in way that
   each line includes one password.
*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void genpassword(char * password)
{
	int i;
	for (i=0;i<20;i++)
	{
	
	  int category;
	  category=rand()%2;
	  if (!category)
	     password[i]=rand()%26+'a';
	  else
	     password[i]=rand()%10+'0';	   
    }
    password[20]='\0';
}
main()
{
	int i;
	FILE * passfile;
	char password[21];
	srand(time(NULL));
	passfile=fopen("password.txt","w");
	if (passfile==NULL)
	{
		printf("We cannot create the password file \n");
		exit(0);
	}
	for (i=0;i<100;i++)
	{
		genpassword(password);
		fprintf(passfile,"%s\n",password);
	}
	fclose(passfile);
}
