#include <stdio.h>
#include <stdlib.h>

struct node {
  struct node *anterior;
  struct node *proximo;
  int value;
};

typedef struct node Node;

int main() {
  Node *n1 = malloc(sizeof(Node));
  n1->value = 1;

  Node *n2 = malloc(sizeof(Node));
  n2->value = 4;

  n1->proximo = n2;
  n2->anterior = n1;

  printf("%d, %d\n", n1->value, n1->proximo->value);

  free(n1);
  free(n2);
  
  return 0;
}
