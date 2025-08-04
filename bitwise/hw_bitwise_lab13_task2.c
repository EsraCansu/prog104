#include<stdio.h>
// kullanıcıdan iki sayı girşi alınır
// ilk sayının 7 ve 3. bitleri sıfırlanır
// ikinci sayının 4. biti 1 yapılır
// ilk ve ikinci sayıların 6. biti karşılaştırılır
// ilk ve ikinci sayıya XOR uygulanır

int main(){
    unsigned char num1; // 0010 0101 = 37
    unsigned char num2; // 1001 1010 = 154

    // iki sayının XOR sonucu
    unsigned char result = num1^num2; 
    //işlemi önceden yaptım çünkü yapılan işlemlerle num1 ve num2 değişecektir

    printf("Please enter the num1:\n");
    scanf("%hhu", &num1);

    printf("Please enter the num2:\n");
    scanf("%hhu", &num2);

    num1 &= ~(1 << 2);
    num1 &= ~(1 << 6);
    num2 |= (1 << 3);

    printf("New form of the num1:\n%u\n", num1);
    printf("New form of the num2:\n%u\n", num2);

    unsigned char mask = (1 << 5);
    if((num1 & mask) == (num2 & mask))
        printf("The 6. bits are same\n");

    else
        printf("The 6. bits are not same\n");

    printf("The XOR result of the numbers: %u\n", result);

    return 0;
}