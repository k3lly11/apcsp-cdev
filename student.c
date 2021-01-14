#include <stdio.h>



// student structure
//struct Student...

struct Student {
  char firstname[64];
  char lastname[64];
  int id;
  int age;
};


void printStudent(struct Student* student)
{
  printf("\nfirstname: %s\n", student->firstname);
  printf("lastname: %s\n", student->lastname);
  printf("id: %d\n", student->id);
  printf("age: %d\n", student->age);
}


void printAllStudents(struct Student students[], int num)
{
  // call printStudent for each student in students
  for(int i = 0; i < num; i++){
    printStudent(&students[i]);
  }
}


int main()
{

  // an array of students
  //xxx students;
  struct Student students[64];

  int numStudents = 0;
  while (1)
  {
    char c;
    char input[256];
    printf("\nEnter a to add, p to print, q to quit:");
    fgets(input, 256, stdin);
    if (sscanf(input, "%c", &c) != 1) continue;
    if (c == 'q') 
    {
      break;
    }
    else if (c == 'p')
    {
      // print all students
      printAllStudents(students, numStudents);
      continue;
    }
    else if (c == 'a')
    {
      // enter a new student
      numStudents++;
      char temp[256];
      printf("\nenter student's firstname: ");
      fgets(temp, 256, stdin);
      sscanf(temp, "%s", students[numStudents-1].firstname);
      printf("\nenter student's lastname: ");
      fgets(temp, 256, stdin);
      sscanf(temp, "%s", students[numStudents-1].lastname);
      printf("\nenter student's id: ");
      fgets(temp, 256, stdin);
      sscanf(temp, "%d", &students[numStudents-1].id);
      printf("\nenter student's age: ");
      fgets(temp, 256, stdin);
      sscanf(temp, "%d", &students[numStudents-1].age);
      
    }
  }
  
  printf("\nGoodbye!\n");
}



