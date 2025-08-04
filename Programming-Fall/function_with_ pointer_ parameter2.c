#include <stdio.h>
#include <stdlib.h>
#include <time.h> 
/* write a c function to generate a random string with given size, whose each char is between A-Z*/
int randomstr(char *s, int n){
  int i;
  if (!(n>=1 && n<=100)){
  	//fail
  	return 0;
  }
  for (i=0;i<n;i++)
     s[i]=rand()%26+65;
  s[i]='\0';
  return 1;
}
char str[101];
int status;
main(){
	status=randomstr(str,5);
	if (status==1)
	  printf("%s\n",str);
	else
	  printf("n must be between 1-100\n");
	getch();
}
