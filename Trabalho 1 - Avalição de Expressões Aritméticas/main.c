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
#include <stdlib.h>
#include "arvore.h"
#include "pilha.h"

void extrai_numero_esq(char* expressao, int posicao, char* numero) {
    int digito = posicao;
    while (digito > 0 && isdigit(expressao[digito - 1]))
        digito--;
    int tamanho = posicao - digito + 1;
    strncpy(numero, &expressao[digito], tamanho);
    numero[tamanho] = '\0';
}

void extrai_numero_dir(char* expressao, int posicao, char* numero) {
    int digito = posicao;
    while (isdigit(expressao[digito + 1]))
        digito++;
    int tamanho = digito - posicao + 1;
    strncpy(numero, &expressao[posicao], tamanho);
    numero[tamanho] = '\0';
}

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
        printf("\nExpressao: %s\n", expressao[i]);

        sub = 0;

        for(int j = 0; j < strlen(expressao[i]); j++){//percorre a expressão i

            if(expressao[i][j] == ')'){//quando um parênteses é encontrado na expressão, o programa começa a buscar pelos símbolos e números correspondentes
                for(int l = j; l > 0; l--){

                    if(ispunct(expressao[i][l]) && (expressao[i][l] != '(') && (expressao[i][l] != ')')){
                        
                        char numero_esq[10] = "\0", numero_dir[10] = "\0";
                        if(isdigit(expressao[i][l-1]))
                            extrai_numero_esq(expressao[i], l-1, numero_esq);
                        if(isdigit(expressao[i][l+1]))
                            extrai_numero_dir(expressao[i], l+1, numero_dir);

                        if(j == strlen(expressao[i]) - 1){

                            arvore = arvore_cria(
                                (char[]){expressao[i][l], '\0'},//raiz
                                isdigit(expressao[i][l-1]) ?//sub-árvore esquerda
                                    arvore_cria(numero_esq, arvore_criavazia(), arvore_criavazia())
                                    :
                                    subarvore[desempilhar(&galhos)],
                                isdigit(expressao[i][l+1]) ?//sub-árvore direita
                                    arvore_cria(numero_dir, arvore_criavazia(), arvore_criavazia())
                                    :
                                    subarvore[desempilhar(&galhos)]
                            );
                            
                            l = 0;
                            break;

                        }

                        subarvore[sub] = arvore_cria(
                            (char[]){expressao[i][l], '\0'},//raiz da subárvore
                            isdigit(expressao[i][l-1]) ?//folha esquerda da subárvore
                                arvore_cria(numero_esq, arvore_criavazia(), arvore_criavazia())
                                :
                                (expressao[i][l-1] != ')') && (expressao[i][l+1] != '(') ?
                                    subarvore[sub-1]
                                    :
                                    subarvore[sub-2],
                            isdigit(expressao[i][l+1]) ?//folha direita da subárvore
                                arvore_cria(numero_dir, arvore_criavazia(), arvore_criavazia())
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