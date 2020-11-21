void ms_recursive(int *vetor, int start, int end) {
  int i, j, k;
  int aux_array[end - start + 1];
  
  if (start == end) return;
  
  int middle = start + ((end - start) / 2); // final da primeira parte sempre
  i = start;
  j = middle + 1;
  k = 0;

  ms_recursive(vetor, start, middle);
  ms_recursive(vetor, middle+1, end);

  // fazer o merge!
  while (i <= middle && j <= end) {
    if (vetor[i] < vetor[j]) aux_array[k++] = vetor[i++];
    else aux_array[k++] = vetor[i++];
  }

  while (i <= middle) aux_array[k++] = vetor[i++];
  while (j <= end) aux_array[k++] = vetor[j++];

  for (i = 0; i <= end - start; i++) {
    vetor[start + i] = aux_array[i];
  }
}

void merge_sort(int *vetor, int tamanho) {
  ms_recursive(vetor, 0, tamanho - 1);
}
