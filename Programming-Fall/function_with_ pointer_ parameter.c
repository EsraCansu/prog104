#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
/* write a c function to generate a random string with given size, whose each char is between A-Z*/
void randomstr(char *s, int n,int * status){
  int i;
  if (n>100 || n<=0){
  	*status=0; //fail
  	return;
  }
  for (i=0;i<n;i++)
     *(s+i)=rand()%26+65;
  s[i]='\0';
  *status=1;
}
char str[101];
int status;
main(){
	randomstr(str,100,&status);
	if (status==1)
	  printf("%s\n",str);
	else
	  printf("n must be between 1-100\n");
	getch();
}
