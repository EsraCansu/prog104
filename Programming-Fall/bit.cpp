#include <stdio.h>

// Check the value of a specific bit
int checkBit(int num, int bitPosition) {
    return (num >> bitPosition) & 1;
}

// Set a specific bit to 1
int setBitToOne(int num, int bitPosition) {
    return num | (1 << bitPosition);
}

// Set a specific bit to 0
int setBitToZero(int num, int bitPosition) {
    return num & ~(1 << bitPosition);
}

int main() {
    int number, bitPosition;

    printf("Enter a number: ");
    scanf("%d", &number);

    printf("Enter the bit position (0-7): ");
    scanf("%d", &bitPosition);

    if (bitPosition < 0 || bitPosition > 8) {
        printf("Invalid bit position. Enter a number between 0 and 8.\n");
        return 1;
    }

    // Check the value of a specific bit
    printf("The value of bit %d is: %d\n", bitPosition, checkBit(number, bitPosition));

    // Set a specific bit to 1
    int numWithBitSetToOne = setBitToOne(number, bitPosition);
    printf("Number with bit %d set to 1: %d\n", bitPosition, numWithBitSetToOne);

    // Set a specific bit to 0
    int numWithBitSetToZero = setBitToZero(number, bitPosition);
    printf("Number with bit %d set to 0: %d\n", bitPosition, numWithBitSetToZero);

    return 0;
}

