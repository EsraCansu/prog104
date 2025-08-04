//Write a C program to copy any file to another file.

#include <stdio.h>

int main() {
   FILE * source;
   FILE * target;
   int count;
   long int file_length;
   char source_file[100], target_file[100];
   unsigned char buffer[100];
   
   int sum;
   
   printf("source file:");
   gets(source_file);
   
   printf("target file:");
   gets(target_file);
      
   source = fopen(source_file, "rb");
   if (source == NULL) {
       perror("Error opening source file");
       return 1;
   }
   target = fopen(target_file, "wb");
   if (target == NULL) {
       perror("Error opening target file");
       return 1;
   }
   file_length=filelength(fileno(source));
   
   for (sum=0;sum<file_length;sum=sum+count)  	
     count = fread(buffer, sizeof(unsigned char), 100, source);
     fwrite(buffer, sizeof(unsigned char), count, target);
   }    
   
   fclose(source);
   fclose(target);
   return 0;
}
