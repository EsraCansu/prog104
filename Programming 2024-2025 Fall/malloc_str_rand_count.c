#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//generate a dynamic string including a-z, A-Z, 0-9 chars
//count each category
//a:97 A:65 0:48
void str_count(char * s,int * cat1, int * cat2, int * cat3){
	int i=0;
	*cat1=0;
	*cat2=0;
	*cat3=0;
	while (s[i]){ // '\0'-->0--->false
		if (s[i]>='a' && s[i]<='z')
		   (*cat1)++;
		else if (s[i]>='A' && s[i]<='Z')
		   (*cat2)++;
		else if (s[i]>='0' && s[i]<='9')
		   (*cat3)++;   
		i++;
	}
}
void main()
{   
    char * s;
    int i, cat1, cat2, cat3;
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
        str_count(s,&cat1,&cat2,&cat3);
        printf("a-z:%d A-Z:%d 0-9:%d \n",cat1, cat2, cat3);
        
        free(s);
}

