#include "test_s21_string.h"

int main(void) {
  int failed = 0;
  Suite *test_s21_string[] = {
                              test_s21_strrchr(),
                              test_s21_strstr(),
                              test_s21_strtok(),
                              NULL};

  for (int i = 0; test_s21_string[i] != NULL; i++) { 
    SRunner *sr = srunner_create(test_s21_string[i]);

    srunner_set_fork_status(sr, CK_NOFORK);
    srunner_run_all(sr, CK_NORMAL);

    failed += srunner_ntests_failed(sr);
    srunner_free(sr);
  }
  printf("========= FAILED: %d =========\n", failed);

  return failed == 0 ? 0 : 1;
}