// alınan öğrenci sayısı kadar öğrenci structı oluşturmak // Create a student struct with a given number and write a binary file
#include <stdio.h>
#include <stdlib.h>

struct Student {
    char name[100];
    char surname[100];
    int ID;
    char department[100];
    float grade;
};

int main() {
    FILE *f;
    int i, size;

    printf("Please enter the size of your students array:\n");
    scanf("%d", &size);

    // Bellek tahsisi
    struct Student *students = (struct Student *)malloc(size * sizeof(struct Student));
    if (students == NULL) {
        printf("ERROR: Memory allocation failed.\n");
        exit(0);
    }

    // Dosya yazma
    f = fopen("students.bin", "wb");
    if (f == NULL) {
        printf("ERROR: Could not open file for writing.\n");
        free(students);
        exit(0);
    }

    // Öğrenci bilgilerini alma
    for (i = 0; i < size; i++) {
        printf("Please enter the name of student %d:\n", i + 1);
        scanf("%s", students[i].name);
        printf("Please enter the surname of student %d:\n", i + 1);
        scanf("%s", students[i].surname);
        printf("Please enter the department of student %d:\n", i + 1);
        scanf("%s", students[i].department);
        printf("Please enter the ID of student %d:\n", i + 1);
        scanf("%d", &students[i].ID);
        printf("Please enter the grade of student %d:\n", i + 1);
        scanf("%f", &students[i].grade);
    }

    // Verileri dosyaya yazma
    fwrite(students, sizeof(struct Student), size, f);
    fclose(f);

    // Belleği serbest bırakma
    free(students);

    // Dosyayı okuma
    f = fopen("students.bin", "rb");
    if (f == NULL) {
        printf("ERROR: Could not open file for reading.\n");
        exit(0);
    }

    struct Student *shown_students = (struct Student *)malloc(size * sizeof(struct Student));
    if (shown_students == NULL) {
        printf("ERROR: Memory allocation failed.\n");
        fclose(f);
        exit(0);
    }

    // Dosyadan verileri okuma
    fread(shown_students, sizeof(struct Student), size, f);
    fclose(f);

    // Verileri ekrana yazdırma
    printf("\nStudent Data:\n");
    for (i = 0; i < size; i++) {
        printf("\nStudent %d:\n", i + 1);
        printf("Name: %s\n", shown_students[i].name);
        printf("Surname: %s\n", shown_students[i].surname);
        printf("ID: %d\n", shown_students[i].ID);
        printf("Department: %s\n", shown_students[i].department);
        printf("Grade: %.2f\n", shown_students[i].grade);
    }

    // Belleği serbest bırakma
    free(shown_students);

    return 0;
}
