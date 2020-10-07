#include <stdio.h>
#include <stdlib.h>

struct node {
  int value;
  struct node *right;
  struct node *left;
};

typedef struct node Node;

void add(int value, Node *t) {
  if (value > t->value) {
    if (t->right != NULL) {
      add(value, t->right);
    } else {
      Node *new_node = malloc(sizeof(Node));
      new_node->value = value;
      new_node->right = NULL;
      new_node->left = NULL;

      t->right = new_node;
    }
  } else {
    if (t->left != NULL) {
      add(value, t->left);
    } else {
      Node *new_node = malloc(sizeof(Node));
      new_node->value = value;
      new_node->right = NULL;
      new_node->left = NULL;

      t->left = new_node;
    }
  }
}

int main() {
  Node *n1 = malloc(sizeof(Node));
  n1->left = NULL;
  n1->right = NULL;
  n1->value = 7;

  add(8, n1);
  add(2, n1);
  add(3, n1);

  printf("%d, %d, %d, %d\n", n1->left->value, n1->left->right->value, n1->value, n1->right->value);
  
  return 0;
}
