/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo: Avaliação de Expressões Aritméticas
*/
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"
#include "pilha.h"

int main(){

    int k = 0;
    Arvore *arvore, *subarvore[10];
    Pilha *simbolos = NULL, *numeros = NULL;

    printf("\nBem vindo! Quantas expressões avaliaremos agora?\n");
    scanf("%d", &k);
    char expressao[k][50];

    for(int i = 0; i < k; i++){
        scanf("%s", expressao[i]);
        for(int j = 0; j < sizeof(expressao[i]); j++){//percorre a expressão i
            int sub = 0;
            if(expressao[i][j] == ')'){//quando um parênteses é encontrado na expressão, o programa começa a buscar pelos símbolos e números correspondentes
                for(int k = j; k > 0; k--){
                    if(ispunct(expressao[i][k]) && (expressao[i][k] != '(') && (expressao[i][k] != ')')){
                        subarvore[sub] = arvore_cria(
                            expressao[i][k],
                            isalpha(expressao[i][k+1]) ?
                                arvore_cria(expressao[i][k+1], arvore_criavazia(), arvore_criavazia()) :
                                arvore_criavazia(),
                            isalpha(expressao[i][k-1]) ?
                                arvore_cria(expressao[i][k-1], arvore_criavazia(), arvore_criavazia()) :
                                arvore_criavazia
                        );
                        sub++;
                        // empilhar(expressao[i][k], &simbolos);
                        printf("%c\n", expressao[i][k]);
                        expressao[i][k] = 'v';//impede o reuso do simbolo encontrado
                        // if(isalpha(expressao[i][k+1])){//PARA TESTES - isto está procurando por letras, alterar para isdigit(expressao[i][k+1])
                        //     empilhar(expressao[i][k+1], &numeros);//número da esquerda
                        //     printf("%c\n", expressao[i][k+1]);
                        // }
                        // if(isalpha(expressao[i][k-1])){//PARA TESTES - isto está procurando por letras, alterar para isdigit(expressao[i][k-1])
                        //     empilhar(expressao[i][k-1], &numeros);//número da direita
                        //     printf("%c\n", expressao[i][k-1]);
                        // }
                        k = 0;
                    }
                }
            }
        }
        printf("%s\n", expressao[i]);
        while(simbolos != NULL){
            printf("%c", simbolos->elemento);
            desempilhar(&simbolos);
        }
        printf("\n");
        while(numeros != NULL){
            printf("%c", numeros->elemento);
            desempilhar(&numeros);
        }
    }

    return 0;

}