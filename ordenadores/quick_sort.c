int qs_aux(int vetor[], int start, int end) {
  int auxiliar;
  int i = start;
  int j = end;
  int pivo = start + ((end - start) / 2);

  while (i < j) {
    // tambem param se i ou j chegar em pivo
    while (vetor[i] < vetor[pivo]) i++;
    while (vetor[j] > vetor[pivo]) j--;
    // 3 opcoes
    // j = i = pivo -> parar, pois esta no local certo
    // j = pivo ou i = pivo -> complicadinho, fazer o bagulho certo
    // j != pivo e i != pivo -> faz troca e continua (aqui?)
    if (i == pivo) {
      pivo = j;
    } else if (j == pivo) {
      pivo = i;
    }
    
    auxiliar = vetor[i];
    vetor[i] = vetor[j];
    vetor[j] = auxiliar;
  }
  return pivo;
}

void qs_recursive(int vetor[], int start, int end) {
  if (start >= end) {
    return;
  }
  int pp = qs_aux(vetor, start, end);
  printf("pivo ordenado: %d | valor: %d\n", pp, vetor[pp]);
  qs_recursive(vetor, start, pp-1);
  qs_recursive(vetor, pp+1, end);
}

/* funciona se não houver números repetidos */
void quicksort(int *vetor, int tamanho) {
  qs_recursive(vetor, 0, (tamanho - 1)); 
}
