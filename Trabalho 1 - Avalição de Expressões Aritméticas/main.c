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
    Pilha *galhos = NULL;
    Arvore *subarvore[20];

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
                for(int l = j; l > 0; l--){
                    if(ispunct(expressao[i][l]) && (expressao[i][l] != '(') && (expressao[i][l] != ')')){
                        printf("subarvore %d:\n", sub);
                        if(j == strlen(expressao[i]) - 1){
                            printf("arvore:\n");
                            arvore[i] = arvore_cria(
                                expressao[i][l],//raiz
                                isalpha(expressao[i][l-1]) ?//sub-árvore esquerda
                                //PARA TESTES - isto está procurando por letras, alterar para isdigit(expressao[i][k-1])
                                    arvore_cria(expressao[i][l-1], arvore_criavazia(), arvore_criavazia())
                                    :
                                    subarvore[(int)desempilhar(&galhos)],
                                isalpha(expressao[i][l+1]) ?//sub-árvore direita
                                //PARA TESTES - isto está procurando por letras, alterar para isdigit(expressao[i][k+1])
                                    arvore_cria(expressao[i][l+1], arvore_criavazia(), arvore_criavazia())
                                    :
                                    subarvore[(int)desempilhar(&galhos)]
                            );
                            arvore_imprime(arvore[i]);
                            printf("raiz da arvore %d: %c\n", i, expressao[i][l]);
                            l = 0;
                            break;
                        }
                        subarvore[sub] = arvore_cria(
                            expressao[i][l],//raiz da subárvore
                            isalpha(expressao[i][l-1]) ?//folha esquerda da subárvore
                                //PARA TESTES - isto está procurando por letras, alterar para isdigit(expressao[i][k-1])
                                arvore_cria(expressao[i][l-1], arvore_criavazia(), arvore_criavazia())
                                :
                                (expressao[i][l-1] != ')') && (expressao[i][l+1] != '(') ?
                                    subarvore[sub-1]
                                    :
                                    subarvore[sub-2],
                            isalpha(expressao[i][l+1]) ?//folha direita da subárvore
                                //PARA TESTES - isto está procurando por letras, alterar para isdigit(expressao[i][k+1])
                                arvore_cria(expressao[i][l+1], arvore_criavazia(), arvore_criavazia())
                                :
                                subarvore[sub-1]
                        );
                        if(!(isalpha(expressao[i][l-1])))
                            desempilhar(&galhos);
                        if(!(isalpha(expressao[i][l+1])))
                            desempilhar(&galhos);
                        empilhar(sub, &galhos);//empilhar posição do vetor
                        arvore_imprime(subarvore[sub]);
                        printf("raiz da subarvore %d: %c\n", sub, expressao[i][l]);
                        printf("esquerdo da subarvore %d: %c\n", sub, expressao[i][l-1]);
                        printf("direito da subarvore %d: %c\n", sub,  expressao[i][l+1]);
                        sub++;
                        expressao[i][l] = 'v';//impede o reuso do simbolo encontrado nesta posição
                        l = 0;
                    }
                }
            }
        }
        printf("%s\n", expressao[i]);
    }

    return 0;

}