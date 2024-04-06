#include "s21_string.h"

char *s21_strchr(const char *str, int c) {
  char *res = s21_NULL;
  size_t len = s21_strlen(str);
  while (len--) {
    if (*str++ == c) {
      res = (char *)str - 1;
      break;
    }
  }
  if (c == '\0') res = "\0";
  return res;
}
