#include "s21_string.h"

char *s21_strrchr(const char *str, int c) {
  char *str1 = s21_NULL;
  int a = s21_strlen(str);
  while (a >= 0) {
    if (str[a] == c) {
      str1 = (char *)str + a;
      break;
    }
    a--;
  }
  return str1;
}