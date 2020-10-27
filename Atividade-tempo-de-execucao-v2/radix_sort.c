#include <stdio.h>
#include <stdlib.h>
#include "geral.h" 

void ordena_radix_sort(int vetor[], int tam) {

    int i;
    int *b;
    int maior = vetor[0];
    int exp = 1;

    b = (int *)calloc(tam, sizeof(int));

    for (i = 0; i < tam; i++) {
        if (vetor[i] > maior)
    	    maior = vetor[i];
    }

    while (maior/exp > 0) {

        int bucket[10] = { 0 };
    	
        for (i = 0; i < tam; i++)
    	    bucket[(vetor[i] / exp) % 10]++;
    	
        for (i = 1; i < 10; i++)
    	    bucket[i] += bucket[i - 1];
    	
        for (i = tam - 1; i >= 0; i--)
    	    b[--bucket[(vetor[i] / exp) % 10]] = vetor[i];
    	
        for (i = 0; i < tam; i++)
    	    vetor[i] = b[i];
    	exp *= 10;
    }

    free(b);
}
