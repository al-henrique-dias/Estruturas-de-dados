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
void push(char item, Pilha *topo){

    printf("emplihando\n");

    Pilha *novo = (Pilha*)malloc(sizeof(Pilha));
    printf("ok1");

    novo->elemento = item;
    printf("ok2");
    novo->ponteiro = topo;
    printf("ok3");
    printf("\n%c\n novo\n", novo->elemento);
    printf("ok4");
    topo = novo;
    printf("ok5");

    printf("\n%c\n empilhado %p\n", topo->elemento, (void*)topo);
    printf("ok6");

}

void pop(Pilha *topo){

    printf("removendo\n");

    if(topo == NULL){
        printf("Não há nada para ser removido\n");
        return;
    }else{

        Pilha *aux = topo;
        printf("-ok1");
        topo = aux->ponteiro;
        printf("-ok2");
        printf("\n%s\n removido\n", aux->elemento);
        printf("-ok3");
        free(aux);
        printf("-ok4");
    }
}

char peek(Pilha *topo){
    printf("%p", (void*)topo);
    return topo->elemento;
}