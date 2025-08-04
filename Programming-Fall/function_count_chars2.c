#include <stdio.h>
#include <stdlib.h>
#include <time.h> 

/* write a c function to count numerical chars (0-9) and Capital letters (A-Z) inside a string*/
void str_count(char *s, int * num_count, int * cap_count){
	*num_count=0;
	*cap_count=0;
	int i;
	for(i=0;s[i];i++){  /* s[i]!='\0' */
	   	if (s[i]>='0' && s[i]<='9') //between
	   	   ++*num_count;
	   	else if (s[i]>='A' && s[i]<='Z')
	   	   ++*cap_count;	   
	}
	
}

main(){
    int n, c;
    char s[101];
    
	printf("str:");
	gets(s);
	str_count(s,&n,&c);
	printf("# of numerical chars:%d \n",n);
	printf("# of capital letters:%d \n",c);
	getch();
}
