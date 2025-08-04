#include<stdio.h>
#include<string.h>
#include<iostream>
#include<io.h>
using namespace std;

struct Student{
    unsigned char deleted; // 0:normal kayıt edilecek 1: olanlar ise silinecek demek
    char name[50];
    char surname[50];
    char department[50];
    int ID;
};

void student_transcript();
void student_search_from_name();
void student_search_from_ID();
void student_delete_ID();
void student_delete_name();
void student_list();

FILE *f;
struct Student student;
int i;

int main(){
    int choice;
    f=fopen("student.dat", "wb+");
    if(f==NULL){
        printf("ERROR");
        exit(0);
    }

    printf("Please select the choices: \n");
    do{
        printf("1.student_transcript\n");
        printf("2.student_search_from_name\n");
        printf("3.student_search_from_ID\n");
        printf("4.student_delete_ID\n");
        printf("5.student_delete_name\n");
        printf("6.student_list\n");
        printf("7.exit\n");
        printf("choice:\t");
        scanf("%d", &choice);
        if(choice == 1)
            student_transcript();

        else if(choice == 2) 
                student_search_from_name();

        else if(choice == 3)
                student_search_from_ID();
        
        else if(choice == 4)
                student_delete_ID();

        else if(choice == 5)
                student_delete_name();

        else if(choice ==6)
                student_list();
    }while(choice != 7);

    fclose(f);
    return 0;
}

void student_transcript(){
    printf("student ID:\n");
    cin>>student.ID;
    printf("student name:\n");
    cin>>student.name;
    printf("student surname:\n");
    cin>>student.surname;
    printf("student department:\n");
    cin>>student.department;
    student.deleted=0;
    fseek(f, sizeof(Student)*(student.ID-1),SEEK_SET); // ıd numarasına götürüp her bir ıd numarası olan yere bizim structımızı yerleştiriyor
    fwrite(&student,sizeof(struct Student),1,f);
}
void student_search_from_name(){
    char namen[50];
    int number_of_student;
    printf("Student name:\n");
    cin >> namen;
    number_of_student = filelength((fileno(f))/sizeof(struct Student));
    for(i=0; i<number_of_student; i++){
        fseek(f, sizeof(student)*(i-1), SEEK_SET);
        fread(&student, sizeof(struct Student), 1, f);
        if(student.ID && !student.deleted){
            if(!strcmp(student.name,namen)) //strcmp sıfır döndürüp döndürmediğini kontrol eder eğer aynıysa sıfır döndürür
                printf("%d\n", student.ID);
                printf("%s\n", student.name);
                printf("%s\n", student.surname);
                printf("%s\n", student.department);
        }
    }

    if(!student.deleted)

}
void student_search_from_ID(){
    int id;
    printf("Student id:\n");
    scanf("%d", &id);
    fseek(f, sizeof(student)*(id-1), SEEK_SET);
    fread(&student, sizeof(student), 1, f);
    if(!student.deleted){
        printf("%d\n", student.ID);
        printf("%s\n", student.name);
        printf("%s\n", student.surname);
        printf("%s\n", student.department);
    }
}
void student_delete_ID(){
    int id ;
    unsigned char deleted=1;
    printf("student id:\n");
    scanf("%d",&id);
    fseek(f,sizeof(student)*(id-1), SEEK_SET);
    fwrite(&deleted, sizeof(deleted), 1, f);
}
void student_delete_name(){
    printf("Not yet!");
}
void student_list(){
    int number_of_student = filelength((fileno(f))/sizeof(struct Student));
    for(i=0; i<number_of_student; i++){
        fseek(f, sizeof(struct Student)*i,SEEK_SET);
        fread(&student, sizeof(struct Student), 1, f);
        if(student.ID && !student.deleted){
            printf("%d\n", student.ID);
            printf("%s\n", student.name);
            printf("%s\n", student.surname);
            printf("%s\n", student.department);
        }       
    }
}