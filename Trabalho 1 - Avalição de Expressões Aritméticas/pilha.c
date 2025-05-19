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

    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));//aloca um espaço na memória para o novo item

    novo->elemento = item;//o novo item recebe seu valor
    novo->ponteiro = *topo;//o ponteiro do item aponta para o topo da pilha
    *topo = novo;//o topo da pilha passa a apontar para o endereço do novo item

}

char desempilhar(Pilha **topo){

    if(*topo == NULL){//verifica se a pilha está vazia, se estiver, a função é encerrada
        printf("\nA pilha está vazia, não há nada para ser removido.\n");
        return '\0';
    }

    Pilha *aux = *topo;//um ponteiro auxiliar é criado, apontando para o mesmo endereço do topo da pilha
    char elemento = aux->elemento;

    *topo = aux->ponteiro;//o topo da pilha passa a apontar para o endereço de seu ponteiro (o mesmo do ponteiro auxiliar)
    free(aux);//o espaço na memória indicado pelo ponteiro auxiliar (o item do topo da pilha) é liberado

    return elemento;

}