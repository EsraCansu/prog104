#include <stdio.h>
#include <stdlib.h>
//Write a C program to find the maximum and minimum of numbers in numbers.txt
//each line includes a number

int main()
{
		//long int
	float number,max, min;
	int counter=0;
	    
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
    	if (counter==0)  {
	    	min=number;
	    	max=number;
		}
		counter++;
    	if (number>max)
    	   max=number;
    	if (number<min)
    	   min=number;
	}
	printf("the max of numbers:%25.f\n",max);
	printf("the min of numbers:%25.f\n",min);
	fclose(fptr);
}
