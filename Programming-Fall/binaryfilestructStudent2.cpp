#include <stdio.h>   
#include <string.h>
#include <iostream>
#include <io.h>
using namespace std;

struct Student{
  int StudentID;
  char name[30];
  char surname[30];
  char department[20];
};
struct Student Student2;
FILE *f;
int i;
int choice;

void student_write(){
 printf("student id:");
 //scanf("%d",&);
 cin>>Student2.StudentID;
 printf("student name:");
 //gets(Student2.name);
 cin>>Student2.name; 
 printf("student surname:");
 //gets(Student2.surname);
 cin>>Student2.surname; 
 printf("student department:");
 cin>>Student2.department; 
 //gets(Student2.department);
 fseek(f,sizeof(struct Student)*(Student2.StudentID-1),SEEK_SET);
 fwrite(&Student2,sizeof(struct Student),1,f);   
}
void student_search(){
 int id;
 printf("student id:");
 scanf("%d",&id);
 fseek(f,sizeof(Student2)*(id-1),SEEK_SET);
 fread(&Student2,sizeof(Student2),1,f);
 printf("%d \n",Student2.StudentID);
 printf("%s \n",Student2.name);
 printf("%s \n",Student2.surname);
 printf("%s \n",Student2.department);
}
void student_list(){
 int i,number_of_students;
 number_of_students=filelength(fileno(f))/sizeof(struct Student);
 
 for (i=1;i<=number_of_students;i++){ 
   fseek(f,sizeof(struct Student)*(i-1),SEEK_SET);
   fread(&Student2,sizeof(struct Student),1,f);
   if (Student2.StudentID){   
  	 printf("%d \n",Student2.StudentID);
   	 printf("%s \n",Student2.name);
   	 printf("%s \n",Student2.surname);
  	 printf("%s \n",Student2.department);
   	 printf("\n");   	
 }
}
}
main(){
  f=fopen("student.dat","rb+");
 //if file doesnt exist create it
 if (!f){
 	f=fopen("student.dat","wb+");
 }
 
 
 do{
 	printf("1. add student\n");
 	printf("2. search student\n");
 	printf("3. list student\n");
 	printf("4. exit\n");
 	printf("choice:");
 	scanf("%d",&choice);
 	if (choice==1)
 	  student_write();
 	else if (choice==2)
 	  student_search();
 	else if (choice==3)
 	  student_list();
 }while(choice!=4);
 
fclose(f);
}
