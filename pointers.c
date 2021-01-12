#include <stdio.h>

int main()
{
  
  int a;
  int* ptrtoa;

  ptrtoa = &a;

  a = 5;
  printf("The value of a is %d\n", a);

  *ptrtoa = 6;
  printf("The value of a is %d\n", a);

  printf("The value of ptrtoa is %p\n", (void*)ptrtoa);
  printf("It stores the value %d\n", *ptrtoa);
  printf("The address of a is %p\n", (void*)&a);

  float d = 3.43;
  float e = 6.23;
  float temp = d;
  printf("The value of d is %f and the address of d is %p\n", d, (void*)&d);
  printf("the value of e is %f and the address of e is %p\n", e, (void*)&e);

  float* ptrtod = &d;
  float* ptrtoe = &e;

  *ptrtod = *ptrtoe;
  *ptrtoe = temp;
  printf("d is now %f and e is now %f\n", *ptrtod, *ptrtoe);

}
