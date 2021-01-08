#include<stdio.h>

int main()
{
  int a = 545;

  // print value and size of an int variable
  printf("int a value: %d and size: %lu bytes\n", a, sizeof(a));

  char b = 'z';
  printf("char b value: %c and size: %lu bytes\n", b, sizeof(b));

  float c = 6.442;
  printf("float c value: %f and size: %lu bytes\n", c, sizeof(c));

  double d = 2.4252522343;
  printf("double d value: %f and size: %lu bytes\n", d, sizeof(d));

  unsigned int e = 11;
  printf("unsigned int e value: %d and size: %lu bytes\n", e, sizeof(e));

  short int f = 4;
  printf("short int f value: %d and size: %lu bytes\n", f, sizeof(f));

}

