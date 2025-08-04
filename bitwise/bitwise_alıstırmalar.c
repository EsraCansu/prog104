/* #include<stdio.h>

int main(){
    unsigned char num; // sekiz bitlik oluşması için unsigned char kullandım
    int check;

    printf("Please enter the num:\n");
    scanf("%hhu", &num);

    while(num>256 && num<0){
        printf("Invalid input! Please enter the num between(0-255)");
        scanf("%hhu", &num);
    }
    
    printf("Please enter the num for checking 1 or 0:\n");
    scanf("%d", &check);
    while (check < 0 || check > 7) {
        printf("Invalid input! Please enter a bit position between 0 and 7:\n");
        scanf("%d", &check);
    }

    //numın x. karakteri sıfır mı onu kontrol edeceğiz
    unsigned char mask1 = (1 << check);
    if(num & check){
        printf("%d. char is 1\n");
    }
    else{
        printf("%d. char is 0\n");
    }
    return 0;
} */

#include <stdio.h>

int main() {
    unsigned char num; // Sekiz bitlik sayı için unsigned char
    int check;

    // Kullanıcıdan num al
    printf("Please enter the num (0-255):\n");
    scanf("%hhu", &num);

    // Kullanıcıdan bit pozisyonunu al
    printf("Please enter the bit position to check (0-7):\n");
    scanf("%d", &check);

    // Bit pozisyonunun geçerli olup olmadığını kontrol et
    while (check < 0 || check > 7) {
        printf("Invalid input! Please enter a bit position between 0 and 7:\n");
        scanf("%d", &check);
    }

    // Kontrol için maskeyi oluştur
    unsigned char mask1 = (1 << check);

    // Bit kontrolü yap
    if (num & mask1) {
        printf("Bit %d is 1.\n", check);
    } else {
        printf("Bit %d is 0.\n", check);
    }

    return 0;
}
