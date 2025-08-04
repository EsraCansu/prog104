#include<stdio.h>
#include<stdlib.h>

int main(){
    int i;
    char buffer[10], word[10];
    FILE *f, *copy_f;

    printf("Please enter the for deleting word:\n");
    scand("%s",word);

    f=fopen("novel.txt","rb");
    if(f==NULL){
        printf("ERROR");
        exit(0);
    }

    copy_f=fopen("copy_novel.txt","wb");
    if(copy_f == NULL){
        printf("ERROR");
        exit(0);
    }
    
    while(!feof(f)){
        fread(buffer,sizeof(char),10,f);
        if(word!=buffer){
            fwrite(buffer,sizeof(char),10,copy_f);
        }
    }

    fclose(f);
    fclose(copy_f);n
    return 0;
}
