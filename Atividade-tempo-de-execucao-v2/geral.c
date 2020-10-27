#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include <sys/time.h>
#include <time.h>
#include "geral.h"

int vetor1[1000];
int vetor5[5000];
int vetor10[10000];
int vetor20[20000];
int vetor50[50000];
int vetor100[100000];

#define ANSI_COLOR_RED "\x1b[31m"
#define ANSI_COLOR_GREEN "\x1b[32m"
#define ANSI_COLOR_YELLOW "\x1b[33m"
#define ANSI_COLOR_BLUE "\x1b[34m"
#define ANSI_COLOR_MAGENTA "\x1b[35m"
#define ANSI_COLOR_CYAN "\x1b[36m"
#define ANSI_COLOR_RESET "\x1b[0m"

//------------------- Menus ----------------------------
int menu_entr() {						//exibe menu principal
    int opc;
    printf("\nSelecione o método de ordenação desejada:\n\n");
    printf("\t1. BubbleSort\n");
    printf("\t2. InsertionSort\n");
    printf("\t3. SelectionSort\n");
    printf("\t4. ShellSort\n");
    printf("\t5. RadixSort - LSD\n");
    printf("\t6. MergeSort\n");
    printf("\t7. QuickSort\n");
    printf("\t8. HeapSort\n");
    printf("\t9. Sair\n");
    printf("\n> ");
    scanf("%d",&opc);
    if(opc == 9){
        exit(-1);
    }
    if(opc < 1 || opc > 9){
        printf("\nOpção inválida!\n");
        return menu_entr();
    }
    return opc;
}

int menu_qnt(){
    int qnt_elem;
    printf("\nSelecione a quantidade de elementos desejada:\n\n");
    printf("\t1. 1.000\n");
    printf("\t2. 5.000\n");
    printf("\t3. 10.000\n");
    printf("\t4. 20.000\n");
    printf("\t5. 50.000\n");
    printf("\t6. 100.000\n");
    printf("\n> ");
    scanf("%d", &qnt_elem);
    fflush(stdin);

    switch(qnt_elem){
        case 1: qnt_elem = 1000; break;
        case 2: qnt_elem = 5000; break;
        case 3: qnt_elem = 10000; break;
        case 4: qnt_elem = 20000; break;
        case 5: qnt_elem = 50000; break;
        case 6: qnt_elem = 100000; break;
        default: {
            printf("\nQuantidade invalida!\n");
            menu_qnt();
        }
    }   
    return qnt_elem;
}

//-------------------------------------------------------

void geraVetor(int *vet, int tam){
    int aux;
    for(aux = 0; aux < tam; aux++){
        vet[aux] = rand();
    }
}

void geraVetorCrescente(int *vet, int tam){

    int aux;
    for(aux = 0; aux < tam; aux++){
        vet[aux] = rand();
    }

    ordena_radix_sort(vet, tam);
}

void geraVetorDecrescente(int *vet, int tam){
    int aux;
    for(aux = tam - 1; aux >= 0; aux--){
        vet[aux] = rand();
    }
    ordena_radixsort_desc(vet, tam);
}
/*
unsigned long get_time() {
    
    struct timeval tv;
    gettimeofday(&tv, NULL);
    unsigned long ret = tv.tv_usec;
    //ret /= 1;
    //printf("\n%ld segundos e %ld milisegundos", tv.tv_sec/1000000, tv.tv_usec);
    ret = (tv.tv_sec * 1000000) + tv.tv_usec;        ///<<<< MUDEI ESSA PARTE - ACHO QUE É ASSIM
    return ret;
}
*/

//USANDO A FUNÇÃO CLOCK, biblioteca time.h
unsigned long get_time() {
    // Calculate the time 
    clock_t t; 
    t = clock(); 
    double time_taken = ((double)t)/(CLOCKS_PER_SEC/1000000); // in microseconds, em milisegundo é só dividir por 1000
    
    return time_taken;
}


int media(int vet_tempos[]){
    int i, sum = 0;
    for(i = 0; i < 10; i++){
        sum += vet_tempos[i];    
    }
    return sum/10;
}

