#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<string.h>
using namespace std;

class Student{    
    private:
        string name, surname, department;
        float midterm, final, average;
        int id;

    public:
        void set_name(string &n){
            name = n;
        }
        void set_surname(string &s){
            surname = s;
        }
        void set_department(string &d){
            department = d;
        }   
        void set_midterm_grade(float mid){
            midterm = mid;
        }
        void set_final_grade(float f){
            final = f;
        }
        string get_name(){
            return name;
        }
        string get_surname(){
            return surname;
        }
        string get_depatment(){
            return department;
        }   
        float get_midterm_grade(){
            return midterm;
        }
        float get_final_grade(){
            return final;
        }
        float find_average(){
            average = (midterm*0.4)+(final*0.6);
            return average;
        } 
};

int main(){
    Student *students;
    int size, i;
    printf("Please enter the size of students:\n");
    scanf("%d", &size);
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
    }

}