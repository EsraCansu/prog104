#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int numericalcharcount(char *p,int n){
	int i,counter=0;
	for (i = 0; i < n; ++i) {
		    if (p[i]>='0' && p[i]<='9')
              counter++;
        }  
    return counter;
}
int numericalcharcount2(char *p){
	int i,counter=0;
	//'\0'-->null char: ascii value 0
	for (i = 0; p[i]!='\0'; i++) {
		    if (p[i]>='0' && p[i]<='9')
              counter++;
        }  
    return counter;
}
void main()
{   char ch;
    char s[100];
    char * ptr;
    int i;
        
    // Dynamically allocate memory using malloc()
    ptr = (char *)malloc(1000* sizeof(char));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (ptr == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    
     srand(time(0));// initialize random seed before loop
        // ASCII table:0-255 'A'-->65 '0'-->48 space=32 backspace=8 enter=13
        for (i = 0; i < 1000; ++i) {
           *(ptr+i) = rand()%256;            
        }

        // Print the elements of the array
        printf("The elements of the array are: ");
        for (i = 0; i < 1000; ++i) {
            printf("%c, ", ptr[i]);
        }   
        
        printf("\n Number of numericals:%d \n",numericalcharcount(ptr,1000));
		free(ptr);     
		printf("s:");
		gets(s);//string input
		printf("\n Number of numericals:%d \n",numericalcharcount(s,strlen(s)));
		printf("\n Number of numericals:%d \n",numericalcharcount2(s));
		//ptr=s;
		ptr=&s[0];
		printf("%s\n",ptr);//print the chars until '\0'
		ch='A';
		ptr=&ch;
		printf("%c %p \n",*ptr,ptr);
}

