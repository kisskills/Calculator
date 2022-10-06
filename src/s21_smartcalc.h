#ifndef SRC_S21_SMARTCALC_H_
#define SRC_S21_SMARTCALC_H_

#include <ctype.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define INPUT_MAX 256
#define PARSER_MAX 512
#define OK 0
#define ERROR 1

typedef enum {
  LOW = 0,
  MEDIUM = 1,
  HIGHT = 2,
  SUPERHIGHT = 3,
} priority_calc;

struct char_stack {
  char data;
  struct char_stack* next;
};

struct double_stack {
  double data;
  struct double_stack* next;
};

void push_char_stack(struct char_stack** head, char data);
char pop_char_stack(struct char_stack** head);
char peek_char_stack(struct char_stack* head);

void push_double_stack(struct double_stack** head, double data);
double pop_double_stack(struct double_stack** head);
double peek_double_stack(struct double_stack* head);

int djkstra_algorithm(char* old_string, char* new_string);
int is_unary_operation(struct char_stack** head, char* string, int i);
int is_binary_operation(char ch);
int priority_calculation(char current, struct char_stack* previous);
int set_priority(char ch);
int is_function(char* ch);
int check_function(char* str);
void push_reverse_function(struct char_stack** head, char* string, int length);

double calculation_algorithm(char* string, double x);
void bin_operation_calc(char ch, struct double_stack** head);
void function_calc(char* string, struct double_stack* head, int length);

int check_string(char* string);
int check_x_value(char* string);
void mod_to_percent(char* old_string, char* new_string);
#endif  // SRC_S21_SMARTCALC_H_
