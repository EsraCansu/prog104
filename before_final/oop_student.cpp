#include<stdio.h>
#include<iostream>
#include<stdlib.h>
using namespace std;

class oop_student{
private:
    string name;
    string surname;
    string department;
    float midterm_grade;
    float final_grade;
    float average;

public:
    void set_name(const string &n){
        name = n;
    }
    void set_surname(const string &s){
        surname = s;
    }
    void set_department(const string &d){
        department = d;
    }
    void set_midterm_grade(float mid){
        midterm_grade = mid;
    }
    void set_final_grade(float final){
        final_grade = final;
    }
    float find_average(){
        average = (midterm_grade*0.4)+(final_grade*0.6);
    }

    string get_name()const{
        return name;
    }
    string get_surname()const{
        return surname;
    }
    string get_department()const{
        return department;
    }
    float get_midterm_grade()const{
        return midterm_grade;
    }
    float get_final_grade()const{
        return final_grade;
    }
    float get_average()const{
        return average;
    }
    void display(){

    }

};

int main(){
    FILE *f;
    int size, i, average;
    //oop_student *students;
    auto *students =new oop_student[size];
    char buffer[1000];

    printf("Please enter the size of the student class:\n");
    cin >> size;

    //students = (oop_student)malloc(size *sizeof(oop_student));
    
/*     if(students == NULL){
        printf("The memory is not allocated");
        exit(0);
    } */

    ofstream outFile("student_class.txt");
    if(!outFile){
        printf("Text didn't open");
        exit(0);
    }

    for(i=0; i<size; i++){
        string name, surname, department;
        float mid, final;
        cout << "Please enter the " << i+1 <<" student's,\n" ;
        cout << "Name:\n";
        cin >> name;
        cout << "Surname:\n";
        cin >> surname;
        cout << "Department:\n";
        cin >> department;
        cout << "Midterm grade:\n";
        cin >> mid;
        cout << "Final grade:\n";
        cin >> final;

        students[i].set_name(name);
        students[i].set_surname(surname);
        students[i].set_department(department);
        students[i].set_midterm_grade(mid);
        students[i].set_final_grade(final);
        students[i].find_average();    
    
        students[i].display(outFile);
    }
    delete[] students;
    outFile.close();
        
    ifstream inFile("student_class.txt");
    if (!inFile){
        cout << "Unable to open file for reading\n";
        return 1;
    }
    
    printf("The written text is:\n");
    while(fgets(buffer, sizeof(buffer), f)){
        printf("%s", buffer);
    }
    
    inFile.close();
    return 0;
}