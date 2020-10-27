#include <stdio.h>
#include <stdlib.h>
#include "geral.h" 

void ordena_radixsort_desc(int vet[], int n) {

    int i, m=0, exp=1;
    int *b;
    b = (int *)calloc(n, sizeof(int));

    for (i=0; i<n; i++)
        if (vet[i]>m)
            m=vet[i];
    while (m/exp>0)
    {
        int bucket[10]={0};
        for (i=0; i<n; i++)
            bucket[9-vet[i]/exp%10]++;        
        for (i=1; i<10; i++)
            bucket[i]+=bucket[i-1];
        for (i=n-1; i>=0; i--)
            b[--bucket[9-vet[i]/exp%10]]=vet[i]; 
        for (i=0; i<n;i++){
            vet[i]=b[i];                     
        }
        exp*=10;
    }
    free(b);
}