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

    int k = 0, sub = 0;
    Arvore *subarvore[10];

    printf("\nBem vindo! Quantas expressões avaliaremos agora?\n");
    scanf("%d", &k);
    char expressao[k][50];
    Arvore *arvore[k];

    for(int i = 0; i < k; i++){
        printf("\nInsira a expressao %d:\n", i + 1);
        scanf("%s", expressao[i]);
        expressao[i][strlen(expressao[i])] = '\0';
        sub = 0;
        for(int j = 0; j < strlen(expressao[i]); j++){//percorre a expressão i
            if(expressao[i][j] == ')'){//quando um parênteses é encontrado na expressão, o programa começa a buscar pelos símbolos e números correspondentes
                for(int k = j; k > 0; k--){
                    if(ispunct(expressao[i][k]) && (expressao[i][k] != '(') && (expressao[i][k] != ')')){
                        if(j == strlen(expressao[i]) - 1){
                            arvore[i] = arvore_cria(expressao[i][k], arvore_criavazia(), arvore_criavazia());
                            arvore_imprime(arvore[i]);
                            printf("raiz da arvore %d: %c\n", i, expressao[i][k]);
                            k = 0;
                            break;
                        }
                        subarvore[sub] = arvore_cria(
                            expressao[i][k],//raiz da subárvore
                            isalpha(expressao[i][k-1]) ?//folha esquerda da subárvore
                                //PARA TESTES - isto está procurando por letras, alterar para isdigit(expressao[i][k-1])
                                arvore_cria(expressao[i][k-1], arvore_criavazia(), arvore_criavazia()) :
                                arvore_criavazia(),
                            isalpha(expressao[i][k+1]) ?//folha direita da subárvore
                                //PARA TESTES - isto está procurando por letras, alterar para isdigit(expressao[i][k+1])
                                arvore_cria(expressao[i][k+1], arvore_criavazia(), arvore_criavazia()) :
                                arvore_criavazia()
                        );
                        arvore_imprime(subarvore[sub]);
                        sub++;
                        printf("raiz da subarvore %d: %c\n", sub - 1, expressao[i][k]);
                        printf("esquerdo da subarvore %d: %c\n", sub - 1, expressao[i][k-1]);
                        printf("direito da subarvore %d: %c\n", sub - 1,  expressao[i][k+1]);
                        expressao[i][k] = 'v';//impede o reuso do simbolo encontrado nesta posição
                        k = 0;
                    }
                }
            }
        }
        printf("%s\n", expressao[i]);
    }

    return 0;

}