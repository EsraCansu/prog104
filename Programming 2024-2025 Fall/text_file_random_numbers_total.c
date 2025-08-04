#include <stdio.h>
//Write a C program to find the sum of numbers in numbers.txt
//each line includes a number

int main()
{
	char ch;
	int i,j;
	//long int
	float number,sum=0;
	
	    
    FILE* fptr;

    // opening the file in read mode
    fptr = fopen("numbers.txt", "r");

    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("Cannot open file\n");
        exit(0);       
    }
    while (!feof(fptr)){
    	fscanf(fptr,"%f",&number);
    	sum=sum+number;
	}
	printf("the sum of numbers:%25.f\n",sum);
	fclose(fptr);
}
