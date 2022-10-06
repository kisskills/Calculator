#include "s21_smartcalc.h"

void push_double_stack(struct double_stack** head, double data) {
  struct double_stack* ptr =
      (struct double_stack*)calloc(1, sizeof(struct double_stack));
  ptr->data = data;
  ptr->next = *head;
  *head = ptr;
}

double pop_double_stack(struct double_stack** head) {
  if (!head) exit(1);
  struct double_stack* ptr = *head;
  double data = ptr->data;
  *head = (*head)->next;
  free(ptr);
  return data;
}

// double peek_double_stack(struct double_stack* head) {
//   if (!head) exit(1);
//   return head->data;
// }
