#include <stdio.h>

//Write a C program to read from password.txt and 
//to find how many numerical and alphabetical chars are used in the file.

void pass_num_count(char *s,int * num_count, int * alp_count) {
	int i, count1=0, count2=0;
        for (i = 0; i < strlen(s); i++) {
           if (s[i]>='0'&&s[i]<='9')
             count1++;
		   else if (s[i]>='A'&&s[i]<='Z')	 
		      count2++; 
		   else if (s[i]>='a'&&s[i]<='z')	 
		      count2++;        
        }
        * num_count=count1;
        * alp_count=count2;
}
        
int main()
{
	char s[22];
	int i, count1, count2,sum_num_count=0,sum_alp_count=0;
		    
    FILE* fptr;

    // opening the file in read mode
    fptr = fopen("password.txt", "r");

    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("Cannot open file\n");
        exit(0);       
    }
    while (!feof(fptr)){
    	if (fgets(s,22,fptr)){		
    	  pass_num_count(s,&count1, &count2);
    	  sum_num_count=sum_num_count+count1;
    	  sum_alp_count=sum_alp_count+count2;
        }
	}
    fclose(fptr);
    printf("total number of numerical chars:%d\n",sum_num_count);
    printf("total number of alphabetical chars:%d\n",sum_alp_count);
}
