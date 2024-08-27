#include "s21_smart_calc.h"

/**
 * @brief проверка на правильный ввод выражения в строку
 * */
int validator(char *array) {
  int code = CODE_TRUE;
  int brackets = 0;
  int count_dot = 0;

  // if(array[0] == '\0') code = CODE_FALSE;

  for (size_t i = 0; array[i] != '\0' && code == CODE_TRUE; i++) {
    if (count_dot && !is_number(array[i]) && array[i] != '.') count_dot = 0;

    if (is_number(array[i])) {
      if (array[i] == '0' && !is_number(array[i - 1]) &&
          is_number(array[i + 1]) && count_dot == 0)
        code = CODE_FALSE;
      continue;
    } else if (array[i] == '.')
      code = dot_correct(array, &i, &count_dot);
    else if (array[i] == 'x')
      code = x_correct(array, &i);
    else if (is_function(array[i], "start"))
      code = function_correct(array, &i);
    else if (array[i] == '(' || array[i] == ')')
      code = breckets_correct(array, &i, &brackets);
    else if (is_sign(array[i], "start"))
      code = sign_correct(array, &i);
    else
      code = CODE_FALSE;
  }

  if (brackets != 0) code = CODE_FALSE;

  return code;
}

/**
 * @brief проверка на правильность ввода соседних символов от точки
 * */
int dot_correct(char *array, size_t *index, int *count_dot) {
  int code = CODE_TRUE;

  code = is_number(array[*index - 1]) && is_number(array[*index + 1]);
  *count_dot += 1;
  if (*count_dot > 1) code = CODE_FALSE;

  return code;
}

/**
 * @brief проверка на правильность ввода соседних символов от икса
 * */
int x_correct(char *array, size_t *index) {
  int code = CODE_TRUE;

  if (*index != 0)
    code = is_sign(array[*index - 1], "end") || array[*index - 1] == '(';
  if (*index != strlen(array) - 1 && code == CODE_TRUE)
    code = is_sign(array[*index + 1], "start") || array[*index + 1] == ')';

  return code;
}

/**
 * @brief проверка на правильность ввода соседних символов от функции
 * */
int function_correct(char *array, size_t *index) {
  int code = CODE_TRUE;

  if (*index != 0)
    code = array[*index - 1] == '(' || is_sign(array[*index - 1], "end");
  if (code != CODE_FALSE) code = correct_name_function(array, index);
  if (code != CODE_FALSE) code = array[*index + 1] == '(';

  return code;
}

/**
 * @brief проверка на правильность ввода соседних символов и  правильное
 * закрытие/открытие скобок
 * */
int breckets_correct(char *array, size_t *index, int *brackets) {
  int code = CODE_TRUE;

  code = !(array[*index] == '(' && array[*index + 1] == ')');
  if (array[*index] == '(')
    *brackets += 1;
  else
    *brackets -= 1;

  if (array[*index] == '(' && is_number(array[*index - 1])) code = CODE_FALSE;
  if (array[*index] == ')' && is_number(array[*index + 1])) code = CODE_FALSE;

  if (*brackets < 0) code = CODE_FALSE;

  return code;
}

/**
 * @brief проверка на правильность ввода соседних символов от знака
 * */
int sign_correct(char *array, size_t *index) {
  int code = CODE_TRUE;

  code = is_number(array[*index - 1]) || array[*index - 1] == ')' ||
         (array[*index - 1] == '(' && array[*index] == '-') ||
         array[*index - 1] == 'x';
  if (array[*index] == 'm' && code == CODE_TRUE)
    code = is_mod_sign(array, index);
  if (*index == 0 && (array[*index] == '+' || array[*index] == '-'))
    code = CODE_TRUE;
  if (code == CODE_TRUE)
    code = is_number(array[*index + 1]) ||
           is_function(array[*index + 1], "start") ||
           array[*index + 1] == '(' || array[*index + 1] == 'x';

  return code;
}

int is_number(char symbol) {
  int code = CODE_FALSE;
  if (symbol >= 48 && symbol <= 57) code = CODE_TRUE;

  return code;
}

int is_sign(char symbol, char *start_end) {
  int code = CODE_FALSE;

  if (symbol == '+' || symbol == '-' || symbol == '*' || symbol == '/' ||
      symbol == '^') {
    code = CODE_TRUE;
  }

  if (code == CODE_FALSE) {
    if (strstr(start_end, "start")) {
      if (symbol == 'm') code = CODE_TRUE;
    } else if (strstr(start_end, "end")) {
      if (symbol == 'd') code = CODE_TRUE;
    }
  }

  return code;
}

int is_mod_sign(char *array, size_t *index) {
  int code = CODE_FALSE;

  char buffer[3] = {0};

  for (int i = 0; i < 3; i++) {
    buffer[i] = array[*index + i];
  }

  if (strstr(buffer, "mod") != NULL) {
    *index += 2;
    code = CODE_TRUE;
  }

  return code;
}

int is_function(char symbol, char *start_end) {
  int code = CODE_FALSE;

  if (strstr(start_end, "end") != NULL) {
    if (symbol == 's' || symbol == 'n' || symbol == 't' || symbol == 'g')
      code = CODE_TRUE;
  } else if (strstr(start_end, "start") != NULL) {
    if (symbol == 'c' || symbol == 's' || symbol == 't' || symbol == 'a' ||
        symbol == 'l')
      code = CODE_TRUE;
  }

  return code;
}

int correct_name_function(char *array, size_t *index) {
  int code = CODE_FALSE;

  char buffer[5] = {0};

  for (size_t i = 0; i < 4; i++) {
    buffer[i] = array[i + *index];
  }

  if (strstr(buffer, "acos") != NULL || strstr(buffer, "asin") != NULL ||
      strstr(buffer, "atan") != NULL || strstr(buffer, "sqrt") != NULL) {
    *index += 3;
    code = CODE_TRUE;
  }

  if (code == CODE_FALSE) {
    if (strstr(buffer, "cos") != NULL || strstr(buffer, "sin") != NULL ||
        strstr(buffer, "tan") != 0 || strstr(buffer, "log") != NULL) {
      *index += 2;
      code = CODE_TRUE;
    }
  }

  if (code == CODE_FALSE) {
    if (strstr(buffer, "ln") != NULL) {
      *index += 1;
      code = CODE_TRUE;
    }
  }

  return code;
}