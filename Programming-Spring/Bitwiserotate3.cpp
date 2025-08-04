#include <iostream>
#include <cstring>
using namespace std;
class BitwiseRotate{
    public:
        void showbits(char *s,int number);		
		int rotate_left(int b,int n);	
		int rotate_right(int b,int n);	
	private:
		unsigned int AND_mask = 0x80;
};
void BitwiseRotate::showbits(char *s,int number)
{   int i;    
	for(i=0;i<=7;i++)
	{
		if (number&AND_mask)
			s[i]='1';
		else
		    s[i]='0';
		AND_mask=AND_mask/2;
	} 
	s[8] ='\0'; 
}
int BitwiseRotate::rotate_left(int b,int n)
{
	int i;
	int mask1=0x80;
	int mask2=0x01;
	for (i=0;i<n;i++)
	{
	
	   if (b&mask1)
	   {
		  b=b<<1;
		  b=b|mask2;
	   }
	   else
	     b=b<<1;
   	}
	 return b;	
}    
int BitwiseRotate::rotate_right(int b,int n)
{
	int i;
	int mask_and=0x01;
	int mask_or=0x80;
	for (i=0;i<n;i++)
	{
	
	   if (b&mask_and)
	   {
		  b=b>>1;
		  b=b|mask_or;
	   }
	   else
	     b=b>>1;
    }
	return b;	
}
int main()
{
	//int  b=0x91,i;
    //unsigned char---->byte :0..255 8bits
    int b;
    cout<<"b:";
    scanf("%x",&b);
    char s[9];
    //BitwiseRotate:class
    //br1: object
    BitwiseRotate br1;
    
    br1.showbits(s,b);
    cout<<"Bits:"<<s<<endl;
    
    b=br1.rotate_left(b,4);
    br1.showbits(s,b);
    cout<<"Bits:"<<s<<endl;
    
    b=br1.rotate_right(b,4);
    br1.showbits(s,b);
    cout<<"Bits:"<<s<<endl;
    
    return 0;
}

