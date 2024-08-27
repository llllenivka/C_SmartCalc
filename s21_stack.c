#include "s21_smart_calc.h"

/**
 * @brief помещает элемент на вершину стека
 * */
OBJ *push(OBJ *top, double number, char sign, char *function, int priority) {
  OBJ *ptr = malloc(sizeof(OBJ));

  ptr->number = number;
  ptr->priority = priority;
  ptr->sign = sign;
  strcpy(ptr->function, function);
  ptr->next = top;

  return ptr;
}

/**
 * @brief снимает элемент с вершины стека, перемещая вершину на следующий
 * элемент
 * */
OBJ *pop(OBJ *top) {
  if (top == NULL) return top;

  OBJ *ptr_next = top->next;
  free(top);

  return ptr_next;
}

/**
 * @brief переворачивает стек
 * */
OBJ *revers(OBJ *top) {
  OBJ *ptr = NULL;
  while (top != 0) {
    ptr = push(ptr, top->number, top->sign, top->function, top->priority);
    top = pop(top);
  }

  return ptr;
}

// void show(const OBJ* top) {
//     const OBJ * current = top;

//     printf("\033[33m-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

//     while(current != 0) {
//         if(current->next == NULL) printf("\\/ ");
//         else printf("|| ");
//         printf("number = %lf\tsymbol = %c\tfunction = %s\tpryority = %d\n",
//         current->number, current->sign, current->function,
//         current->priority); current = current->next;
//     }
//     printf("NULL\n");

//     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\033[39m\n");
// }