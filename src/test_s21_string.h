#ifndef S21_TEST_STRING_H
#define S21_TEST_STRING_H

#include <check.h>
#define BUFF_SIZE 300
#include <stdio.h>
#include <string.h>

#include "s21_string.h"

Suite *test_s21_strrchr(void);
Suite *test_s21_strstr(void);
Suite *test_s21_strtok(void);

#endif