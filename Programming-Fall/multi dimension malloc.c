#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
	char *s[10];
	int i;
	for (i=0;i<10;i++){	
		s[i]=(char *)malloc(sizeof(char)*(rand()%100+1));
		
		if (s[i]==NULL){
			printf("out of memory\n");
			exit(0);
		}
		printf("line %d:",i+1);
		gets(s[i]);
   }
   for (i=0;i<10;i++)
     printf("%s \n",s[i]);
	getch();
}
