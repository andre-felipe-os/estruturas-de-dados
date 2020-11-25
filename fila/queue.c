#include "queue.h"

void append(t_queue* queue, t_container* container) {
  if (queue->containers_quantity == 0) {
    queue->first_container = container;
  } else {
    queue->last_container->next = container;
  }
  queue->last_container = container;
  queue->container_quantity += 1;
}

t_container* get_next(t_queue* queue) {
  t_container* first_container;

  first_container = queue->first_container;

  if (queue->containers_quantity > 0) {
    queue->first_container = queue->first_container->next;
    
    if (queue->containers_quantity == 1) {
      queue->last_container = NULL;
    }
  
    queue->containers_quantity -= 1;
  }

  return first_container;
}

t_container* create_container(int value) {
  t_container *new_container;
  
  new_container = malloc(sizeof(t_container));

  new_container->value = value;
  new_container->next = NULL;

  return new_container;
}

t_queue* create_empty_queue() {
  t_queue *new_queue;

  new_queue = malloc(sizeof(t_queue));

  new_queue->containers_quantity = 0;
  new_queue->first_container = NULL;
  new_queue->last_container = NULL;

  return new_queue;
}

void delete_empty_queue(t_queue* queue) {
  if (queue->containers_quantity == 0) {
    free(queue);
  }
}
