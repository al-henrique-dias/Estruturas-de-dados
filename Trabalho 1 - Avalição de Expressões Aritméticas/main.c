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

    Pilha *pilha;
    pilha->ponteiro = NULL;
    pilha->elemento = ' ';

    printf("\n%c\n%p\n", pilha->elemento, pilha->ponteiro);

    pop(pilha);
    push('a', pilha);
    printf("%c\n", peek(pilha));
    push('b', pilha);
    printf("%c\n", peek(pilha));
    push('c', pilha);
    push('d', pilha);
    printf("%c\n", peek(pilha));
    pop(pilha);
    printf("%c\n", peek(pilha));

    return 0;
}