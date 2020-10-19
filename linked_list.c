#include <stdio.h>
#include <stdlib.h>

/* Single-Linked List */

struct s_node {
  struct s_node *next;
  int value;
};

typedef struct s_node t_node;

struct s_list {
  t_node* head;
  t_node* tail;
  int size;
};

typedef struct s_list t_list;

/* ------- Protótipos ------- */

t_list* create_empty_list();
t_list* create_list(int*, int);
void insert_head(t_list*, int);
void _bind_head(t_list*, t_node*);
void delete_first(t_list*);
t_node* remove_first(t_list*);
t_node* _create_node(int);

/* --- Fim dos Protótipos --- */

t_node* _create_node(int value) {
  t_node* node;

  node = malloc(sizeof(t_node));
  node->next = NULL;
  node->value = value;

  return node;
}

t_list* create_empty_list() {
  t_list* list;

  list = malloc(sizeof(t_list));
  list->head = NULL;
  list->tail = NULL;
  list->size = 0;
  
  return list;
}

void print_list(t_list* list) {
  t_node* iterator;

  iterator = list->first;
  while (iterator != NULL) {
    printf(" %d ", iterator->value);
    iterator = iterator->next;
  }
  printf("\n");
}

void insert_head(t_list* list, int value) {
  t_node* node;

  node = _create_node(value);
  node->next = list->head;
  list->head = node;
  if (list->size == 0) {
    list->tail = node;
  }
  list->size = list->size + 1;
}

void insert_tail(t_list* list, int value) {
  t_node* node;

  node = _create_node(value);
  if (list->size == 0) {
    list->head = node;
  } else {
    list->tail->next = node;
  }
  list->tail = node;
  list->size = list->size + 1;
}

void insert_index(t_list* list, int value, int index) {
  t_node* node;
  t_node* iterator;
  int i;

  if (index = 0) {
    insert_head(list, value);
  } else if (index = list->size) {
    insert_tail(list, value);
  } else if (index > 0 && index < list->size) {
    node = _create_node(value);
    iterator = list->first;
    i = 0;
    while (i != index) {
      iterator = iterator->next;
      i = i + 1;
    }
    iterator->previous->next = node;
    node->next = iterator;

    list->size = list->size + 1;
  }
}

t_list* create_list(int* values, int quantity) {
  t_list* list;
  int i;

  list = create_empty_list();
  for (i = 0; i < quantity; i++) {
    insert_tail(list, values[i]);
  }
  
  return list;
}

t_node* remove_first(t_list* list) {
  t_node* node;

  node = list->first;
  if (list->size > 0) {
    list->head = node->next;
    if (list->size == 1) {
      list->tail = NULL;
    }
    list->size = list->size - 1;
  }
  
  return node;
}

void delete_first(t_list* list) {
  t_node* removed;

  removed = remove_first(list);

  if (removed != NULL) {
    free(removed);
  }
}

t_node* remove_last(t_list* list) {
  t_node* node;

  node = list->last;
  if (list->size > 0) {
    // OPS, eu teria que iterar a lista até o penúltimo para atualizar list->tail
    list->size = list->size - 1;
  }

  return node;
}

void delete_last(t_list* list) {
  t_node* removed;

  removed = remove_last(list);

  if (removed != NULL) {
    free(removed);
  }
}

int main() {
  int array[] = {1, 2, 3, 4, 5};

  t_list* list_0 = create_list(array, 5);
  print_list(list_0);
  delete_first(list_0);
  t_node* node_0 = remove_first(list_0);
  printf("O %d foi removido.\n", node_0->value);
  insert_head(list_0, 15);
  insert_head(list_0, 22);
  insert_head(list_0, 13);
  insert_head(list_0, 89);
  print_list(list_0);
  
  return 0;
}
