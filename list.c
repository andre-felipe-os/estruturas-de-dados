#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *anterior;
  struct node *proximo;
  int value;
};

typedef struct node t_node;

struct list {
  t_node *head;
};

typedef struct list t_list;

t_list *create_list() {
  t_list *list = malloc(sizeof(t_list));
  return list;
}

t_node *create_node() {
  t_node *node = malloc(sizeof(t_node));
  node->proximo = NULL;
  node->anterior = NULL;
  return node;
}

/*
t_node *init_node(int value) {
  t_node *node = malloc(sizeof(t_node));
  node->value = value;
  node->next = NULL;
  node->previous = NULL;
*/

void insert_to_head(t_list list, int value) {
  t_node *node = create_node();
  node->value = value;
  node->proximo = list->first;
  node->anterior = list->last;

  list->first->anterior = node;
  list->last->proximo = node;

  list->first = node;
}


void addNode(t_node *first, int value) {
  t_node *n = malloc(sizeof(t_node));
  n->value = value;
  
  n->proximo = first;
  n->anterior = first->anterior;

  first->anterior = n;
  n->anterior->proximo = n;
}

void removeNode(t_node *first, int value) {
  t_node *i = first;

  while (i->value != value) {
    i = i->proximo;
  }

  i->anterior->proximo = i->proximo;
  i->proximo->anterior = i->anterior;
  free(i);
}

void showAll(t_node *first) {
  t_node *i = first;

  while (i != first->anterior) {
    printf("%d, ", i->value);
    i = i->proximo;
  }

  printf("%d\n", i->value);
}

int main() {
  t_node *n1 = malloc(sizeof(t_node));
  n1->value = 1;

  t_node *n2 = malloc(sizeof(t_node));
  n2->value = 4;

  n1->proximo = n2;
  n1->anterior = n2;
  n2->proximo = n1;
  n2->anterior = n1;

  addNode(n1, -6);
  addNode(n1, -13);
  addNode(n1, 0);
  addNode(n1, 2);
  removeNode(n1, 4);

  //printf("%d, %d, %d\n", n1->anterior->value, n1->value, n1->proximo->value);
  showAll(n1);

  /*free(n1->anterior);
  free(n1);
  free(n2);*/
  
  return 0;
}