void calcula_tempos(int *vet, int qnt_elem, int tipo_ord){
   
    int i, vetor_tempo[10], tempo, m;

    //-------------------- 10 arrays aleatórios ----------------------
    
    for(i = 0; i < 10; i++){
        long start_time = get_time();
        vet = (int*) malloc(qnt_elem * sizeof(int));
        geraVetor(vet, qnt_elem);  //teste com vetor gerado antes da execução do algoritmo
        
        switch(tipo_ord){
            case 1: 
                if(i == 0){
                    printf("\n\n- BUBBLE SORT -\n");
					printf("- %d elementos -\n\n", qnt_elem);
                }
                ordena_bubbleSort(vet, qnt_elem);
                break;
            case 2: 
                if(i == 0){
                    printf("\n\n- INSERTION SORT -\n\n");
					printf("- %d elementos -\n\n", qnt_elem);
                }
                ordena_insertionSort(vet, qnt_elem);
                break;
            case 3: 
                if(i == 0){
                    printf("\n\n- SELECTION SORT -\n\n");
					printf("- %d elementos -\n\n", qnt_elem);
                }
                ordena_selectionSort(vet, qnt_elem);
                break;
            case 4: 
                if(i == 0){
                    printf("\n\n- SHELL SORT -\n\n");
					printf("- %d elementos -\n\n", qnt_elem);
                }
                ordena_shellSort(vet, qnt_elem);
                break;    
            case 5: 
                if(i == 0){
                    printf("\n\n- RADIX SORT - LSD -\n\n");
					printf("- %d elementos -\n\n", qnt_elem);
                }
                ordena_radix_sort(vet, qnt_elem);
                break;
            case 6: 
                if(i == 0){
                    printf("\n\n- MERGE SORT -\n\n");
					printf("- %d elementos -\n\n", qnt_elem);
                }
                ordena_mergeSort(vet, 0, qnt_elem - 1);;
                break;
            case 7: 
                if(i == 0){
                    printf("\n\n- QUICK SORT -\n\n");
					printf("- %d elementos -\n\n", qnt_elem);
                }
                ordena_quick_sort(vet, 0, qnt_elem - 1);
                break;
            case 8:  
                if(i == 0){
                    printf("\n\n- HEAP SORT -\n\n");
					printf("- %d elementos -\n\n", qnt_elem);
                }
                ordena_heapSort(vet, qnt_elem);
                break;
            default:
                printf("\nTipo de ordenação inválida!\n");            
        }
        long end_time = get_time();
        vetor_tempo[i] = end_time - start_time;
        free(vet);     
    }
    /*   
    for(i = 0; i < 10; i++){
        printf("v[%d]: %d microssegundos\n", i+1, vetor_tempo[i] );     
    }
    */
    m = media(vetor_tempo);
    printf("Tempo Médio:\t\t\t%d microssegundos\n", m);

    //------------------ 1 array ordem crescente -------------------- 
    vet = (int*) malloc(qnt_elem * sizeof(int));
    geraVetorCrescente(vet, qnt_elem);       
    long start_timeC = get_time();

    switch(tipo_ord){
        case 1: 
            if(i == 0){
                printf("\n\n- BUBBLE SORT -\n\n");
            }
            ordena_bubbleSort(vet, qnt_elem);
            break;
        case 2: 
            if(i == 0){
                printf("\n\n- INSERTION SORT -\n\n");
            }
            ordena_insertionSort(vet, qnt_elem);
            break;
        case 3: 
            if(i == 0){
                printf("\n\n- SELECTION SORT -\n\n");
            }
            ordena_selectionSort(vet, qnt_elem);
            break;
        case 4: 
            if(i == 0){
                printf("\n\n- SHELL SORT -\n\n");
            }
            ordena_shellSort(vet, qnt_elem);
            break;    
        case 5: 
            if(i == 0){
                printf("\n\n- RADIX SORT - LSD -\n\n");
            }
            ordena_radix_sort(vet, qnt_elem);
            break;
        case 6: 
            if(i == 0){
                printf("\n\n- MERGE SORT -\n\n");
            }
            ordena_mergeSort(vet, 0, qnt_elem - 1);;
            break;
        case 7: 
            if(i == 0){
                printf("\n\n- QUICK SORT -\n\n");
            }
            ordena_quick_sort(vet, 0, qnt_elem - 1);
            break;
        case 8:  
            if(i == 0){
                printf("\n\n- HEAP SORT -\n\n");
            }
            ordena_heapSort(vet, qnt_elem);
            break;
        default:
            printf("\nTipo de ordenação inválida!\n");            
        } 
    long end_timeC = get_time();   
    tempo = end_timeC - start_timeC;        
    free(vet);      
    printf("Tempo no melhor caso:\t%d microssegundos\n", tempo );
    
    //----------------- 1 array ordem decrescente -------------------
    vet = (int*) malloc(qnt_elem * sizeof(int));
    geraVetorDecrescente(vet, qnt_elem);       
    long start_timeD = get_time();

    switch(tipo_ord){
        case 1: 
            if(i == 0){
                printf("\n\n- BUBBLE SORT -\n\n");
            }
            ordena_bubbleSort(vet, qnt_elem);
            break;
        case 2: 
            if(i == 0){
                printf("\n\n- INSERTION SORT -\n\n");
            }
            ordena_insertionSort(vet, qnt_elem);
            break;
        case 3: 
            if(i == 0){
                printf("\n\n- SELECTION SORT -\n\n");
            }
            ordena_selectionSort(vet, qnt_elem);
            break;
        case 4: 
            if(i == 0){
                printf("\n\n- SHELL SORT -\n\n");
            }
            ordena_shellSort(vet, qnt_elem);
            break;    
        case 5: 
            if(i == 0){
                printf("\n\n- RADIX SORT - LSD -\n\n");
            }
            ordena_radix_sort(vet, qnt_elem);
            break;
        case 6: 
            if(i == 0){
                printf("\n\n- MERGE SORT -\n\n");
            }
            ordena_mergeSort(vet, 0, qnt_elem - 1);;
            break;
        case 7: 
            if(i == 0){
                printf("\n\n- QUICK SORT -\n\n");
            }
            ordena_quick_sort(vet, 0, qnt_elem - 1);
            break;
        case 8:  
            if(i == 0){
                printf("\n\n- HEAP SORT -\n\n");
            }
            ordena_heapSort(vet, qnt_elem);
            break;
        default:
            printf("\nTipo de ordenação inválida!\n");            
        } 
    long end_timeD = get_time();   
    tempo = end_timeD - start_timeD;                
    free(vet); 
    printf("Tempo no pior caso:\t\t%d microssegundos\n", tempo );    
}

