// C Program to illustrate text file opening and reading
#include <stdio.h>
#include <stdlib.h>
 
int main()
{   char line[101];
    // file pointer variable to store the value returned by
    // fopen
    FILE* fptr;
 
    // opening the file in read mode
    fptr = fopen("test.txt", "r");
 
    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
        exit(0);
    }
    while(!feof(fptr)){
    	fgets(line,100,fptr);
    	printf("%s",line);
	}
	fclose(fptr);
	getch();
 
    return 0;
}
