#include <stdio.h>
char arr[5]={'A','B','C','D','E'};
char c='a';
char * p;
int i;
void main(){
	p=&c;
	printf("%d\n",p);
	printf("%c\n",*p);
	p=arr;/* arr holds its beginning address */
	for(i=0;i<5;i++)
	   printf("%c ",arr[i]);
	printf("\n");
	for(i=0;i<5;i++)
	   printf("%c ",p[i]);
	printf("\n");
	for(i=0;i<5;i++)
	   printf("%c ",*(p+i));
	printf("\n");
	for(i=0;i<5;i++){
	   printf("%d\n",p);	
	   printf("%c ",*p);
	   p++;
    }
    printf("\n");
    printf("%d\n",p);
    printf("%c",*p);
	getch();
}
