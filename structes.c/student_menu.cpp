#include<stdio.h>
#include<iostream>
#include<io.h>
using namespace std;

struct Student{
    int student_ID;
    char name[50];
    char surname[50];
    char student_department[50];
};
void student_transkript();
void student_search();
void student_delete();
void student_list();

struct Student student;
FILE *f;
int i;
int choice;

int main(){
    f=fopen("student.txt","rb4+");
    if(f == NULL){
        f=fopen("student.txt","wb+");
    }

    do{
        printf("1.add the student\n2.search the student by ID\n");
        printf("3.delete the student\n4.list the students\n");
        scanf("%d", &choice);
        if(choice==1)
            student_transkript();

        else if(choice==2)
            student_search();

        else if(choice==3)
            student_delete();
        
        else if(choice==4)
            student_list();

    } while(choice!=5);

    fclose(f);
    return 0;
}

void student_transkript(){
    printf("Please enter the ID of student:\n");
    cin>>student.student_ID;

    printf("Please enter the name of student:\n");
    cin>>student.name;

    printf("Please enter the surname of student:\n");
    cin>>student.surname;

    printf("Please enter the department of student:\n");
    cin>>student.student_department;

    fseek(f,sizeof(struct Student)*(student.student_ID-1), SEEK_SET);
    fwrite(&student, sizeof(struct Student),1,f);
}

void student_search(){
    int id;
    printf("student ID:\n");
    scanf("%d", &id);

    fseek(f, sizeof(struct Student), (student.student_ID-1), SEEK_SET);
    fread(&student, sizeof(student), 1, f);

    printf("%d\n", student.student_ID);
    printf("%s\n", student.name);
    printf("%s\n", student.surname);
    printf("%s\n", student.student_department);
}

void student_delete(){

}

void student_list(){
    int i, number_of_students;
    number_of_students=filelength(fileno(f))/sizeof(struct Student);

    for(i=0; i<number_of_students; i++){
        fseek(f, sizeof(struct Student)*(i), SEEK_SET);
        fread(&student, sizeof(struct Student), 1, f);
        if(student.student_ID){
            printf("%d\n", student.student_ID);
            printf("%s\n", student.name);
            printf("%s\n", student.surname);
            printf("%s\n", student.student_department);
            printf("\n");
        }
    }
}