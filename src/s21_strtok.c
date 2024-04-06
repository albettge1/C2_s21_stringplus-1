#include "s21_string.h"

char *s21_strtok(char *str, const char *delim) {
  static char *rez;
  char *res;
  if (str != s21_NULL) {
    rez = str;
  }
  if (rez == s21_NULL || *rez == '\0') {
    rez = s21_NULL;
  }
  while (*rez != '\0' && s21_strchr(delim, *rez) != NULL) {
    rez++;
  }
  char *delim_pos = s21_strpbrk(rez, delim);
  if (delim_pos != s21_NULL) {
    *delim_pos = '\0';
    res = rez;
    rez = delim_pos + 1;
  } else {
    res = rez;
    rez = s21_NULL;
  }
  return res;
}