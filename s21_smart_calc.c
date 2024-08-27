#include "s21_smart_calc.h"

int combo_calc(OBJ **stack_exprassion, char *str_exprassion, double x_num,
               double *result) {
  int code = CODE_TRUE;

  if (str_exprassion[0] != '\0') {
    code = validator(str_exprassion);

    if (code == CODE_TRUE) {
      *stack_exprassion = parser_str(str_exprassion, *stack_exprassion, x_num);
      *stack_exprassion = revers(*stack_exprassion);
      *stack_exprassion = polish_notation(*stack_exprassion);
      *stack_exprassion = revers(*stack_exprassion);

      code = calculator(stack_exprassion, result);
    }
  }

  return code;
}

int calculator(OBJ **exprassion, double *result) {
  int code = CODE_TRUE;
  OBJ *buffer_stack = NULL;

  while (code == CODE_TRUE && *exprassion != 0) {
    buffer_stack = move_num_to_stack(exprassion, buffer_stack);

    if (*exprassion != 0) {
      if ((*exprassion)->priority >= 1 && (*exprassion)->priority <= 3)
        *result = operation_is_sing(exprassion, &buffer_stack, &code);
      else if ((*exprassion)->priority == 4)
        *result = operation_is_function(exprassion, &buffer_stack, &code);
    }

    if (*exprassion == 0 && buffer_stack != 0) {
      *result = buffer_stack->number;
      buffer_stack = pop(buffer_stack);
    }

    if (*exprassion != 0)
      *exprassion = push(*exprassion, *result, 0, "\0", IS_NUM);
  }

  if (code == CODE_FALSE) {
    while (*exprassion != 0) *exprassion = pop(*exprassion);
    while (buffer_stack != 0) buffer_stack = pop(buffer_stack);
  }

  return code;
}

OBJ *move_num_to_stack(OBJ **exprassion, OBJ *buffer_stack) {
  int flag_exit = 0;

  while (!flag_exit) {
    if ((*exprassion)->priority == -1)
      move_to_another_stack(&buffer_stack, exprassion);
    else
      flag_exit = 1;

    if (*exprassion == NULL) flag_exit = 1;
  }

  return buffer_stack;
}

double operation_is_sing(OBJ **exprassion, OBJ **buffer_stack, int *code) {
  double result = 0;

  double value_2 = pop_value_from_stack(buffer_stack);
  double value_1 = pop_value_from_stack(buffer_stack);

  if ((*exprassion)->priority == 1)
    result = sum_sub(exprassion, value_1, value_2);
  else if ((*exprassion)->priority == 2)
    result = mul_div_mod(exprassion, value_1, value_2, code);
  else if ((*exprassion)->priority == 3) {
    result = pow(value_1, value_2);
    *exprassion = pop(*exprassion);
  }

  return result;
}

double pop_value_from_stack(OBJ **stack) {
  double value = (*stack)->number;
  *stack = pop(*stack);

  return value;
}

double sum_sub(OBJ **exprassion, double value_1, double value_2) {
  int code = (*exprassion)->sign == '+' ? 1 : -1;
  *exprassion = pop(*exprassion);

  return value_1 + (code * value_2);
}

double mul_div_mod(OBJ **exprassion, double value_1, double value_2,
                   int *code) {
  double result = 0;

  *code = CODE_TRUE;

  if ((*exprassion)->sign == '*')
    result = value_1 * value_2;
  else if (value_2 != 0.0) {
    if ((*exprassion)->sign == '/')
      result = value_1 / value_2;
    else
      result = fmod(value_1, value_2);
  } else
    *code = CODE_FALSE;

  *exprassion = pop(*exprassion);

  return result;
}

double operation_is_function(OBJ **exprassion, OBJ **buffer_stack, int *code) {
  double result = 0;

  double value = pop_value_from_stack(buffer_stack);

  if (strstr((*exprassion)->function, "acos"))
    result = is_acos_operation(value, code);
  else if (strstr((*exprassion)->function, "asin"))
    result = is_asin_operation(value, code);
  else if (strstr((*exprassion)->function, "atan"))
    result = atan(value);
  else if (strstr((*exprassion)->function, "cos"))
    result = cos(value);
  else if (strstr((*exprassion)->function, "sin"))
    result = sin(value);
  else if (strstr((*exprassion)->function, "tan"))
    result = tan(value);
  else if (strstr((*exprassion)->function, "log"))
    result = is_log_operation(value, code);
  else if (strstr((*exprassion)->function, "ln"))
    result = is_ln_operation(value, code);
  else if (strstr((*exprassion)->function, "sqrt"))
    result = is_sqrt_operation(value, code);

  *exprassion = pop(*exprassion);

  return result;
}

double is_sqrt_operation(double value, int *code) {
  double result = 0;

  if (value < 0)
    *code = CODE_FALSE;
  else
    result = sqrt(value);

  return result;
}

double is_acos_operation(double value, int *code) {
  double result = 0;

  if (value < -1 || value > 1)
    *code = CODE_FALSE;
  else
    result = acos(value);

  return result;
}

double is_asin_operation(double value, int *code) {
  double result = 0;

  if (value < -1 || value > 1)
    *code = CODE_FALSE;
  else
    result = asin(value);

  return result;
}

double is_log_operation(double value, int *code) {
  double result = 0;

  if (value <= 0)
    *code = CODE_FALSE;
  else
    result = log10(value);

  return result;
}

double is_ln_operation(double value, int *code) {
  double result = 0;

  if (value <= 0)
    *code = CODE_FALSE;
  else
    result = log(value);

  return result;
}