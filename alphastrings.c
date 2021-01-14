#include <stdio.h>
#include <string.h>

int main() {

  char string1[27];
  char string2[27] = "abcdefghijklmnopqrstuvwxyz";

  for (int i =0; i<26; i++) {
    string1[i] = 'a' + i;
  }
  string1[26] = '\0';

  if (strcmp(string1, string2) == 0) {
    printf("string1 and string2 are the same\n");
  }

  for(int i = 0; i<26; i++) {
    string1[i] = string1[i]-32;
  }

  if (strcmp(string1, string2) == 0) {
    printf("string1 and string2 are the same\n");
  } else {
    printf("string1 and string2 are different\n");
  }

  char string3[54];
  strcpy(string3, string1);
  strcat(string3, string2);

  printf("string1: %s\n", string1);
  printf("string2: %s\n", string2);
  printf("string3: %s\n", string3);



}
