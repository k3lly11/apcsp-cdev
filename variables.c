#include <stdio.h>

int main()
{
  int a;
  int b = 3;
  int c;

  a = 2;
  c = a + b;
  printf("Sum of %d and %d is %d\n", a, b, c);
  c = c - b;
  a = a + b;
  printf("a is %d\n c is %d\n", a, c);
}
