#include <stdio.h>
#include <stdlib.h>
#include "geral.h" 


void ordena_selectionSort(int *v, int n){
    int i, j, menor, troca;
    for(i = 0; i < n - 1; i++){
        menor = i;
        for(j = i + 1; j < n; j++){
            if(v[j] < v[menor]){    //mudando para '>' ordena em ordem decrescente
                menor = j;
            }
        }
        if(i != menor){
            troca = v[i];
            v[i] = v[menor];
            v[menor] = troca;
        }
    }
}
