// C Program to illustrate the 2D array
#include <stdio.h>
#include <stdlib.h>
#include <time.h>


void fill_char_arr(char * s,int n){
	int i;
	for ( i = 0; i < n; i++)         
        s[i]=rand()%26+'a';
    s[n]='\0';
}

void main()
{
    int i;
    char * ptr[10];//10 string
	for (i=0;i<10;i++)
        ptr[i] = (char *)malloc(101* sizeof(char));
    
	srand(time(0));
	
    for ( i = 0; i < 10; i++)      
       fill_char_arr(ptr[i],100);

    for ( i = 0; i < 10; i++)      
            printf("%s \n", ptr[i]);     
    
    
    
    for ( i = 0; i < 10; i++)      
       free(ptr[i]);    
}
   

