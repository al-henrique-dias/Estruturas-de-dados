/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/
#include <stdio.h>
#include "arvore.h"
#include "pilha.h"

int main(){

    Pilha *pilha = NULL;

    desempilhar(&pilha);
    empilhar('a', &pilha);
    printf("\n%c\n", pilha->elemento);
    empilhar('b', &pilha);
    printf("\n%c\n", pilha->elemento);
    empilhar('c', &pilha);
    printf("\n%c\n", pilha->elemento);
    empilhar('d', &pilha);
    printf("\n%c\n", pilha->elemento);
    desempilhar(&pilha);
    printf("__________________\n%c\n", pilha->elemento);
    desempilhar(&pilha);
    printf("\n%c\n", pilha->elemento);
    printf("\n%c\n", pilha->ponteiro->elemento);
    desempilhar(&pilha);
    desempilhar(&pilha);
    desempilhar(&pilha);

    return 0;
}