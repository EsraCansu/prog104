#include<stdio.h>
#include<stdlib.h>
#include<time.h>
//binary dosyaya rastgele sayı oluşturup yazdırmak 

int main(){
    int i;
    FILE *source_f;
    int num[50];
    int shown[50];

    source_f=fopen("data.txt","wb");
    if(source_f == NULL){
        printf("ERROR");
        exit(0);
    }

    srand(time(NULL));
    for(i=0;i<50;i++){
        num[i]=rand()%50;
    }

    fwrite(num,sizeof(int),50,source_f);
    fclose(source_f);
    
    source_f=fopen("data.txt","rb");
    if(source_f == NULL){
        printf("ERROR");
        exit(0);
    }

    fread(shown,sizeof(int),50,source_f);
    fclose(source_f);
    
    printf("The nums written successfully\nThe nums:\n");
    for(i=0; i<50; i++){
        printf("%d\n", shown[i]);
    }
    return 0;
}