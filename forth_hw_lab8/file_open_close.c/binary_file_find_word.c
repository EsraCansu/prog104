#include<stdio.h>
#include<stdlib.h>
#include<string.h>
//find the given word and count

int main(){
    int i, counter=0;
    char word[10], buffer[1024];
    FILE *f;

    printf("Please enter the word for finding(the size should be less then 10):\n ");
    scanf("%s",word);
    f = fopen("novel.txt","rb");

    if(f == NULL){
        printf("ERROR");
        exit(0);
    }
    size_t word_len=strlen(word);
    size_t bytes_read=0;

    while((bytes_read = fread(buffer, 1, sizeof(buffer), f))>0){
        for(i=0; i<=bytes_read-word_len; i++){
            if(memcmp(&buffer[i], word, word_len == 0)){ // buffer dizisinde i indisinden başlayan adres, kullanıcının girdiği kelimenin adresi, karşılaştırılacak bayt sayısı
                counter++; // eğer memcmp sıfır dönerse iki bellek bölsesi eşlemiş demektir. 
            }
        }
        if(bytes_read >= word_len){
            fseek(f, -(long)(word_len-1), SEEK_CUR);
        }
    }

    fclose(f);
    printf("The word '%s' was found %d times in the file.\n", word, counter);
    return 0;
}