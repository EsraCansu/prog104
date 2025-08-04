#include <stdio.h>

//Write a C program to read from password.txt and to find passwords having 5 or more numerical chars

int pass_num_count(char *s)     {
	int i, count=0;
        for (i = 0; i < strlen(s); i++) {
           if (s[i]>='0'&&s[i]<='9')
              count++;		          
        }
        return count;
}
        
int main()
{
	char s[22];
	int i, count;
		    
    FILE* fptr;

    // opening the file in read mode
    fptr = fopen("password.txt", "r");

    // checking if the file is opened successfully
    if (fptr == NULL) {
        printf("Cannot open file\n");
        exit(0);       
    }
    while (!feof(fptr)){
    	fgets(s,22,fptr);
    	count=pass_num_count(s);
    	if (count>=5)
    	   printf("%s",s);
	}
    fclose(fptr);
    printf("random password having 5 or numerical chars are given!!!");
}
