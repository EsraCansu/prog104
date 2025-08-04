// write 
#include <stdio.h>
char buffer[1000];
main(){
	FILE* fptr;
	FILE* fptr2;
 
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
    fseek(fptr, 21*50, SEEK_SET);
    fread(buffer,sizeof(buffer),1,fptr);
    fwrite(buffer,sizeof(buffer),1,fptr2);
    fclose(fptr);
    fclose(fptr2);
    printf("last 50 passwords are copied!");
    getch();
}
