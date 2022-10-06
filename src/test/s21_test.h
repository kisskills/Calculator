#ifndef SRC_TEST_S21_TEST_H_
#define SRC_TEST_S21_TEST_H_

#include <check.h>
#include <errno.h>

#include "../s21_smartcalc.h"

Suite *suite_binary_operations_test(void);
Suite *suite_functions_test(void);

void run_tests(void);
void run_testcase(Suite *testcase);

#endif  // SRC_TEST_S21_TEST_H_
