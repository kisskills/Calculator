#include "s21_smartcalc.h"

static int check_binary_operations_in_string(char *string);
static int check_functions_in_string(char *string);
static int check_brackets_in_string(char *string);
static int check_numbers_in_string(char *string);
static int check_other_in_string(char *string);

static int check_plus_minus(char ch);
static int is_bracket(char ch);

int check_string(char *string) {
  int res = OK;

  if ((res = check_brackets_in_string(string)) == OK) {
    if ((res = check_binary_operations_in_string(string)) == OK) {
      if ((res = check_functions_in_string(string)) == OK) {
        if ((res = check_numbers_in_string(string)) == OK) {
          res = check_other_in_string(string);
        }
      }
    }
  }

  return res;
}

static int check_binary_operations_in_string(char *string) {
  int res = OK;
  unsigned long str_length = strlen(string);

  for (unsigned long i = 0; i < str_length; i++) {
    if (is_binary_operation(string[i])) {
      if (!i || string[i - 1] == '(') {
        if (!check_plus_minus(string[i])) {
          res = ERROR;
        } else if (i == str_length - 1) {
          res = ERROR;
        } else if (!isdigit(string[i + 1]) && !is_function(&string[i + 1]) &&
                   string[i + 1] != 'x') {
          res = ERROR;
        }
      } else if (string[i - 1] == ')' || isdigit(string[i - 1]) ||
                 string[i - 1] == 'x') {
        if (i == str_length - 1) {
          res = ERROR;
        } else if (!check_plus_minus(string[i + 1])) {
          if (!isdigit(string[i + 1]) && !is_function(&string[i + 1]) &&
              string[i + 1] != '(' && string[i + 1] != 'x') {
            res = ERROR;
          }
        } else if ((i + 1) == (str_length - 1)) {
          res = ERROR;
        } else if (!isdigit(string[i + 2]) && !is_function(&string[i + 2]) &&
                   string[i + 2] != '(' && string[i + 1] != 'x') {
          res = ERROR;
        }
      }
    }
    if (res == ERROR) break;
  }

  return res;
}

static int check_functions_in_string(char *string) {
  int res = OK;
  long int str_length = strlen(string);
  int length = 0;

  for (long int i = 0; i < str_length; i++) {
    if (!is_binary_operation(string[i]) && !is_bracket(string[i]) &&
        !isdigit(string[i]) && string[i] != '.' && string[i] != 'x') {
      if ((length = is_function(&string[i])) != 0) {
        i += length - 1;
        if (i == str_length - 1) {
          res = ERROR;
        } else if (string[i + 1] != '(') {
          res = ERROR;
        }
      } else {
        res = ERROR;
      }
    }
    if (res) break;
  }

  return res;
}

static int check_brackets_in_string(char *string) {
  int res = OK;
  long int str_length = strlen(string);
  int br_counter = 0;

  for (long int i = 0; i < str_length; i++) {
    if (string[i] == '(') br_counter++;
    if (string[i] == ')') br_counter--;
    if (br_counter < 0) {
      res = ERROR;
      break;
    }
  }
  if (br_counter > 0) res = ERROR;

  return res;
}

static int check_numbers_in_string(char *string) {
  int res = OK;
  int flag = 0;
  unsigned long str_length = strlen(string);

  for (unsigned long i = 0; i < str_length; i++) {
    if (string[i] == '.') {
      if (!i || i == str_length - 1) {
        res = ERROR;
      } else if (!isdigit(string[i - 1]) || !isdigit(string[i + 1])) {
        res = ERROR;
      } else if (flag) {
        res = ERROR;
      } else {
        flag = 1;
      }
    } else if (!isdigit(string[i])) {
      flag = 0;
    }
    if (res) break;
  }

  return res;
}
static int check_other_in_string(char *string) {
  int res = OK;
  unsigned long str_length = strlen(string);

  for (unsigned long i = 0; i < str_length; i++) {
    if (string[i] == '(') {
      if (string[i + 1] == ')') res = ERROR;
    } else if (string[i] == 'x') {
      if (!i) {
        if (string[i + 1] == '\0' || is_binary_operation(string[i + 1])) {
        } else {
          res = ERROR;
        }
      } else if (isdigit(string[i - 1]) || isdigit(string[i + 1])) {
        res = ERROR;
      } else if (string[i + 1] != '\0' && string[i + 1] != ')' &&
                 !is_binary_operation(string[i + 1])) {
        res = ERROR;
      }
    } else if ((i != str_length - 1) &&
               (isdigit(string[i]) || string[i] == 'x')) {
      if (string[i + 1] == '(') res = ERROR;
    }
    if (res) break;
  }

  return res;
}
static int check_plus_minus(char ch) {
  int res = 0;
  if (ch == '+' || ch == '-') res = 1;
  return res;
}

static int is_bracket(char ch) {
  int res = 0;
  if (ch == '(' || ch == ')') res = 1;
  return res;
}

int check_x_value(char *string) {
  int res = OK;

  if (!string[0]) res = ERROR;
  if (!res) {
    for (unsigned long i = 0; i < strlen(string); i++) {
      if (i == 0 && string[i] == '-') continue;
      if (!isdigit(string[i]) && string[i] != '.') res = ERROR;
      if (res) break;
    }
  }
  if (!res) {
    res = check_numbers_in_string(string);
  }

  return res;
}
