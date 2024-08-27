#include "s21_smart_calc.h"

int priority(char sign) {
  int code = 0;
  switch (sign) {
    case '+':
    case '-':
      code = 1;
      break;
    case '*':
    case '/':
    case 'm':
      code = 2;
      break;
    case '^':
      code = 3;
      break;
    case 'c':
    case 's':
    case 't':
    case 'a':
    case 'l':
      code = 4;
      break;
    case ')':
      code = 5;
      break;
    case '(':
      code = 6;
      break;
  }
  return code;
}

OBJ *parser_str(char *array, OBJ *result, double x_num) {
  int flag_dot = 0;

  for (size_t i = 0; array[i] != '\0'; i++) {
    if (is_number(array[i])) {
      result = number_to_stack(array, i, result, &flag_dot);
    } else if (array[i] == 'x') {
      result = x_to_stack(result, x_num);
    } else if (array[i] == '.') {
      flag_dot = 1;
    } else if (is_sign(array[i], "start")) {
      result = sign_to_stack(array, &i, result);
    } else if (array[i] == '(' || array[i] == ')') {
      result = push(result, 0, array[i], "\0", priority(array[i]));
    } else if (is_function(array[i], "start")) {
      result = function_to_stack(array, &i, result);
    }
  }

  return result;
}

OBJ *x_to_stack(OBJ *result, double x_num) {
  result = push(result, x_num, 0, "\0", IS_NUM);

  return result;
}

OBJ *number_to_stack(char *array, size_t index, OBJ *result, int *flag_dot) {
  static int num_before_dot = 0;

  if (!is_number(array[index - 1]) && array[index - 1] != '.') {
    result = push(result, array[index] - '0', 0, "\0", IS_NUM);

  } else {
    if (*flag_dot) num_before_dot++;

    result->number = result->number * 10 + (array[index] - '0');

    if (*flag_dot && !is_number(array[index + 1])) {
      result->number /= pow(10, num_before_dot);
      num_before_dot = 0;
    }
  }

  if (!is_number(array[index + 1])) *flag_dot = 0;

  return result;
}

OBJ *sign_to_stack(char *array, size_t *index, OBJ *result) {
  if ((array[*index] == '-' || array[*index] == '+') &&
      (array[*index - 1] == '(' || *index == 0)) {
    result = push(result, 0, 0, "\0", -1);
  }
  result = push(result, 0, array[*index], "\0", priority(array[*index]));

  is_mod_sign(array, index);

  return result;
}

OBJ *function_to_stack(char *array, size_t *index, OBJ *result) {
  if (array[*index] == 'a') {
    if (array[*index + 1] == 'c')
      result = push(result, 0, 0, "acos", priority(array[*index]));
    else if (array[*index + 1] == 's')
      result = push(result, 0, 0, "asin", priority(array[*index]));
    else if (array[*index + 1] == 't')
      result = push(result, 0, 0, "atan", priority(array[*index]));

    *index += 3;
  } else if (array[*index] == 'c') {
    result = push(result, 0, 0, "cos", priority(array[*index]));
    *index += 2;
  } else if (array[*index] == 's') {
    if (array[*index + 1] == 'i') {
      result = push(result, 0, 0, "sin", priority(array[*index]));
      *index += 2;
    } else if (array[*index + 1] == 'q') {
      result = push(result, 0, 0, "sqrt", priority(array[*index]));
      *index += 3;
    }
  } else if (array[*index] == 't') {
    result = push(result, 0, 0, "tan", priority(array[*index]));
    *index += 2;
  } else if (array[*index] == 'l') {
    if (array[*index + 1] == 'n') {
      result = push(result, 0, 0, "ln", priority(array[*index]));
      *index += 1;
    } else if (array[*index + 1] == 'o') {
      result = push(result, 0, 0, "log", priority(array[*index]));
      *index += 2;
    }
  }

  return result;
}