/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo: Avaliação de Expressões Aritméticas
*/
#include <stdio.h>
#include <string.h>
#include "arvore.h"
#include "pilha.h"

int main(){

    int k = 0;
    Arvore *arvore;

    printf("\nBem vindo! Quantas expressões avaliaremos agora?\n");
    scanf("%d", &k);
    char expressao[k][50];

    for(int i = 0; i < k; i++){
        scanf("%s", expressao[i]);
        for(int j = 0; i < sizeof(expressao[i]); i++){
            if(expressao[i][j] != '(' || expressao[i][j] != ')'){
                
            }
        }
        printf("%s\n", expressao[i]);
    }

    return 0;

}