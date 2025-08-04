#include<stdio.h>
#include<stdio.h>
// beş öğrenci alınıp ortalamaları hesaplandı // get 5 students information from the user and calculated the average grade
struct Student{
    char name[100];
    char surname[100];
    int age;
    float final_grade;
    float midterm_grade;
    float average;
};

float find_average(float final_grade, float midterm_grade);
int main(){
    FILE *f;
    int i;

    f=fopen("info.txt", "w");
    if(f==NULL){
        printf("The file doesn't open");
        exit(0);
    }

    struct Student *students;
    students = (struct Student*)malloc(5*sizeof(struct Student));

    for(i=0; i<5; i++){
        printf("please enter the %d. student's;\n");
        printf("Name:\n");
        scanf("%s", students[i].name);
        printf("Surname:\n");
        scanf("%s", students[i].surname);
        printf("Age:\n");
        scanf("%d", &students[i].age);      
        printf("Midterm grade:\n");
        scanf("%f", &students[i].midterm_grade);       
        printf("Age:\n");
        scanf("%f", &students[i].final_grade);

        students[i].average = find_average(students[i].final_grade, students[i].midterm_grade);
        fprintf(f, "%d. Student's name: %s, surname: %s, age: %d\n", i+1, students[i].name, students[i].surname, students[i].age);
        fprintf(f, "midterm grade: %f\t final grade: %f\naverage grade: %.2f\n", students[i].midterm_grade, students[i].final_grade, students[i].average);
    }

    fclose(f);
    free(students);

    f=fopen("info.txt", "r");
    if(f==NULL){
        printf("The file doesn't open");
        exit(0);
    }

    char buffer[1000];
    while(fgets(buffer, sizeof(buffer),f) != NULL){
        printf("%s", buffer);
    }

    fclose(f);
    return 0;
}

float find_average(float final_grade, float midterm_grade){
    float average;
    average = ((midterm_grade*0.4)+(final_grade*0.6));
    return average;
}