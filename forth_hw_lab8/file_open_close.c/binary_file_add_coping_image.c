//bir dosyayı kopyalayıp, başka bir dosyada, kopyalanan dosyayı alt alta yapıştıracağım, 
//bu dosyalar resim dosyası olacaktır.
#include<stdio.h>
#include<stdlib.h>

int main(){
    FILE *source_f, *target_f;
    int count, sum=0;
    char source_file_name[100], target_file_name[100];
    unsigned char buffer[100];

    printf("Please enter the name of image file:\n");
    gets(source_file_name);

    printf("Please enter the coping of image file:\n");
    gets(target_file_name);

    source_f = fopen(source_file_name, "rb");
    target_f = fopen("$$temp.dat", "wb");

    if(source_f == NULL || target_f == NULL){
        printf("ERROR");
        exit(0);
    }

//iki kere yapmak için aynı döngüyü mü tekrar etmeliyim nasıl bir döngü kullanmalıyım
    while(!feof(source_f)){
        count = fread(buffer, sizeof(unsigned char), 100, source_f);
        fwrite(buffer, sizeof(unsigned char), count, target_f);
    }

    fclose(source_f);
    fclose(target_f);
    return 0;
}
