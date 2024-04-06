#include "test_s21_string.h"

START_TEST(strtok1) {
  char str[100] = "Hell, hell, hell";
  char str1[100] = ",";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
  char str2[100] = "Hello/hello/hello/";
  char str3[100] = "/";
  ck_assert_pstr_eq(strtok(str2, str3), s21_strtok(str2, str3));
}
END_TEST

START_TEST(strtok2) {
  char str[100] = "Hell, hell, hell";
  char str1[100] = "Hell";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
}

END_TEST

START_TEST(strtok3) {
  char str[100] = "HellohelloHellohello";
  char str1[100] = "Hello";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
  char str2[] = "1234567890";
  char str3[100] = "456";
  ck_assert_pstr_eq(strtok(str2, str3), s21_strtok(str2, str3));
}
END_TEST

START_TEST(strtok4) {
  char str[] = "I wanna cry dream";
  char str1[100] = " ";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
  char str2[100] = "Hello School";
  char str3[100] = "Q";
  ck_assert_pstr_eq(strtok(str2, str3), s21_strtok(str2, str3));
}
END_TEST

START_TEST(strtok5) {
  char str[] = "Hello 21 School 21";
  char str1[100] = "21";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
  char str2[100] = "";
  char str3[100] = "l";
  ck_assert_ptr_null(s21_strtok(str2, str3));
  char str4[] = "";
  char str5[100] = "\0";
  ck_assert_pstr_eq(strtok(str4, str5), s21_strtok(str4, str5));
}
END_TEST

START_TEST(strtok6) {
  char str[] = "1234567890";
  char str1[100] = "21";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
  char str2[100] = "Hello School";
  char str3[100] = "21";
  ck_assert_pstr_eq(strtok(str2, str3), s21_strtok(str2, str3));
  char str4[] = "1234567890";
  char str5[100] = "457";
  ck_assert_pstr_eq(strtok(str4, str5), s21_strtok(str4, str5));
}
END_TEST

START_TEST(strtok7) {
  char str[] = "1234567890";
  char str1[100] = "5";
  ck_assert_pstr_eq(strtok(str, str1), s21_strtok(str, str1));
  char str2[100] = "!@#$%^&*(%)";
  char str3[100] = "%";
  ck_assert_pstr_eq(strtok(str2, str3), s21_strtok(str2, str3));
  char str4[100] = "q!qq!qq!qq!q";
  char str5[100] = "!";
  ck_assert_pstr_eq(strtok(str4, str5), s21_strtok(str4, str5));
}
END_TEST

Suite *test_s21_strtok() {
  Suite *s1 = suite_create("test_s21_strtok");
  TCase *tc1_1 = tcase_create("Core");

  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strtok1);
  tcase_add_test(tc1_1, strtok2);
  tcase_add_test(tc1_1, strtok3);
  tcase_add_test(tc1_1, strtok4);
  tcase_add_test(tc1_1, strtok5);
  tcase_add_test(tc1_1, strtok6);
  tcase_add_test(tc1_1, strtok7);

  return s1;
}