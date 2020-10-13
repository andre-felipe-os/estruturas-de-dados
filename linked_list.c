#include <stdio.h>
#include <stdlib.h>

struct s_node {
  struct s_node *next;
  int value;
};

typedef struct s_node t_node;

struct s_list {
  t_node* first; // or head?
};

typedef struct s_list t_list;

t_list* create_empty_list();
t_list* create_list(int*, int);
void insert_head(t_list*, int);
void _bind_head(t_list*, t_node*);
void delete_first(t_list*);
t_node* remove_first(t_list*);
t_node* _create_node(int);
int _is_empty(t_list*);

t_list* create_empty_list() {
  t_list* list;

  list = malloc(sizeof(t_list));
  list->first = NULL;
  
  return list;
}

t_list* create_list(int* values, int quantity) {
  t_list* list;
  int i;

  list = create_empty_list();
  for (i = quantity - 1; i >= 0; i--) {
    insert_head(list, values[i]);
  }

  return list;
}

void insert_head(t_list* list, int value) {
  t_node* node;

  node = _create_node(value);
  _bind_head(list, node);
}

void _bind_head(t_list* list, t_node* node) {
  node->next = list->first;
  list->first = node;
}

t_node* remove_first(t_list* list) {
  t_node* node;

  node = list->first;
  list->first = node->next;

  return node;
}

void delete_first(t_list* list) {
  t_node* removed;

  removed = remove_first(list);

  free(removed);
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

int _is_empty(t_list* list) {
  if (list->first == NULL) return 1;
  else return 0;
}

t_node* _create_node(int value) {
  t_node* node;

  node = malloc(sizeof(t_node));
  node->value = value;
  node->next = NULL;

  return node;
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
