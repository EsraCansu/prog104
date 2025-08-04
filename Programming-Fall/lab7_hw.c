#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {
    FILE *file;
    FILE *testFile;
    char firstName[50];
    char lastName[50];
    int grade;
    int studentCount;

    // Open the file to write student information in "w" (write) mode
    file = fopen("student_info.txt", "w");

    // Check if the file is opened successfully
    if (file == NULL) {
        printf("File could not be opened. Program is terminating.\n");
        perror("error");
        return 1; // Return 1 to indicate an error
    }

    // Open the file in "w" (write) mode to write test information
    testFile = fopen("test2.txt", "w");

    // Check if the file is opened successfully
    if (testFile == NULL) {
        printf("File could not be opened. Program is terminating.\n");
        fclose(file); // Close the first file
        return 1; // Return 1 to indicate an error
    }

    // Get the number of students from the user
    printf("How many student records do you want to add? ");
    scanf("%d", &studentCount);

    // Get student information from the user and write to the file
    for (int i = 0; i <= studentCount; i++) {
        printf("Enter the first name of the student: ");
        scanf("%s", firstName);

        printf("Enter the last name of the student: ");
        scanf("%s", lastName);

        // Generate a random grade (0-100)
        grade = rand() % 101;

        // Write the user-input student information and the random grade to the file
        fprintf(file, "%s %s %d\n", firstName, lastName, grade);
    }

    // Read student information from the file and write those with grades above 60 to test2.txt
    rewind(file); // Go back to the beginning of the file

    while (fscanf(file, "%s %s %d", firstName, lastName, &grade) == 3) {
        if (grade > 60) {
            fprintf(testFile, "%s %s %d\n", firstName, lastName, grade);
        }
    }

    // Close the files
    fclose(file);
    fclose(testFile);

    printf("Information of students with grades above 60 has been written to test2.txt.\n");

    return 0; // Return 0 to indicate successful completion of the program
}

