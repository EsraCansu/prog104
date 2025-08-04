#include <stdio.h>
int arr[5]={2,4,6,8,10};
int i=5;
int * p;
unsigned int j;
unsigned char c;//byte %d %c 0..255 2^8
char c2;//-128..0..127

void main(){
	p=&i;
	printf("%x\n",p);
	printf("%d\n",*p);
	p=arr;/* arr holds its beginning address */
	for(i=0;i<5;i++)
	   printf("%d ",arr[i]);
	printf("\n");
	for(i=0;i<5;i++)
	   printf("%d ",p[i]);
	printf("\n");
	for(i=0;i<5;i++)
	   printf("%d ",*(p+i));
	printf("\n");
	for(i=0;i<5;i++){
	   printf("%d\n",p);	
	   printf("%d ",*p);
	   p++;
    }
    printf("\n");
    printf("%d\n",p);
    printf("%d\n",*p);
    printf("%d\n",0xFFFF);
    
	getch();
}
