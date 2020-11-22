void insertion_sort(int vetor[], int tamanho) {
  int i;
  int j;
  int auxiliar;

  for (i = 1; i < tamanho; i++) {
    auxiliar = vetor[i];
    
    for (j = i - 1; j >= 0; j--) {
      if (vetor[j] > auxiliar) {
	vetor[j + 1] = vetor[j];
      } else {
	break;
      }
    }
    vetor[j + 1] = auxiliar;
  }
}
