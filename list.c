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
}

int main() {
  Node *n1 = malloc(sizeof(Node));
  n1->value = 1;

  Node *n2 = malloc(sizeof(Node));
  n2->value = 4;

  n1->proximo = n2;
  n2->anterior = n1;

  addNode(n1, -6);

  printf("%d, %d, %d\n", n1->anterior->value, n1->value, n1->proximo->value);

  free(n1);
  free(n2);
  
  return 0;
}
