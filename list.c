#include <stdio.h>
#include <stdlib.h>

// essa lista é circular ou não? o que isso implica?

struct s_node {
  struct s_node *next;
  struct s_node *previous;
  int value;
};

typedef struct s_node t_node;

struct s_list {
  t_node* first;
};

typedef struct s_list t_list;

// create_empty_list() and create_list(int* array);
t_list* create_empty_list() {
  t_list* list = malloc(sizeof(t_list));
  list->first = NULL;
  
  return list;
}

t_node* create_node(int value) {
  t_node* node = malloc(sizeof(t_node));
  node->next = NULL;
  node->previous = NULL;
  node->value = value;
  
  return node;
}

// insert_at_the_beginning() and insert_at_the_end();
// or insert_beginning() and insert_end();
// or insert_first() and insert_last();
// or insert_head() and insert_tail();
void insert_head(t_list list, int value) {
  t_node* node = create_node(value);
  node->proximo = list->first;
  node->anterior = list->last;

  list->first->anterior = node;
  list->last->proximo = node;

  list->first = node;
}

t_node* remove_first(t_list list) {
  t_node* node = list->first;

  list->first = node->next;
  list->first->previous = node->previous;
  node->previous->next = list->first;

  return node;
}

void delete_first(t_list list) {
  t_node* removed = remove_first(list);
  free(removed);
}

void print_list(t_list* list) {
  t_node *i = list->first->next;

  printf("%d", list->first->value);
  while (i != list->first) {
    printf(", %d, ", i->value);
    i = i->next;
  }
  printf(".\n", i->value);
}

int main() {
  
  return 0;
}
