// write a C program to create a text file whose each line contains a random password of a-z, 0-9 characters 
//with a length 0f 20
//100 rows are required.
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void rnd_pass(char *s,int n)
{
	int i, category;	
	
	for(i=0;i<n;i++){
	   category=rand()%2; //0-1
	   if (category==0)	   
		   s[i]=rand()%10+48;
	   else if (category==1)	   
		   s[i]=rand()%26+97;
    }
	s[n]='\n';      
	s[n+1]='\0'; 
}
void text_rnd_password(char * filename,int rownumber){
	FILE* fptr;
	int i;
    char password[22];
    
    // opening the file in read mode
    fptr = fopen("rnd_password.txt", "w");
 
    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("The file is not created. The program will "
               "now exit.");
        exit(0);
    }
    for (i=0;i<rownumber;i++){
    	rnd_pass(password,20);
    	fprintf(fptr,password);
	}
	fclose(fptr);
}
main(){
	srand(time(0));//before loop
	text_rnd_password("rand_pass_text.txt",100);
	printf("password file is created with 100 rows!");
	getch();
}
