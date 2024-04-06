#include "s21_string.h"

char *s21_strpbrk(const char *str1, const char *str2) {
  int status = 0, i = 0;
  char *symb = s21_NULL;
  for (i = 0; status == 0 && str1[i] != '\0'; i++) {
    for (int j = 0; status == 0 && str2[j] != '\0'; j++) {
      if (str1[i] == str2[j]) {
        status = 1;
        i--;
      }
    }
  }
  if (status)
    symb = (char *)str1 + i;
  else
    symb = s21_NULL;
  return symb;
}
