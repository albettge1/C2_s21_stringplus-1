#include "s21_string.h"

char *s21_strstr(const char *haystack, const char *needle) {
  char *new_haystack = (char *)haystack;
  char *new_needle = (char *)needle;
  char *res = s21_NULL;
  int len_needle = 0;
  len_needle = s21_strlen(new_needle);
  if (len_needle == 0) res = new_haystack;
  int i = 0;
  while (new_haystack[i] != 0) {
    if (new_haystack[i] == *new_needle) {
      int i1 = i;
      for (int count_nl = 0; count_nl <= len_needle; i1++, count_nl++) {
        if (count_nl == len_needle) {
          int ptr = i;
          res = &new_haystack[ptr];
        }
        if (new_haystack[i1] != new_needle[count_nl]) break;
      }
    }
    i++;
  }
  return res;
}