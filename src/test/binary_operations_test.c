#include "s21_test.h"

START_TEST(sum_only) {
  char* input = "1+2";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = 1 + 2;

  check_string(input);
  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(sub_only) {
  char* input = "10.5-2.5";
  char output[PARSER_MAX] = {0};
  double res = 0.0;
  double expected_res = 10.5 - 2.5;

  check_string(input);
  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mul_only) {
  char* input = "5.2*4";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = 5.2 * 4;

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(div_only) {
  char* input = "513.7765/22.87";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = 513.7765 / 22.87;

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mod_only) {
  char* input = "124.5mod21.2";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = fmod(124.5, 21.2);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(pow_only) {
  char* input = "124.5^21.2";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = pow(124.5, 21.2);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_01) {
  char* input = "124.5mod21.2*25/137";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = fmod(124.5, 21.2) * 25 / 137;

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_02) {
  char* input = "123456.987+24.8*2-125/5";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = 123456.987 + 24.8 * 2 - 125 / 5;

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_03) {
  char* input = "((123456.987+24.8)*2-125)/5";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = ((123456.987 + 24.8) * 2 - 125) / 5;

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_04) {
  char* input = "5^5^2/5^5-4/2^2";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = pow(pow(5, 5), 2) / pow(5, 5) - 4 / pow(2, 2);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_05) {
  char* input = "(2 + 3) * -(2 + 3)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = (2 + 3) * -(2 + 3);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_x_01) {
  char* input = "(2 + x) * -(x + 3)";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double x = 8.5;
  double expected_res = (2 + x) * -(x + 3);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 8.5);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_x_02) {
  char* input = "5^x^x/5^5-4/2^2";
  char output[PARSER_MAX] = {0};
  double x = 5.0;
  double res = 0;
  double expected_res = pow(pow(5, x), x) / pow(5, 5) - 4 / pow(2, 2);

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 5.0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_unary_operations) {
  char* input = "((-123456.987+-24.8)*+2--125)/-5";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = ((-123456.987 + -24.8) * +2 - -125) / -5;

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(mixed_unary_plus) {
  char* input = "+5-+6";
  char output[PARSER_MAX] = {0};
  double res = 0;
  double expected_res = +5 - +6;

  djkstra_algorithm(input, output);
  res = calculation_algorithm(output, 0);
  ck_assert_double_eq(res, expected_res);
}
END_TEST

START_TEST(wrong_1) {
  char* input = "(2 + x)) * -(x + 3)";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

START_TEST(wrong_2) {
  char* input = "++2";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

START_TEST(wrong_3) {
  char* input = "3+";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

START_TEST(wrong_4) {
  char* input = "()";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

START_TEST(wrong_5) {
  char* input = "xx";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

START_TEST(wrong_6) {
  char* input = "3x4";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

START_TEST(wrong_7) {
  char* input = "5+x*";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

START_TEST(wrong_8) {
  char* input = "6+5++-7";

  ck_assert_int_eq(check_string(input), ERROR);
}
END_TEST

START_TEST(wrong_9) {
  char* input = "3.5.";

  ck_assert_int_eq(check_x_value(input), ERROR);
}
END_TEST

Suite* suite_binary_operations_test(void) {
  Suite* s = suite_create("suite_binary_operations_test");
  TCase* tc = tcase_create("binary_operations_test");

  tcase_add_test(tc, sum_only);
  tcase_add_test(tc, sub_only);
  tcase_add_test(tc, mul_only);
  tcase_add_test(tc, div_only);
  tcase_add_test(tc, mod_only);
  tcase_add_test(tc, pow_only);
  tcase_add_test(tc, mixed_01);
  tcase_add_test(tc, mixed_02);
  tcase_add_test(tc, mixed_03);
  tcase_add_test(tc, mixed_04);
  tcase_add_test(tc, mixed_05);
  tcase_add_test(tc, mixed_x_01);
  tcase_add_test(tc, mixed_x_02);
  tcase_add_test(tc, mixed_unary_operations);
  tcase_add_test(tc, mixed_unary_plus);
  tcase_add_test(tc, wrong_1);
  tcase_add_test(tc, wrong_2);
  tcase_add_test(tc, wrong_3);
  tcase_add_test(tc, wrong_4);
  tcase_add_test(tc, wrong_5);
  tcase_add_test(tc, wrong_6);
  tcase_add_test(tc, wrong_7);
  tcase_add_test(tc, wrong_8);
  tcase_add_test(tc, wrong_9);

  suite_add_tcase(s, tc);
  return s;
}
