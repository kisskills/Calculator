#include "s21_smartcalc.h"

void push_char_stack(struct char_stack** head, char data) {
  struct char_stack* ptr =
      (struct char_stack*)calloc(1, sizeof(struct char_stack));
  ptr->data = data;
  ptr->next = *head;
  *head = ptr;
}

char pop_char_stack(struct char_stack** head) {
  if (!head) exit(1);
  struct char_stack* ptr = *head;
  char data = ptr->data;
  *head = (*head)->next;
  free(ptr);
  return data;
}

// char peek_char_stack(struct char_stack* head) {
//   if (!head) exit(1);
//   return head->data;
// }
