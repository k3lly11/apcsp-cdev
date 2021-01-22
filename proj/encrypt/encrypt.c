//
// encrypt.c
//

#include <string.h>

#include "encrypt.h"


char CHARS[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789";
int CHARS_LEN = 62;


char shiftChar(char c, int shift, int direction)
{
  // implement the character shift here:
  //  given a char c shift it either forwards (direction == 1) or backwards (direction == 0)
  //  use the CHARS array above
  //  return the newly shifted char
  //
  // eg.
  //   shiftChar('c', 3, 1) : 'f'
  //   shiftChar('S', 2, 0) : 'P'
  //   shiftChar('b', 3, 0) : '8'
  int index = 0;
  if (c <= 122 && c >=97){
    index = c-97;
    if (direction == 1) {
      if ((62-index) < shift){
        index = shift - (62-index);
        return CHARS[index];
      }
      return CHARS[index+shift];
    }
    else {
      if (index<shift) {
        index = 62 - (shift - index);
        return CHARS[index];
      }
      return CHARS[index-shift];
    }
  } else if (c <= 90 && c >=65){
    index = c - 65;
    index = index + 26;
    if (direction == 1) {
      if ((62-index) < shift){
        index = shift - (62-index);
        return CHARS[index];
      }
      return CHARS[index+shift];
    }
    else {
      if (index<shift) {
        index = 62 - (shift - index);
        return CHARS[index];
      }
      return CHARS[index-shift];
    }
  } else {
    index = c-48;
    index = index + 52;
    if (direction == 1) {
      if ((62-index) <= shift){
        index = shift - (62-index);
        return CHARS[index];
      }
      return CHARS[index+shift];
    }
    else {
      if (index<shift) {
        index = 62 - (shift - index);
        return CHARS[index];
      }
      return CHARS[index-shift];
    }
  }
}


void encrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 1);
  }
}


void decrypt(char str[], int shifts[], int shiftslen)
{
  for (int i = 0; i < strlen(str); i++) 
  {
    char c = str[i];

    str[i] = shiftChar(c, shifts[i%shiftslen], 0);
  }
}


void caesarEncrypt(char str[], int shift)
{
  int shifts[] = { shift };
  encrypt(str, shifts, 1);
}


void caesarDecrypt(char str[], int shift)
{
  int shifts[] = { shift };
  decrypt(str, shifts, 1);
}


