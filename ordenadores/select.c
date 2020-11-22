void select_sort(int vetor[], int tamanho) {
  int i;
  int j;
  int auxiliar;
  int index_menor;

  for (i = 0; i < tamanho - 1; i++) {
    index_menor = i;

    for (j = index_menor + 1; j < tamanho; j++) {
      if (vetor[j] < vetor[index_menor]) {
	index_menor = j;
      }
    }

    auxiliar = vetor[i];
    vetor[i] = vetor[index_menor];
    vetor[index_menor] = auxiliar;
  }
}
