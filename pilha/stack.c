#include "stack.h"

void stack(t_stack* stack, t_container* container) {
  container->next = stack->top_container;
  stack->top_container = container;
  stack->containers_quantity += 1;
}

t_container* unstack(t_stack* stack) {
  t_container container;

  container = stack->top_container;

  if (stack->containers_quantity > 0) {
    stack->top_container = stack->top_container->next;
    stack->containers_quantity -= 1;
  }

  return container;
}

t_container* create_container(int value) {
  t_container *new_container;
  
  new_container = malloc(sizeof(t_container));

  new_container->value = value;
  new_container->next = NULL;

  return new_container;
}

t_stack* create_empty_stack() {
  t_stack *new_stack;

  new_stack = malloc(sizeof(t_stack));

  new_stack->containers_quantity = 0;
  new_stack->top_container = NULL;

  return new_stack;
}

void delete_empty_stack(t_stack* stack) {
  if (stack->containers_quantity == 0) {
    free(stack);
  }
}
