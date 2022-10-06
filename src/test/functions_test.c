#include "s21_test.h"

START_TEST(cos_only) {
  char* input = "cos(0)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = cos(0);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(sin_only) {
  char* input = "sin(5)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = sin(5);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(tan_only) {
  char* input = "tan(0)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = tan(0);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(acos_only) {
  char* input = "acos(0)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = acos(0);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(asin_only) {
  char* input = "asin(0)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = asin(0);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(atan_only) {
  char* input = "atan(5)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = atan(5);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(sqrt_only) {
  char* input = "sqrt(5)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = sqrt(5);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(ln_only) {
  char* input = "ln(5)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = log(5);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(log_only) {
  char* input = "log(5)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = log10(5);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_01) {
  char* input = "sin(21)+cos(0)*sqrt(25)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = sin(21) + cos(0) * sqrt(25);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_02) {
  char* input = "(ln(0.001)-log(1000))*atan(25)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = (log(0.001) - log10(1000)) * atan(25);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_x_01) {
  char* input = "sin(x)+cos(x)*sqrt(x)";
  char output[PARSER_MAX] = {0};
  double x = 25;
  double res = 0;
  double expected_res = sin(x) + cos(x) * sqrt(x);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, x);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_x_02) {
  char* input = "(ln(x)-log(1000))*atan(25)";
  char output[PARSER_MAX] = {0};
  double x = 0.001;
  double res = 0;
  double expected_res = (log(x) - log10(1000)) * atan(25);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, x);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_unary_operations) {
  char* input = "(-ln(+0.001)--log(+1000))*-atan(+25)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = (-log(+0.001) - -log10(+1000)) * -atan(+25);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(wrong_1) {
  char* input = "cos";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

START_TEST(wrong_2) {
  char* input = "cos+";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

Suite* suite_functions_test(void) {
  Suite* s = suite_create("suite_functions_test");
  TCase* tc = tcase_create("functions_test");

  tcase_add_test(tc, cos_only);
  tcase_add_test(tc, sin_only);
  tcase_add_test(tc, tan_only);
  tcase_add_test(tc, acos_only);
  tcase_add_test(tc, asin_only);
  tcase_add_test(tc, atan_only);
  tcase_add_test(tc, sqrt_only);
  tcase_add_test(tc, ln_only);
  tcase_add_test(tc, log_only);
  tcase_add_test(tc, mixed_01);
  tcase_add_test(tc, mixed_02);
  tcase_add_test(tc, mixed_x_01);
  tcase_add_test(tc, mixed_x_02);
  tcase_add_test(tc, mixed_unary_operations);
  tcase_add_test(tc, wrong_1);
  tcase_add_test(tc, wrong_2);

  suite_add_tcase(s, tc);
  return s;
}