//------------------- TELA ABERTURA --------------------------



void entr(){  
	printf(ANSI_COLOR_GREEN "									\n\n\n\n");
    printf("                 (       )    )     (                  \n");
    printf("                 )\\ ) ( /( ( /(     )\\ )               \n");
    printf("      (   (  (  (()/( )\()))\())(  (()(     (         \n");
    printf("      )\\  )\\ )\\  (_)|(_)\((_)\\ )\\  /(_))   ))\\        \n");
    printf("     ((_)((_|(_)(_))   ((_)_((_|(_)(_))    /((_)       \n");
    printf("     \\ \\ / /| __| |   / _ \\_  /| __/ __|  (_))         \n");
    printf("      \\ V / | _|| |__| (_) / / | _|\\__ \\  / -_)        \n");
    printf("       \\_)  (___(____|\\___/__)||___|_(_/  \\___)  (     \n");
    printf("      ( /(  )\\ ))\\ )      ( /(  (    )\\ )  ( /(  )\\ )  \n");
    printf("      )\\())(()/(()/(  (   )\\()) )\\  (()/(  )\\())(()/(  \n");
    printf("     ((_)\\  /(_))(_)) )\\ ((_)((((_)( /(_))((_)\\  /(_)) \n");
    printf("       ((_)(_))(_))_ ((_) _((_)\\ _ )(_))_   ((_)(_))   \n");
    printf("      / _ \\| _ \\|   \\| __| \\| (_)_\\(_)   \\ / _ \\/ __|  \n");
    printf("     | (_) |   /| |) | _|| .` |/ _ \\ | |) | (_) \\__ \\  \n");
    printf("      \\___/|_|_\\|___/|___|_|\\_/_/ \\_\\|___/ \\___/|___/  \n");
    printf("                                              		\n\n"ANSI_COLOR_RESET);                                                      
    printf("\t\t\t\tALGORITMOS DE ORDENAÇÃO							\n\n");
    printf("\t\t\tTrabalho de Estrutura de Dados II\n\t\t\t\t\t		\n");

	printf("\n\n\n\n\n\n\n>Press Enter to continue...");
	getchar();
    system("cls");
}