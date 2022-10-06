#include "s21_smartcalc.h"

double calculation_algorithm(char *string, double x) {
  struct double_stack *head = NULL;
  int length = 0;
  for (unsigned long i = 0; i < strlen(string); i++) {
    if (isdigit(string[i])) {
      push_double_stack(&head, atof(&string[i]));
      while (isdigit(string[i]) || (string[i] == '.')) i++;
    } else if (string[i] == 'x') {
      push_double_stack(&head, x);
    } else if (is_binary_operation(string[i]) || (string[i] == '~')) {
      bin_operation_calc(string[i], &head);
    } else if ((length = is_function(&string[i])) != 0) {
      function_calc(&string[i], head, length);
      i += length - 1;
    }
  }
  return pop_double_stack(&head);
}

void bin_operation_calc(char ch, struct double_stack **head) {
  if (*head) {
    switch (ch) {
      case '+':
        (*head)->next->data += (*head)->data;
        pop_double_stack(head);
        break;
      case '-':
        (*head)->next->data -= (*head)->data;
        pop_double_stack(head);
        break;
      case '*':
        (*head)->next->data *= (*head)->data;
        pop_double_stack(head);
        break;
      case '/':
        (*head)->next->data /= (*head)->data;
        pop_double_stack(head);
        break;
      case '%':
        (*head)->next->data = fmod((*head)->next->data, (*head)->data);
        pop_double_stack(head);
        break;
      case '^':
        (*head)->next->data = pow((*head)->next->data, (*head)->data);
        pop_double_stack(head);
        break;
      case '~':
        (*head)->data = -((*head)->data);
        break;
    }
  }
}

void function_calc(char *string, struct double_stack *head, int length) {
  char str[6] = {0};
  int i = 0;
  for (char *ptr = string; length > 0; ptr++, length--, i++) {
    str[i] = *ptr;
  }
  i = check_function(str);
  if (head) {
    switch (i) {
      case 1:
        head->data = cos(head->data);
        break;
      case 2:
        head->data = sin(head->data);
        break;
      case 3:
        head->data = tan(head->data);
        break;
      case 4:
        head->data = acos(head->data);
        break;
      case 5:
        head->data = asin(head->data);
        break;
      case 6:
        head->data = atan(head->data);
        break;
      case 7:
        head->data = sqrt(head->data);
        break;
      case 8:
        head->data = log(head->data);
        break;
      case 9:
        head->data = log10(head->data);
        break;
    }
  }
}
