// C Program to illustrate text file opening and reading
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int main()
{   char line[101];
    // file pointer variable to store the value returned by
    // fopen
    FILE* fptr;
    FILE* fptr2;
 
    // opening the file in read mode
    fptr = fopen("test.txt", "r");
    
    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
        exit(0);
    }
    //temporary file creation
    fptr2 = fopen("test2.txt", "w");
    if (fptr2 == NULL) {
        printf("The file is not created. The program will "
               "now exit.");
        exit(0);
    }
    while(!feof(fptr)){
    	fgets(line,100,fptr);
    	fprintf(fptr2,"%s",strupr(line));
    	printf("%s",strupr(line));
	}
	fclose(fptr);
	fclose(fptr2);
	//delete and rename files
	remove("test.txt");
	rename("test2.txt","test.txt");
	getch();
 
    return 0;
}
