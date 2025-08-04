#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Write a C program to produce 100 random passwords of length 20 and to write them to a text file.

void rand_pass(char *s)     {
	int i, category;

        for (i = 0; i < 20; ++i) {
           category=rand()%3;//0..2
           if (category==0)
              s[i] = rand()%26+'a';  //a-z:26 chars   
           else if (category==1)
              s[i] = rand()%26+'A';  //A-Z:26 chars  
		   else
		      s[i] = rand()%10+'0';  //0-9:10 chars  
		          
        }
        s[20]='\0';
}
int main()
{
	char s[21];
	int i;
	srand(time(0));// initialize random seed before loop
	    
    FILE* fptr;

    // opening the file in read mode
    fptr = fopen("password.txt", "w");

    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("Cannot open file\n");
        exit(0);       
    }
    for (i=0;i<100;i++){
      rand_pass(s);	
      fprintf(fptr,"%s\n",s);      
	}
    fclose(fptr);
    printf("random password are written!!!");
}
