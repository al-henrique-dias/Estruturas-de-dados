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
    Pilha* galhos = NULL, * resultado = NULL;
    Arvore* subarvore[20], * arvore = arvore_criavazia();

    printf("\nBem vindo! Quantas expressoes avaliaremos agora?\n");
    scanf("%d", &k);
    char expressao[k][50];

    for(int i = 0; i < k; i++){

        printf("\nInsira a expressao %d:\n", i + 1);
        scanf("%s", expressao[i]);
        expressao[i][strlen(expressao[i])] = '\0';
        printf("\nExpressao: %s\n", expressao[i]);

        sub = 0;

        for(int j = 0; j < strlen(expressao[i]); j++){//percorre a expressão i

            if(expressao[i][j] == ')'){//quando um parênteses é encontrado na expressão, o programa começa a buscar pelos símbolos e números correspondentes
                for(int l = j; l > 0; l--){

                    if(ispunct(expressao[i][l]) && (expressao[i][l] != '(') && (expressao[i][l] != ')')){
                        if(j == strlen(expressao[i]) - 1){

                            arvore = arvore_cria(
                                expressao[i][l],//raiz
                                isdigit(expressao[i][l-1]) ?//sub-árvore esquerda
                                    arvore_cria(expressao[i][l-1], arvore_criavazia(), arvore_criavazia())
                                    :
                                    subarvore[desempilhar(&galhos)],
                                isdigit(expressao[i][l+1]) ?//sub-árvore direita
                                    arvore_cria(expressao[i][l+1], arvore_criavazia(), arvore_criavazia())
                                    :
                                    subarvore[desempilhar(&galhos)]
                            );
                            
                            l = 0;
                            break;

                        }

                        subarvore[sub] = arvore_cria(
                            expressao[i][l],//raiz da subárvore
                            isdigit(expressao[i][l-1]) ?//folha esquerda da subárvore
                                arvore_cria(expressao[i][l-1], arvore_criavazia(), arvore_criavazia())
                                :
                                (expressao[i][l-1] != ')') && (expressao[i][l+1] != '(') ?
                                    subarvore[sub-1]
                                    :
                                    subarvore[sub-2],
                            isdigit(expressao[i][l+1]) ?//folha direita da subárvore
                                arvore_cria(expressao[i][l+1], arvore_criavazia(), arvore_criavazia())
                                :
                                subarvore[sub-1]
                        );
                        if(!(isdigit(expressao[i][l-1])))
                            desempilhar(&galhos);
                        if(!(isdigit(expressao[i][l+1])))
                            desempilhar(&galhos);
                        empilhar(sub, &galhos);//empilhar posição do vetor

                        sub++;
                        expressao[i][l] = 'v';//impede o reuso do simbolo encontrado nesta posição
                        l = 0;

                    }
                    
                }
            }

        }
        printf("Arvore (pre-ordem): ");
        pre_ordem(arvore);
        printf("\nArvore (in-ordem): ");
        in_ordem(arvore);
        printf("\nArvore (pos-ordem): ");
        pos_ordem(arvore);
        avaliar(arvore, &resultado);
        printf("\nResultado: %d\n", resultado->elemento);
    }
    arvore = arvore_libera(arvore);

    return 0;

}