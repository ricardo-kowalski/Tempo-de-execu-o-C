#include <stdio.h>
#include <stdlib.h>
#include "geral.h" 



void merge(int *v, int inicio, int meio, int fim){
    int *temp, p1, p2, tamanho, i, j, k;
    int fim1 = 0, fim2 = 0;
    tamanho = fim - inicio +1;
    p1 = inicio;
    p2 = meio + 1;
    temp = (int*) malloc(tamanho * sizeof(int));

    if(temp != NULL){
        for(i = 0; i < tamanho; i++){
            if(!fim1 && !fim2){
                if(v[p1] < v[p2]){
                    temp[i] = v[p1];
                    p1++;
                }
                else{
                    temp[i] = v[p2];
                    p2++;
                }
                if(p1 >meio){
                    fim1 = 1;
                }
                if(p2 > fim){
                    fim2 = 1;
                }
            }
            else{
                if(!fim1){
                    temp[i] = v[p1++];
                }
                else{
                    temp[i] = v[p2++];
                }
            }    
        }
        for(j=0, k = inicio; j<tamanho; j++, k++){
            v[k] = temp[j];
        }
    }
    free(temp);
}

void ordena_mergeSort(int *v, int inicio, int fim){
    int meio;
    if(inicio < fim){
        meio = (inicio + fim)/2;
        ordena_mergeSort(v, inicio, meio);
        ordena_mergeSort(v, meio + 1, fim);
        merge(v, inicio, meio, fim);
    }
}