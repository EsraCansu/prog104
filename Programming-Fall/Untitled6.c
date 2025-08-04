#include <stdio.h>

void display_bits(unsigned char number, char *s) {
    int i, j;
    int mask = 128; // 7th 1000 0000 0001 0000 130 1000 0010

    for (j = 0, i = 7; i >= 0; i--, j++) {
        if (number & mask)
            s[j] = '1'; //s[0]=1
        else
            s[j] = '0'; //s(1)=0
        mask = mask / 2;
    }
    s[j] = '\0'; // null char
}



int main() {
    unsigned char number;
    char s[9];
    int mask;

    printf("Enter a number (0-255): ");
    scanf("%hhu", &number);


    // Write binary representation to a .dat file
    FILE *file = fopen("binary_data.dat", "wb");
    fwrite(&number, sizeof(unsigned char), 1, file);
    fclose(file);

    // Read the binary data from the .dat file
    file = fopen("binary_data.dat", "rb");
    fread(&number, sizeof(unsigned char), 1, file);
    fclose(file);

    printf("Original bits: ");
    display_bits(number, s);
    printf("%s\n", s);

    mask = 128; // and mask to control 7th bit
    if (number & mask) {
        // 0010 0000=0x20 or mask to make 5th bit 1  1010 0010
        mask = 0x20;
        number = number | mask;
        // 1111 0111=0xF7 and mask to make 3rd bit 0 1010 0010
        mask = 0xF7;
        number = number & mask;

        printf("Modified bits: ");
        display_bits(number, s);
        printf("%s\n", s);
    }

    return 0;
}

