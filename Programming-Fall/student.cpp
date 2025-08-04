#include <iostream>
#include <cstdlib> // for rand and srand functions
#include <ctime>   // for time function

using namespace std;

class Student {
public:
  string name;
  string surname;
  int grade;
};

int main() {
    
  srand(static_cast<unsigned int>(time(0)));
  
  int randomNumber = rand() % 101;
  
  Student s[3];
  
  for (int i = 0; i < 3; ++i) {
        s[i].name="Esra";
        students[i].displayInfo();
    }
  s1.name = "Esra";
  s1.surname = "Kavalci";
  s1.grade = randomNumber;

  cout << "Student 1 Name: " << s1.name << endl;
  cout << "Student 1 Surname: " << s1.surname << endl;
  cout << "Student 1 Grade: " << s1.grade << endl;
  return 0;
}

