#include <stdio.h>
#include <string.h>
#include <iostream>
#include <fstream>
using namespace std;

struct Student {
    unsigned char deleted;  // 0: normal, 1: deleted (soft delete)
    int StudentID;
    char name[30];
    char surname[30];
    char department[20];
};

FILE *f;
int choice;
struct Student Student2;

void student_write() {
    printf("Student ID: ");
    cin >> Student2.StudentID;
    printf("Student Name: ");
    cin >> Student2.name;
    printf("Student Surname: ");
    cin >> Student2.surname;
    printf("Student Department: ");
    cin >> Student2.department;
    
    Student2.deleted = 0; // Normal record
    fseek(f, sizeof(struct Student) * (Student2.StudentID - 1), SEEK_SET);
    fwrite(&Student2, sizeof(struct Student), 1, f);
}

void student_search_id() {
    int id;
    printf("Student ID: ");
    scanf("%d", &id);
    fseek(f, sizeof(struct Student) * (id - 1), SEEK_SET);
    fread(&Student2, sizeof(struct Student), 1, f);
    
    if (!Student2.deleted) {
        printf("ID: %d\n", Student2.StudentID);
        printf("Name: %s\n", Student2.name);
        printf("Surname: %s\n", Student2.surname);
        printf("Department: %s\n", Student2.department);
    } else {
        printf("This student record has been deleted.\n");
    }
}

void student_delete_id() {
    int id;
    printf("Student ID to delete: ");
    scanf("%d", &id);
    fseek(f, sizeof(struct Student) * (id - 1), SEEK_SET);
    fread(&Student2, sizeof(struct Student), 1, f);
    
    if (!Student2.deleted) {
        Student2.deleted = 1; // Mark as deleted
        fseek(f, sizeof(struct Student) * (id - 1), SEEK_SET);
        fwrite(&Student2, sizeof(struct Student), 1, f);
        printf("Student record deleted.\n");
    } else {
        printf("This student record has already been deleted.\n");
    }
}

void student_list() {
    int number_of_students;
    fseek(f, 0, SEEK_END);
    number_of_students = ftell(f) / sizeof(struct Student);
    fseek(f, 0, SEEK_SET);
    
    for (int i = 0; i < number_of_students; i++) {
        fread(&Student2, sizeof(struct Student), 1, f);
        if (!Student2.deleted) {
            printf("ID: %d\n", Student2.StudentID);
            printf("Name: %s\n", Student2.name);
            printf("Surname: %s\n", Student2.surname);
            printf("Department: %s\n\n", Student2.department);
        }
    }
}

void student_search_name() {
    char name[30];
    printf("Student Name: ");
    cin >> name;
    
    int number_of_students;
    fseek(f, 0, SEEK_END);
    number_of_students = ftell(f) / sizeof(struct Student);
    fseek(f, 0, SEEK_SET);
    
    for (int i = 0; i < number_of_students; i++) {
        fread(&Student2, sizeof(struct Student), 1, f);
        if (!Student2.deleted && !strcmp(Student2.name, name)) {
            printf("ID: %d\n", Student2.StudentID);
            printf("Name: %s\n", Student2.name);
            printf("Surname: %s\n", Student2.surname);
            printf("Department: %s\n\n", Student2.department);
        }
    }
}

int main() {
    f = fopen("student2.dat", "rb+");
    if (!f) {
        f = fopen("student2.dat", "wb+");
    }

    if (!f) {
        printf("Error opening file.\n");
        return 1;
    }

    do {
        printf("1. Add Student\n");
        printf("2. Search Student by ID\n");
        printf("3. Search Student by Name\n");
        printf("4. Delete Student by ID\n");
        printf("5. List Students\n");
        printf("6. Exit\n");
        printf("Choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                student_write();
                break;
            case 2:
                student_search_id();
                break;
            case 3:
                student_search_name();
                break;
            case 4:
                student_delete_id();
                break;
            case 5:
                student_list();
                break;
            case 6:
                printf("Exiting...\n");
                break;
            default:
                printf("Invalid choice. Try again.\n");
        }
    } while (choice != 6);

    fclose(f);
    return 0;
}
