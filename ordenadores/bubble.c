void bubble_sort(int vetor[], int tamanho) {
  int i;
  int j;
  int auxiliar;

  for (i = 0; i < tamanho - 1; i++) {
    for (j = 0; j < tamanho - i - 1; j++) {
      if (vetor[j] > vetor[j + 1]) {
	auxiliar = vetor[j];
	vetor[j] = vetor[j + 1];
	vetor[j + 1] = auxiliar;
      }
    }
  }
}
