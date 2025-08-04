/* list the all passwords in password.txt*/
#include <stdio.h>
main()
{
	FILE * passfile;
	char password[21];
	passfile=fopen("password.txt","r");
	if (passfile==NULL)
	{
		printf("we cannot open the file\n");
		exit(1);
	}
	while (!feof(passfile))
	{
		fgets(password,20,passfile);
		printf("%s",password);
	}
	fclose(passfile);
}
