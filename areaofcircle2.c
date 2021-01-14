#include <stdio.h>
#include <math.h>

// for testing only - do not change
void getTestInput(int argc, char* argv[], int* a, int* b)
{
  if (argc == 3) {
    sscanf(argv[1], "%d", a);
    sscanf(argv[2], "%d", b);
  }
}



// add your areaOfCircle function here - it must NOT printf, instead it must
// return the result to be printed in main
float areaOfCircle(int radius) {
  float area = radius * radius * M_PI;
  return area; 
}



int main(int argc, char* argv[]) 
{
  int input1=-1;
  if (argv[1] != NULL) {sscanf(argv[1], "%d", &input1);}
  int input2 = -1;
  if (argv[2] != NULL) {sscanf(argv[2], "%d", &input2);}

  char temp[64];
  if (input1 == -1){
    printf("enter a start value: ");
    fgets(temp, 64, stdin);
    sscanf(temp, "%d", &input1);
  }
  if (input2 == -1){
    printf("enter an end value: ");
    fgets(temp, 64, stdin);
    sscanf(temp, "%d", &input2);
  }

  if (input1 < 0) {
    input1 = input1*-1;
  }
  if (input2 < 0) {
    input2 = input2*-1;
  }
  if (input2 < input1){
    input2 = input1;
  }

  int reps = input2 - input1;
  
  // for testing only - do not change
  //getTestInput(argc, argv, &input1, &reps);

  printf("calculating area of circle starting at %d, and ending at %d\n", input1, input2);
  
  // add your code below to call areaOfCircle function with values between
 // start and end

  for (int i = 0; i <= reps; i++) {
    printf("a circle with radius %d has area %f\n", input1 + i, areaOfCircle(input1 + i));
  }

}


