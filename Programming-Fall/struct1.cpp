#include <stdio.h>   
#include <string.h>
#include <iostream>
using namespace std;

struct {
  int StudentID;
  string name;
  string surname;
  string department;
} Student;
struct {
  int StudentID;
  char name[30];
  char surname[30];
  char department[20];
} Student2;

main(){

// Assign values to members of myStructure
Student.StudentID = 1;
Student.name="a";
Student.surname="b";
Student.department="ceng";

Student2.StudentID = 1;
strcpy(Student2.name,"a");
strcpy(Student2.surname,"b");
strcpy(Student2.department,"ceng");

// Print members of myStructure
cout << Student.StudentID << "\n";
cout << Student.name<< "\n";
cout << Student.surname << "\n";
cout << Student.department<< "\n";

cout <<" "<<"\n";
cout << Student2.StudentID << "\n";
cout << Student2.name<< "\n";
cout << Student2.surname << "\n";
cout << Student2.department<< "\n";

printf("%d \n",Student2.StudentID);
printf("%s \n",Student2.name);
printf("%s \n",Student2.surname);
printf("%s \n",Student2.department);
}
