#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/

void empilhar(char item, Pilha **topo){

    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));

    novo->elemento = item;
    novo->ponteiro = *topo;
    *topo = novo;

}

void desempilhar(Pilha **topo){

    if(*topo == NULL){
        printf("\nA pilha está vazia, não há nada para ser removido.\n");
        return;
    }

    Pilha *aux = *topo;

    *topo = aux->ponteiro;
    free(aux);

}