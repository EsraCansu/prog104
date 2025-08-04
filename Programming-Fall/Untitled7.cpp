#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void writeToFile(char *fileName, char *text) {
    FILE *file = fopen(fileName, "w");
    if (file == NULL) {
        perror("Error opening file for writing");
        exit(1);
    }

    fprintf(file, "%s", text);

    fclose(file);
}

void encryptDecrypt(char *inputFileName, char *outputFileName, char key) {
    FILE *inputFile, *outputFile;
    char ch;

    // Open the input file for reading
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        perror("Error opening input file");
        exit(1);
    }

    // Open the output file for writing
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        perror("Error opening output file");
        fclose(inputFile);
        exit(1);
    }

    // Read each character from the input file, decrypt, encrypt, and write to the output file
    while ((ch = fgetc(inputFile)) != EOF) {
        // Decrypt: apply bitwise XOR with the key
        char decryptedChar = ch ^ key;

        // Encrypt: apply bitwise XOR with the same key
        char encryptedChar = decryptedChar ^ key;

        // Write the decrypted and encrypted characters to the output file
        fprintf(outputFile, "Original: %c, Decrypted: %c, Encrypted: %c\n", ch, decryptedChar, encryptedChar);
    }

    // Close the files
    fclose(inputFile);
    fclose(outputFile);
}

int main() {
    char inputFileName[50] = "input.txt";
    char outputFileName[50] = "output.txt";
    char key;
    char text[100];

    // Get the text from the user
    printf("Enter a text to be saved to the file: ");
    fgets(text, sizeof(text), stdin);

    // Write the text to a file
    writeToFile(inputFileName, text);

    // Get the encryption/decryption key from the user
    printf("Enter the encryption/decryption key: ");
    scanf(" %c", &key);

    // Perform encryption and decryption
    encryptDecrypt(inputFileName, outputFileName, key);

    printf("Encryption and decryption completed successfully.\n");

    return 0;
}

