#include "test_s21_string.h"

START_TEST(strstr1) {
  char str[100] = "Hello hello";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
  char str2[100] = "Hello, School";
  char str3[100] = "School";
  ck_assert_pstr_eq(strstr(str2, str3), s21_strstr(str2, str3));
}
END_TEST

START_TEST(strstr2) {
  char str[100] = "Hello, School 21";
  char str1[100] = "21";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
  char str2[100] = "1234567890";
  char str3[100] = "345";
  ck_assert_pstr_eq(strstr(str2, str3), s21_strstr(str2, str3));
}
END_TEST

START_TEST(strstr3) {
  char str[100] = "09876543";
  char str1[100] = "21";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
  char str2[100] = "1234567890";
  char str3[100] = "6787";
  ck_assert_pstr_eq(strstr(str2, str3), s21_strstr(str2, str3));
}
END_TEST

START_TEST(strstr4) {
  char str[100] = "0987654321";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
  char str2[100] = "Hello, School";
  char str3[100] = "21";
  ck_assert_pstr_eq(strstr(str2, str3), s21_strstr(str2, str3));
}
END_TEST

START_TEST(strstr5) {
  char str[100] = "Hello, School";
  char str1[100] = "Hello, School\0";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
  char str2[100] = "Hello, School\0";
  char str3[100] = "Hello, School";
  ck_assert_pstr_eq(strstr(str2, str3), s21_strstr(str2, str3));
}
END_TEST

START_TEST(strstr6) {
  char str[100] = "HelloSchoolhelloSchool";
  char str1[100] = "hello";
  ck_assert_pstr_eq(strstr(str, str1), s21_strstr(str, str1));
}
END_TEST

Suite *test_s21_strstr() {
  Suite *s1 = suite_create("test_s21_strstr");
  TCase *tc1_1 = tcase_create("Core");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strstr1);
  tcase_add_test(tc1_1, strstr2);
  tcase_add_test(tc1_1, strstr3);
  tcase_add_test(tc1_1, strstr4);
  tcase_add_test(tc1_1, strstr5);
  tcase_add_test(tc1_1, strstr6);

  return s1;
}