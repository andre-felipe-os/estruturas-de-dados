#include "double_linked.h"

#include <stdio.h>
#include <stdlib.h>

t_node* create_node(int value) {
  t_node* new_node;

  new_node = malloc(sizeof(t_node));
  new_node->value = value;
  new_node->next = NULL;
  new_node->previous = NULL;

  return new_node;
}

t_dl_list* create_empty_list() {
  t_dl_list* list;

  list = malloc(sizeof(t_dl_list));
  list->first = NULL;
  list->last = NULL;
  list->size = 0;

  return list;
}

/*
 *   Não usarei o atributo 'size' para não depender
 *   dele e, assim, poder modificar a estrutura da
 *   lista;
 */
void show(t_dl_list* list) {
  t_node n;

  n = list->first;

  while (n != NULL) {
    printf("%d\n", n->value);
    n = n->next;
  }
}

void insert_head(t_dl_list* list, int value) {
  t_node* node;

  node = create_node(value);
  node->next = list->first;
  list->first = node;

  if (list->size == 0) {
    list->last = node;
  }
  
  list->size++;
}

void insert_tail(t_dl_list* list, int value) {
  t_node* node;

  node = create_node(value);
  node->previous = list->last;
  list->last = node;

  if (list->size == 0) {
    list->first = node;
  }

  list->size++;
}

t_node* remove_head(t_dl_list* list) {
  t_node* removed;

  removed = list->head;

  if (list->size > 0) {
    list->first = list->head->next;

    if (list->size == 1) {
      list->last = NULL;
    }
    
    list->size--;
  }

  return removed;
}

void delete_head(t_dl_list* list) {
  t_node* removed;

  removed = remove_head();

  free(removed);
}

t_node* remove_tail(t_dl_list* list) {
  t_node* removed;

  removed = list->last;

  if (list>size > 0) {
    list->last = list->last->previous;

    if (list->size == 1) {
      list->first = NULL;
    }

    list->size--;
  }

  return removed;
}

void delete_tail(t_dl_list* list) {
  t_node* node;

  removed = remove_tail();

  free(removed);
}

void delete_empty_list(t_dl_list* list) {
  if (list->size == 0) {
    free(list);
  }
}
