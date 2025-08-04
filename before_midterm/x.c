#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Function to generate a random password
void rand_pass(char *p, int size) {
    int choice, i;

    for (i = 0; i < size; i++) {
        choice = rand() % 3;
        if (choice == 0)
            p[i] = rand() % 26 + 'a'; // Lowercase letter
        else if (choice == 1)
            p[i] = rand() % 26 + 'A'; // Uppercase letter
        else
            p[i] = rand() % 10 + '0'; // Digit
    }
    p[size] = '\0'; // Null-terminate the password
}

int main() {
    int size;
    FILE *f;
    char *p;

    printf("Please enter the size of your password:\n");
    scanf("%d", &size);

    // Validate the size input
    if (size <= 0) {
        printf("Invalid size. Please enter a positive integer.\n");
        return 1;
    }

    // Allocate memory for the password
    p = malloc((size + 1) * sizeof(char));
    if (p == NULL) {
        printf("Memory allocation failed.\n");
        return 1;
    }

    // Open file for writing
    f = fopen("Passwords.txt", "w");
    if (f == NULL) {
        printf("Failed to open the file.\n");
        free(p); // Free allocated memory
        return 1;
    }

    srand(time(NULL)); // Seed the random number generator
    rand_pass(p, size); // Generate the password
    fprintf(f, "%s\n", p); // Write the password to the file

    printf("The password was written successfully to 'Passwords.txt'.\n");

    fclose(f);  // Close the file
    free(p);    // Free allocated memory
    return 0;
}