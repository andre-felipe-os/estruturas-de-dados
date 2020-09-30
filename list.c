#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *anterior;
  struct node *proximo;
  int value;
};

typedef struct node Node;

void addNode(Node *first, int value) {
  Node *n = malloc(sizeof(Node));
  n->value = value;
  
  n->proximo = first;
  n->anterior = first->anterior;

  first->anterior = n;
  n->anterior->proximo = n;
}

void removeNode(Node *first, int value) {
  Node *i = first;

  while (i->value != value) {
    i = i->proximo;
  }

  i->anterior->proximo = i->proximo;
  i->proximo->anterior = i->anterior;
  free(i);
}

void showAll(Node *first) {
  Node *i = first;

  while (i != first->anterior) {
    printf("%d, ", i->value);
    i = i->proximo;
  }

  printf("%d\n", i->value);
}

int main() {
  Node *n1 = malloc(sizeof(Node));
  n1->value = 1;

  Node *n2 = malloc(sizeof(Node));
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
