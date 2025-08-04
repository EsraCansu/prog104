#include <stdio.h>
#include <stdlib.h>
#include <time.h>

//Write a C program to produce random chars between 0-9 at each line
//the number of chars at each line will be also random
//total number of lines will be 100
//use fputc

int main()
{
	char ch;
	int i,j;
	int number_of_char;
	srand(time(0));// initialize random seed before loop
	    
    FILE* fptr;

    // opening the file in read mode
    fptr = fopen("numbers.txt", "w");

    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("Cannot open file\n");
        exit(0);       
    }
    for (i=0;i<100;i++){
       number_of_char=rand()%20+1; //1-20
       for (j=0;j<number_of_char;j++){
       	  ch=rand()%10+'0';
       	  fputc(ch,fptr);
	   }
	   fputc('\n',fptr);               
	}
    fclose(fptr);
    printf("random numbers are written!!!");
}
