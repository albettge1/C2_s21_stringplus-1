#include "test_s21_string.h"

START_TEST(strrchr1) {
  char str[] = "WannaWANNAwana";
  ck_assert_str_eq(strrchr(str, 'a'), s21_strrchr(str, 'a'));
  char str1[] = "OlolololLo";
  ck_assert_str_eq(strrchr(str1, 'l'), s21_strrchr(str1, 'l'));
  char str2[] = "School 21,21111";
  ck_assert_str_eq(strrchr(str2, '1'), s21_strrchr(str2, '1'));
}
END_TEST

START_TEST(strrchr2) {
  char str[] = "Hello22, School 21";
  char ch = 50;
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}

END_TEST

START_TEST(strrchr3) {
  char str[] = "He    llo  School";
  char ch = 127;
  ck_assert_ptr_null(s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr4) {
  char str[] = "He0llo\0";
  char ch = 'l';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr5) {
  char str[] = "1203207444890";
  char ch = '0';
  ck_assert_pstr_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST

START_TEST(strrchr6) {
  char str[] = "Hell, School. Hell, School!";
  ck_assert_str_eq(strrchr(str, 'l'), s21_strrchr(str, 'l'));
}
END_TEST

START_TEST(strrchr7) {
  char str[] = "1*2#$*33&*90";
  char ch = 42;
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
END_TEST
START_TEST(strrchr8) {
  char str[] = "Hello, School soo";
  char ch = 83;
  ck_assert_str_eq(strrchr(str, ch), s21_strrchr(str, ch));
}
Suite *test_s21_strrchr() {
  Suite *s1 = suite_create("test_s21_strrchr");
  TCase *tc1_1 = tcase_create("Core");
  suite_add_tcase(s1, tc1_1);
  tcase_add_test(tc1_1, strrchr1);
  tcase_add_test(tc1_1, strrchr2);
  tcase_add_test(tc1_1, strrchr3);
  tcase_add_test(tc1_1, strrchr4);
  tcase_add_test(tc1_1, strrchr5);
  tcase_add_test(tc1_1, strrchr6);
  tcase_add_test(tc1_1, strrchr7);
  tcase_add_test(tc1_1, strrchr8);

  return s1;
}