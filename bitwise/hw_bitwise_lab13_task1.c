#include<stdio.h>
// kullanıcıdan alınan sayının 2. ve 5. bitleri ters çevirip
//3. ve 4. bitlerin 1 olup olmaduğı kontrol edilir 

int main(){
    unsigned char num;

    printf("Please enter the number: \n");
    scanf("%hhu", &num); //num 0000 1110 14 ya da 0001 0101 21 denendi
    num ^= (1 << 1);//2. bit için
    num ^= (1 << 4);//5. bit için

    printf("number after toggling 2. and 5. bits: %u\n", num);

    unsigned char mask1 = (1 << 2); 
    unsigned char mask2 = (1 << 3);

    if((num & mask1) && (num & mask2)) // ikisi de birse sonuç zaten bir gelir 
        printf("The 3. and 4. bits are both 1.\n");

    else if(num & mask1)
        printf("The 3. bit is 1.\n");
        
    else if(num & mask2)
        printf("The 4. bit is 1.\n ");

    else
        printf("The 3. and 4. bits are not both 1.\n");

    return 0;
}