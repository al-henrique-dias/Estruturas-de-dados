/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "arvore.h"
#include "pilha.h"

Arvore* arvore_criavazia(){
    return NULL;
}

Arvore* arvore_cria(char* elemento, Arvore* esquerdo, Arvore* direito){
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    strcpy(arvore->elemento, elemento);
    arvore->esquerdo = esquerdo;
    arvore->direito = direito;
    return arvore;
}

Arvore* arvore_libera(Arvore* arvore){
    if(!arvore_vazia(arvore)){
        arvore_libera(arvore->esquerdo);
        arvore_libera(arvore->direito);
        free(arvore);
    }
    return NULL;
}

int arvore_vazia(Arvore* arvore){
    return arvore==NULL;
}

int arvore_pertence(Arvore* arvore, char* elemento){
    if(arvore_vazia(arvore)){
        return 0;
    } else {
        return(
            arvore->elemento==elemento ||
            arvore_pertence(arvore->esquerdo, elemento) ||
            arvore_pertence(arvore->direito, elemento)
        );
    }

}

void arvore_imprime(Arvore* arvore){
    if(!arvore_vazia(arvore)){
        printf("%s\n", arvore->elemento);
        arvore_imprime(arvore->esquerdo);
        arvore_imprime(arvore->direito);
    }
}

void processa(Arvore* arvore){
    printf("%s ", arvore->elemento);
}

void pre_ordem(Arvore* arvore){
    if(!arvore_vazia(arvore)){
        processa(arvore);
        pre_ordem(arvore->esquerdo);
        pre_ordem(arvore->direito);
    }
}

void in_ordem(Arvore* arvore){
    if(!arvore_vazia(arvore)){
        in_ordem(arvore->esquerdo);
        processa(arvore);
        in_ordem(arvore->direito);
    }
}

void pos_ordem(Arvore* arvore){
    if(!arvore_vazia(arvore)){
        pos_ordem(arvore->esquerdo);
        pos_ordem(arvore->direito);
        processa(arvore);
    }
}

void avaliar(Arvore* arvore, Pilha** expressao){
    if(!arvore_vazia(arvore)){
        avaliar(arvore->esquerdo, expressao);
        avaliar(arvore->direito, expressao);
        //processa(arvore);
        if(isdigit(arvore->elemento[0]))
            empilhar(atoi(arvore->elemento), expressao);
        else{
            int valor1 = desempilhar(expressao);
            int valor2 = desempilhar(expressao);
            switch(*arvore->elemento){
                case '+':
                    empilhar((valor1 + valor2), expressao);
                    break;
                case '-':
                    empilhar((valor1 - valor2), expressao);
                    break;
                case '*':
                    empilhar((valor1 * valor2), expressao);
                    break;
                case '/':
                    empilhar((valor1 / valor2), expressao);
                    break;
            }
        }
    }
}