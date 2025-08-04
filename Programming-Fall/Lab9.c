#include <stdio.h>

void reverseByte(FILE *inputFile, FILE *outputFile) {
    char byte;

    while ((byte = fgetc(inputFile)) != EOF) {
        // Reverse the byte using bitwise complement operation
        byte = ~byte;
        
        // Write to the output file
        //fputc(byte, outputFile);
        fgets(byte,sizeof(byte),outputFile);
    }
}

int main() {
    FILE *inputFile, *outputFile;
    char inputFileName[50], outputFileName[50];

    // Get the input file name from the user
    printf("Enter the input file name: ");
    scanf("%s", inputFileName);

    // Open the input file
    inputFile = fopen(inputFileName, "r");
    if (inputFile == NULL) {
        printf("Error opening input file.\n");
        return 1;
    }

    // Get the output file name from the user
    printf("Enter the output file name: ");
    scanf("%s", outputFileName);

    // Open the output file
    outputFile = fopen(outputFileName, "w");
    if (outputFile == NULL) {
        printf("Error opening output file.\n");
        fclose(inputFile);
        return 1;
    }

    // Reverse each byte and write to the output file
    reverseByte(inputFile, outputFile);

    // Close the files
    fclose(inputFile);
    fclose(outputFile);

    printf("File reverse operation completed successfully.\n");

    return 0;
}

