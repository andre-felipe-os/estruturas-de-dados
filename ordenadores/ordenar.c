//#include "ordenadores.h"
#include "insertion.c"
#include <stdio.h>

int main() {
  int quantidade, i;

  scanf("%d", &quantidade);
  quantidade = quantidade % 20;

  int valores[quantidade];

  for (i = 0; i < quantidade; i++) {
    scanf("%d", &valores[i]);
  }

  insertion_sort(valores, quantidade);

  for (i = 0; i < quantidade; i++) {
    printf("%d\n", valores[i]);
  }
  
  return 0;
}
