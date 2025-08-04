#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//generate a dynamic string including a-z, A-Z, 0-9 chars
//a:97 A:65 0:48
void main()
{   
    char * s;
    int i;
    int category;//0 :a-z, 1:A-Z, 2:0-9
        
    // Dynamically allocate memory using malloc()
    s = (char *)malloc(21* sizeof(char));

    // Check if the memory has been successfully
    // allocated by malloc or not
    if (s == NULL) {
        printf("Memory not allocated.\n");
        exit(0);
    }
    
     srand(time(0));// initialize random seed before loop
        // ASCII table:0-255 'A'-->65 '0'-->48 space=32 backspace=8 enter=13
        for (i = 0; i < 20; ++i) {
           category=rand()%3;//0..2
           if (category==0)
              s[i] = rand()%26+'a';  //a-z:26 chars   
           else if (category==1)
              s[i] = rand()%26+'A';  //A-Z:26 chars  
		   else
		      s[i] = rand()%10+'0';  //0-9:10 chars  
		          
        }
        s[20]='\0';
        //*(s+i)='\0';
		
        printf("pass:%s \n",s);
        free(s);
}

