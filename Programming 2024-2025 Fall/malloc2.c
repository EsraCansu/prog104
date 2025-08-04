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
void main()
{
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
        
            printf("%s,", ptr[]);
           
        
        printf("\n Number of numericals:%d \n",numericalcharcount(ptr,1000));
		free(ptr);     
}

