#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
int main()
{
	char * *s;
	int i,j;
	int line_num=3;
	
	s=(char *)malloc(sizeof(char *)*line_num);
	for (i=0;i<line_num;i++){	
		s[i]=(char *)malloc(sizeof(char)*(rand()%100+1));
		
		if (s[i]==NULL){
			printf("out of memory\n");
			exit(0);
		}
		printf("line %d:",i+1);
		gets(s[i]);
   }
   /* line by line */
   for (i=0;i<line_num;i++)
     printf("%s \n",s[i]);
     
   printf("\n");  
   /* char by char */
   for (i=0;i<line_num;i++){   
      for (j=0;s[i][j];j++)
         printf("%c",s[i][j]);
      printf("\n");
   }
	getch();
	
   
   for (i=0;i<10;i++)
	 free(s[i]);
}
