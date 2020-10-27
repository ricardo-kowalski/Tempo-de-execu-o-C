#include <stdio.h>
#include "geral.h" 

void ordena_shellSort(int *v, int n){
    /*int i, j, gap, k;
    int x, a[5] = {9, 5, 3, 2, 1};

    for(k = 0; k < 5; k++){
        gap = a[k];
        for(i = gap; i < n; i++){
            x = v[i];
            for(j = i - gap; (x < v[j]) && (j >= 0); j = j - gap){
                v[j + gap] = v[j];
            }
            v[j + gap] = x;
        }
    }  */
		int i , j , value;
 		int x;
    int gap = 1;
    while(gap < n) {
        gap = 3*gap+1;
    }
    while ( gap > 1) {
        gap /= 3;
        for(i = gap; i < n; i++) {
            value = v[i];
            j = i;
            while (j > gap && value <= v[j - gap]) {
                v[j] = v [j - gap];
                j = j - gap;
            }
            v [j] = value;
        }
    }
}