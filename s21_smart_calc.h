#ifndef S21_SMART_CALC_H
#define S21_SMART_CALC_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_SYMBOLS 256
#define IS_NUM -1

typedef struct tag_obj {
  double number;
  char sign;
  int priority;
  char function[5];
  struct tag_obj *next;
} OBJ;

enum code_error { CODE_FALSE, CODE_TRUE };

/*--------------------stack----------------------*/

OBJ *push(OBJ *top, double number, char sign, char *function, int priority);
OBJ *pop(OBJ *top);
OBJ *revers(OBJ *top);
void show(const OBJ *top);

/*------------------validator--------------------*/

int validator(char *array);
int is_number(char symbol);
int is_sign(char symbol, char *start_end);
int is_mod_sign(char *array, size_t *index);
int is_function(char symbol, char *start_end);
int correct_name_function(char *array, size_t *index);

int sign_correct(char *array, size_t *index);
int breckets_correct(char *array, size_t *index, int *brackets);
int function_correct(char *array, size_t *index);
int x_correct(char *array, size_t *index);
int dot_correct(char *array, size_t *index, int *count_dot);

/*--------------------parser----------------------*/

int priority(char sign);
OBJ *parser_str(char *array, OBJ *result, double x_num);
OBJ *x_to_stack(OBJ *result, double x_num);
OBJ *number_to_stack(char *array, size_t index, OBJ *result, int *flag_dot);
OBJ *sign_to_stack(char *array, size_t *index, OBJ *result);
OBJ *function_to_stack(char *array, size_t *index, OBJ *result);

/*---------------polish notation------------------*/

OBJ *polish_notation(OBJ *result);
void move_to_another_stack(OBJ **dst, OBJ **src);

/*---------------smart calculator-----------------*/

int combo_calc(OBJ **stack_exprassion, char *str_exprassion, double x_num,
               double *result);
int calculator(OBJ **exprassion, double *result);
OBJ *move_num_to_stack(OBJ **exprassion, OBJ *buffer_stack);
double pop_value_from_stack(OBJ **stack);
double operation_is_sing(OBJ **exprassion, OBJ **buffer_stack, int *code);
double sum_sub(OBJ **exprassion, double value_1, double value_2);
double mul_div_mod(OBJ **exprassion, double value_1, double value_2, int *code);
double operation_is_function(OBJ **exprassion, OBJ **buffer_stack, int *code);
double is_sqrt_operation(double value, int *code);
double is_acos_operation(double value, int *code);
double is_asin_operation(double value, int *code);
double is_log_operation(double value, int *code);
double is_ln_operation(double value, int *code);

#endif