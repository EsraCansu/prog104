#include<stdio.h>
#include<stdlib.h>

void delete_num(char *pass, char *s);
int main(){
    int i;
    char pass[13], s[13];
    printf("please enter the password(12 character):\n");
    scanf("%12s",pass);

    delete_num(pass, s);
    printf("Deleted version is: %s\n", s);
    return 0;
}
    
void delete_num(char *pass, char *s){
    int i, j=0; 
    for(i=0; i<12 && pass[i]!='\0'; i++){
        if(pass[i]>='a' && pass[i]<='z' || pass[i]>='A' && pass[i]<='Z'){
            s[j++] = pass[i];
        }
    }
    s[j]='\0';
} 

/* #include <stdio.h>
#include <stdlib.h>
#include <ctype.h> // isalpha fonksiyonu için gerekli

void delete_num(const char *pass, char *s);

int main() {
    char pass[13]; // 12 karakter + null sonlandırıcı için 1 ek
    char s[13];    // İşlenmiş dizi için aynı uzunlukta
    printf("Please enter the password (max 12 characters):\n");
    scanf("%12s", pass); // Maksimum 12 karakter girişi için sınır konuldu

    delete_num(pass, s);
    printf("Deleted version is: %s\n", s);
    return 0;
}

void delete_num(const char *pass, char *s) {
    int i, j = 0;
    for (i = 0; pass[i] != '\0'; i++) {
        if (isalpha(pass[i])) { // Harf kontrolü
            s[j++] = pass[i];  // Sadece harfleri ekle
        }
    }
    s[j] = '\0'; // Dizi sonlandırıcısını ekle
} */
