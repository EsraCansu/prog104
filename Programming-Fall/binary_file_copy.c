// write a C program to copy any file entered from keyboard as another file.
#include <stdio.h>
char buffer[1000];
char source_file[100],target_file[100];
int read_byte;
main(){
	FILE* fptr;
	FILE* fptr2;
    printf("source file:");
    gets(source_file);
    printf("target file:");
    gets(target_file);
    // opening the file in read mode
    fptr = fopen(source_file, "rb");
 
    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
        getch();//wait until a char is pressed
		exit(0);
    }
    fptr2 = fopen(target_file, "wb");
 
    // checking if the file is opened successfully
    if (fptr2 == NULL) {
        printf("The file is not created. The program will "
               "now exit.");
        getch();//wait until a char is pressed
		exit(0);
    }
    while (read_byte=fread(buffer,1,sizeof(buffer),fptr)){
		printf("read_byte:%d \n",read_byte);
    	fwrite(buffer,1,read_byte,fptr2);
    }
    fclose(fptr);
    fclose(fptr2);
    printf("%s file is copied as %s\n",source_file,target_file);
    getch();
}
