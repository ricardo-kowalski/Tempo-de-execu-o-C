/****************************************************************************
*    																		*
*	Curso:		ANÁLISE E DESENVOLVIMENTO DE SISTEMAS - IFSP				*
*	Matéria:	Estrutura de Dados 2										*
*	Professor:	Antonio Tartaglia											*
*	Projeto:	ALGORITMOS DE ORDENAÇÃO - 08/05/2019						*		*
*																			*
*	Aluno:		Ricardo		GU3001687										*
*																			*
****************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
#include "geral.h"

int main(){
    setlocale(LC_ALL,"Portuguese");
    int* vet;
    int tipo_ord, qnt_elem, i;

    entr();

    do{
        tipo_ord = menu_entr();     //menu inicial - escolha do algoritmo desejado

        qnt_elem = menu_qnt();      //submenu - escolha da quantidade de elementos 
        
        calcula_tempos(vet, qnt_elem, tipo_ord);    //função de execução

    }while(tipo_ord != 9);

    return 0;
}















