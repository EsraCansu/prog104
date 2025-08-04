/* change all a-z chars to A-Z chars inside password.txt */
#include <stdio.h>
void upperpass(char * password)
{
	int length;
	int i;
	length=strlen(password);
	for (i=0;i<length;i++)
	{
		if (password[i]>='a'&&password[i]<='z')
		  password[i]=password[i]-('a'-'A');
	}
}
void lowerpass(char * password)
{
	int length;
	int i;
	length=strlen(password);
	for (i=0;i<length;i++)
	{
		if (password[i]>='A'&&password[i]<='Z')
		  password[i]=password[i]+('a'-'A');
	}
}
main()
{
	char password[21];
	FILE * passfile1, * passfile2;
	passfile1=fopen("password.txt","r");
	if (passfile1==NULL)
	{
		printf ("we cannot open the file \n");
		exit(1);
	}
	passfile2=fopen("$$pw.txt","w");
	if (passfile2==NULL)
	{
		printf ("we cannot write the file \n");
		exit(0);
	}
	while(!feof(passfile1))
	{
		if (fgets(password,20,passfile1))
		{		
		  lowerpass(password);
		  fprintf(passfile2,"%s",password);
	   }
	}
	fclose(passfile1);
	fclose(passfile2);	
	remove("password.txt");
	rename("$$pw.txt","password.txt");	
}
