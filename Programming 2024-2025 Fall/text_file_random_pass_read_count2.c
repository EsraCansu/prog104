#include <stdio.h>

//Write a C program to read from password.txt and 
//to find how many numerical and alphabetical chars are used in the file.

        
int main()
{
	char s[22];
	int i, count1, count2,sum_num_count=0,sum_alp_count=0;
	char ch;	    
    FILE* fptr;

    // opening the file in read mode
    fptr = fopen("password.txt", "r");

    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("Cannot open file\n");
        exit(0);       
    }
    while (!feof(fptr)){
    	ch=fgetc(fptr);
    	if (ch>='0'&&ch<='9')
             count1++;
		   else if (ch>='A'&&ch<='Z')	 
		      count2++; 
		   else if (ch>='a'&&ch<='z')	 
		      count2++;    
	}
    fclose(fptr);
    printf("total number of numerical chars:%d\n",count1);
    printf("total number of alphabetical chars:%d\n",count2);
}
