#include<stdio.h>

struct Student{
    int student_ID;
    char student_name[100];
    float midterm_grade;
    float final_grade;
};

float find_average_grade(float *student.midterm_grade, float *student.midterm_grade){

}
int main(){
    FILE *student_file;
    struct Student student;
    int choice;

    student_file = fopen("student.txt", "w");
    if(student_file == NULL){
        printf("ERROR");
        exit(0);
    }

    printf("Please enter the choice for:\n1.If you want to add a student to the list please enter the 1\n2.If you want to show the list, please enter the 2\n");
    scanf("%d", &choice);

    struct Student student_shown;

    float average_grade = find_average_grade(&student.midterm_grade, &student.midterm_grade)

    printf("Student ID: %d", student_shown.student_ID);
    printf("Student name: %s", student_shown.student_name);
    printf("Student midterm grade: %f", student_shown.midterm_grade);
    printf("Student final grade: %f", student_shown.final_grade);
    printf("Student average grade: %f", average_grade);

    fclose(student_file);
    return 0;
}