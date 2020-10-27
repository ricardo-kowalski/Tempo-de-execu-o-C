void entr();

int menu_entr();

int menu_qnt();

unsigned long get_time();

void calcula_tempos(int *vet, int qnt_elem, int tipo_ord);

void geraVetor(int *vet, int tam);

void geraVetorCrescente(int *vet, int tam);

void geraVetorDecrescente(int *vet, int tam);

int media(int vet_tempos[]);

void ordena_bubbleSort(int *v, int n);

void ordena_quick_sort(int *a, int left, int right);

void ordena_radix_sort(int vetor[], int tam);

void ordena_radixsort_desc(int vet[], int n);

void ordena_insertionSort(int *v, int n);

void ordena_selectionSort(int *v, int n);

void ordena_shellSort(int *v, int n);

void ordena_heapSort(int *v, int n);

void ordena_mergeSort(int *v, int inicio, int fim);