#include "s21_smart_calc.h"

OBJ *polish_notation(OBJ *src) {
  OBJ *dst = NULL;
  OBJ *signs = NULL;
  int count_sign = 0;

  while (src != NULL) {
    if (src->priority == IS_NUM)
      move_to_another_stack(&dst, &src);
    else if (src->priority >= 1 && src->priority <= 4) {
      while (count_sign && signs->priority >= src->priority &&
             signs->priority != 6) {
        move_to_another_stack(&dst, &signs);
        count_sign--;
      }

      signs = push(signs, src->number, src->sign, src->function, src->priority);
      src = pop(src);

      count_sign++;

    } else if (src->priority == 6) {
      move_to_another_stack(&signs, &src);
    } else if (src->priority == 5) {
      while (signs->priority != 6) {
        move_to_another_stack(&dst, &signs);
        if (count_sign > 0) count_sign--;
      }
      signs = pop(signs);
      src = pop(src);
    }
  }

  while (signs != NULL) move_to_another_stack(&dst, &signs);

  return dst;
}

void move_to_another_stack(OBJ **dst, OBJ **src) {
  *dst = push(*dst, (*src)->number, (*src)->sign, (*src)->function,
              (*src)->priority);
  *src = pop(*src);
}
