#include <iostream>
#include <cstring>
using namespace std;
class BitwiseRotate{
    public:
        void showbits(char *s,int number)
		{   int i;
    		unsigned int mask = 0x80;
			for(i=0;i<=7;i++)
			{
				if (number&mask)
				  s[i]='1';
				else
		  		  s[i]='0';
				mask=mask/2;
			} 
			s[8] ='\0'; 
		}
		int rotate_left(int b,int n)
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
};


int main()
{
	int  b=0x91,i;
    //unsigned char---->byte :0..255 8bits
    char s[9];
    
    BitwiseRotate br1;
    br1.showbits(s,b);
    cout<<"Bits:"<<s<<endl;
    return 0;
}

