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

FILE *f;
int i;
main(){
 f=fopen("student.dat","wb");
 if (!f){
 	printf("file is not created\n");
 	return 1;
 }
 
 // Assign values to members of myStructure
Student2.StudentID = 1;
strcpy(Student2.name,"a");
strcpy(Student2.surname,"b");
strcpy(Student2.department,"ceng");
fwrite(&Student2,sizeof(Student2),1,f); 

Student2.StudentID = 2;
strcpy(Student2.name,"c");
strcpy(Student2.surname,"d");
strcpy(Student2.department,"ceng");
fwrite(&Student2,sizeof(Student2),1,f);   
  
fclose(f);
f=fopen("student.dat","rb");
i=2;//studentid
fseek(f,sizeof(Student2)*(i-1),SEEK_SET);
fread(&Student2,sizeof(Student2),1,f);

printf("%d \n",Student2.StudentID);
printf("%s \n",Student2.name);
printf("%s \n",Student2.surname);
printf("%s \n",Student2.department);
fclose(f);
}
