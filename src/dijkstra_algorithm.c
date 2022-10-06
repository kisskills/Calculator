#include "s21_smartcalc.h"

// static void mod_to_percent(char *old_string, char *new_string);

int djkstra_algorithm(char* old_string, char* new_string) {
  int res = OK;
  int length = 0;
  char ch = 0;
  struct char_stack* head = NULL;
  char buffer_string[INPUT_MAX] = {0};

  mod_to_percent(old_string, buffer_string);
  // res = check_string(buffer_string);
  // if (!res) {
  for (unsigned long i = 0; i < strlen(buffer_string); i++) {
    if (isdigit(buffer_string[i]) || (buffer_string[i] == '.') ||
        (buffer_string[i] == 'x')) {
      length = strlen(new_string);
      new_string[length] = buffer_string[i];
      if (!isdigit(buffer_string[i + 1]) && (buffer_string[i + 1] != '.')) {
        new_string[length + 1] = ' ';
        new_string[length + 2] = '\0';
      } else {
        new_string[length + 1] = '\0';
      }
    } else if (buffer_string[i] == '(') {
      push_char_stack(&head, '(');
    } else if (buffer_string[i] == ')') {
      while ((ch = pop_char_stack(&head)) != '(') {
        length = strlen(new_string);
        new_string[length] = ch;
        new_string[length + 1] = '\0';
      }
    } else if (is_binary_operation(buffer_string[i])) {
      if (is_unary_operation(&head, buffer_string, i)) {
      } else {
        while (head && head->data != '(' && !is_binary_operation(head->data)) {
          ch = pop_char_stack(&head);
          length = strlen(new_string);
          new_string[length] = ch;
          new_string[length + 1] = '\0';
        }
        while (priority_calculation(buffer_string[i], head)) {
          ch = pop_char_stack(&head);
          length = strlen(new_string);
          new_string[length] = ch;
          new_string[length + 1] = '\0';
        }
        push_char_stack(&head, buffer_string[i]);
      }
    } else if ((length = is_function(&buffer_string[i])) != 0) {
      push_reverse_function(&head, &buffer_string[i], length);
      i += length - 1;
    }
  }
  while (head) {
    length = strlen(new_string);
    new_string[length] = pop_char_stack(&head);
    new_string[length + 1] = '\0';
  }
  // }

  return res;
}

int is_unary_operation(struct char_stack** head, char* string, int i) {
  int res = 0;

  if (!i && is_binary_operation(string[i])) {
    if (string[i] == '+') res = 1;
    if (string[i] == '-') {
      push_char_stack(head, '~');
      res = 1;
    }
  } else if (i &&
             (is_binary_operation(string[i - 1]) || (string[i - 1] == '('))) {
    if (string[i] == '+') res = 1;
    if (string[i] == '-') {
      push_char_stack(head, '~');
      res = 1;
    }
  }

  return res;
}
int is_binary_operation(char ch) {
  int res = 0;

  if (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^' ||
      ch == '%')
    res = 1;

  return res;
}

int is_function(char* ch) {
  int i = 0;
  char* ptr = NULL;
  char func[10] = {0};

  for (ptr = ch; *ptr != '(' && *ptr != ' ' && *ptr != '\0' && *ptr != 'x';
       ptr++, i++) {
    func[i] = *ptr;
  }
  return check_function(func) ? i : 0;
}

int check_function(char* str) {
  char* res = NULL;
  int i = 0;
  char func_list[][6] = {"cos",  "sin",  "tan", "acos", "asin",
                         "atan", "sqrt", "ln",  "log"};
  for (i = 0; i < 9; i++) {
    res = strstr(func_list[i], str);
    if (res) {
      if (strlen(func_list[i]) != strlen(str)) res = NULL;
    }
    if (res) break;
  }
  return res ? (i + 1) : 0;
}

void push_reverse_function(struct char_stack** head, char* string, int length) {
  push_char_stack(head, ' ');
  for (char* ptr = string; length > 0; length--)
    push_char_stack(head, *(ptr + length - 1));
}

int priority_calculation(char current, struct char_stack* previous) {
  int res = 0;

  if (previous != NULL) {
    if (is_binary_operation(previous->data)) {
      if (set_priority(previous->data) >= set_priority(current)) {
        res = 1;
      }
    }
  }

  return res;
}

int set_priority(char ch) {
  int priority = LOW;

  switch (ch) {
    case '+':
    case '-':
      priority = LOW;
      break;
    case '*':
    case '/':
    case '%':
      priority = MEDIUM;
      break;
    case '^':
      priority = HIGHT;
      break;
    case '~':
      priority = SUPERHIGHT;
      break;
  }

  return priority;
}

void mod_to_percent(char* old_string, char* new_string) {
  unsigned long length = strlen(old_string);

  for (unsigned long i = 0, k = 0; i < length; i++, k++) {
    if (&old_string[i] == strstr(&old_string[i], "mod")) {
      new_string[k] = '%';
      i += 2;
    } else if (old_string[i] == ' ') {
      k--;
    } else {
      new_string[k] = old_string[i];
    }
  }
}
