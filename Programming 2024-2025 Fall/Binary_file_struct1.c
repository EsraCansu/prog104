#include <stdio.h>
#include <conio.h>
//global type and variables definition
typedef struct {
    int id;
    char name[50];
    float salary;
} Employee;
// Define the struct
    Employee employee;
    
FILE * file;   
char ch;
 
void List_Employee(){
	// Read the structs present in the file
	fseek(file,0,SEEK_SET);
    while (!feof(file)) {
        fread(&employee, sizeof(Employee), 1, file);
        // Process the read data (e.g., print or manipulate)
        printf("Employee ID: %d, Name: %s, Salary: %.2f\n",
               employee.id, employee.name, employee.salary);
    }
}
void Register_Employee(){	
	printf("\nID:");
	scanf("%d",&employee.id);
	printf("Name:");
	scanf("%s",employee.name);
	printf("Salary:");
	scanf("%f",&employee.salary);
	fwrite(&employee, sizeof(Employee), 1, file);
}
int main()
{
    // open the file in rb mode
    file = fopen("employee.dat", "rb+");

    // check if the file was successfully opened
    if (file == NULL) {
        file = fopen("employee.dat", "wb+");
    }
    clrscr();
   do{
   	  printf("\n1. register an employee\n");
   	  printf("2. list employees\n");
   	  printf("3. exit\n");
   	  printf("choice:");
   	  ch=getche();
   	  if (ch=='1')
   	    Register_Employee();
   	  else if (ch=='2')
   	    List_Employee(); 
   	  else
   	    break;
     
   }while(1);
        
    // close the file
    fclose(file);
    return 0;
}
