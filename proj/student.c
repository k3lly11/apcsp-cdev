//
// student.c
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "student.h"
#include "encrypt.h"

const char* STUFILE = "studentdata.txt";

// keeps track of the number of students in the students array
int numStudents = 0;

// holds the student pointer array
Student* students[100] = {0};


void createStudent(char* fname, char* lname, int age, int id)
{
  // createStudent dynamically creates a Student on the heap and adds that
  // student to the student array
  //  - the firstName and lastName strings should be dynamically created
  //    based on the size of the fname and lname args

  Student* st = (Student*)malloc(sizeof(Student));
  char* first = (char*)malloc(100*sizeof(char));
  char* last = (char*)malloc(100*sizeof(char));
  strcpy(first, fname);
  strcpy(last, lname);
  st->firstName = first;
  st->lastName = last;
  st->age = age;
  st-> id = id;
  students[numStudents] = st;
  numStudents++;
}


void deleteStudent(Student* student)
{
  free(student);
  // free the memory associated with a student including the strings
}


void deleteStudents()
{
  for (int i = 0; i < numStudents; i++) {
    deleteStudent(students[0]);
    students[i]=NULL;
  }
  numStudents = 0;
  // iterate over the students array deleting every student and setting te pointer
  // values to 0 and adjusting the numStudents to 0
}


void saveStudents(int key)
{
  // save all students in the student array to a file 'studentdata.txt' overwriting
  // any existing file
  //   - the format of the file is one line per student as follows fname lname age id:
  //       tom thumb 15 1234 
  //       james dean 21 2345 
  //       katy jones 18 4532 

  FILE* fp;
  fp = fopen("studentdata.txt", "w");
  if (fp) {
    if (key != 0) {
      for (int i=0; i<numStudents; i++) {
	char encryptedf[100] = {0};
        char encryptedl[100] = {0};
        char encrypteda[100] = {0};
        char encryptedi[100] = {0};
        sprintf(encrypteda, "%d",  students[i]->age);
        sprintf(encryptedi, "%ld",  students[i]->id);
        sprintf(encryptedf, "%s", students[i]->firstName);
        sprintf(encryptedl, "%s", students[i]->lastName);
	for(int j = 0; j<100; j++) {
	  if(encryptedf[j] != '\0') {encryptedf[j] = shiftChar(encryptedf[j], key, 1);}
          if(encryptedl[j] != '\0') {encryptedl[j] = shiftChar(encryptedl[j], key, 1);}
          if(encrypteda[j] != '\0') {encrypteda[j] = shiftChar(encrypteda[j], key, 1);}
          if(encryptedi[j] != '\0') {encryptedi[j] = shiftChar(encryptedi[j], key, 1);}
	  if(encryptedf[j] == '\0' && encryptedl[j] == '\0'  && encrypteda[j] == '\0' && encryptedi[j] == '\0')
	  {break;}
	}
	printf("Saving: %s %s %s %s\n", encryptedf, encryptedl, encrypteda, encryptedi);
        fprintf(fp, "%s %s %s %s\n", encryptedf, encryptedl, encrypteda, encryptedi);
      }
    } else {
      for (int i = 0; i < numStudents; i++) {
        printf("Saving: %s %s %d %ld\n", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
        fprintf(fp, "%s %s %d %ld\n", students[i]->firstName, students[i]->lastName, students[i]->age, students[i]->id);
      }
    }
    fclose(fp);
  }
}

void loadStudents(int key)
{
  deleteStudents();
  // load the students from the data file overwriting all exisiting students in memory
  FILE* fp;
  fp = fopen("studentdata.txt", "r");
  if(fp) {
    if (key != 0) {
      while(1) {
        char tempf[100] = {0}; char templ[100] = {0}; char tempa[100] = {0}; char tempi[100] = {0};
        if (fscanf(fp, "%s %s %s %s\n", tempf, templ, tempa, tempi) >= 1) {
          for(int j = 0; j<100; j++) {
            if(tempf[j] != '\0') {tempf[j] = shiftChar(tempf[j], key, 0);}
            if(templ[j] != '\0') {templ[j] = shiftChar(templ[j], key, 0);}
            if(tempa[j] != '\0') {tempa[j] = shiftChar(tempa[j], key, 0);}
            if(tempi[j] != '\0') {tempi[j] = shiftChar(tempi[j], key, 0);}
            if(tempf[j] == '\0' && templ[j] == '\0'  && tempa[j] == '\0' && tempi[j] == '\0')
            {break;}
          }
	  int tempage = atoi(tempa);
	  int tempid = atoi(tempi);
          createStudent(tempf, templ, tempage, tempid);
        }else {
          break;
        }
      }

    } else {
      while(1) {
        char tempf[100]; char templ[100]; int tempa; int tempi;
        if (fscanf(fp, "%s %s %d %d\n", tempf, templ, &tempa, &tempi) >= 1) {
	  createStudent(tempf, templ, tempa, tempi);
        }else {
	  break;
	}
      }
    }
  fclose(fp);
  }
  printf("loaded %d students\n", numStudents);
}


void printStudent(Student* student)
{
  printf("  Student: %s %s\n", student->firstName, student->lastName);
  printf("    age: %d\n", student->age);
  printf("    id: %ld\n", student->id); 
}


void printStudents()
{
  for (int i = 0; i < numStudents; i++) {
    printf("\n----- student %d ------\n", i);
    printStudent(students[i]);
  }
}




