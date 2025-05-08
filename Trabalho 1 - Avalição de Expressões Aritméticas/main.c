/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/
#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "pilha.h"

int main(){

    int k = 5;

    char expressao[k][50];
    for(int i = 0; i < k; i++){
        scanf("\n%s", expressao[i]);
    }

    return 0;

}