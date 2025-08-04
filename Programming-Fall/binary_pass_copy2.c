//rnd_password.txt
//100 rows 
//each row:20 char password+\n
//write a c program to write last 50 passwords to rnd_pass_bin.dat file by using binary file logic.
//ofset=22*(row-1)
//offset of 51th row=22*50
#include <stdio.h>
char buffer[50*22];
char buffer2[22];
char eof=26;
main(){
	FILE* fptr;
	FILE* fptr2;
	int i;
 
    // opening the file in read mode
    fptr = fopen("C:\\Users\\MetaOgretici\\Documents\\Programming\\rnd_password.txt", "rb+");
 
    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("The file is not opened. The program will "
               "now exit.");
        getch();//wait until a char is pressed
		exit(0);
    }
    fptr2 = fopen("C:\\Users\\MetaOgretici\\Documents\\Programming\\rnd_pass_bin.dat", "wb");
 
    // checking if the file is opened successfully
    if (fptr2 == NULL) {
        printf("The file is not created. The program will "
               "now exit.");
        getch();//wait until a char is pressed
		exit(0);
    }
    fseek(fptr, 22*50, SEEK_SET);
    //for (i=0;i<50;i++)
    //    fread(buffer,sizeof(buffer2),1,fptr);
        
    fread(buffer,sizeof(buffer),1,fptr);
    fwrite(buffer,sizeof(buffer),1,fptr2);
    fwrite(&eof,sizeof(eof),1,fptr2);
    fclose(fptr);
    fclose(fptr2);
    printf("last 50 passwords are copied!");
    getch();
}
