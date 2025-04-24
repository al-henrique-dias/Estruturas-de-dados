#include <stdio.h>
#include <stdlib.h>
#include "arv.h"

Arv* arv_criavazia (){
    return NULL;
}

Arv* arv_cria (char elemento, Arv* esquerdo, Arv* direito){
    Arv* arvore = (Arv*)malloc(sizeof(Arv));
    arvore->elemento = elemento;
    arvore->esquerdo = esquerdo;
    arvore->direito = direito;
    return arvore;
}

Arv* arv_libera (Arv* arvore){
    if(!arv_vazia(arvore)){
        arv_libera(arvore->esquerdo);
        arv_libera(arvore->direito);
        free(arvore);
    }
    return NULL;
}

int arv_vazia (Arv* arvore){
    return arvore==NULL;
}

int arv_pertence (Arv* arvore, char elemento){
    if(arv_vazia(arvore)){
        return 0;
    } else {
        return(
            arvore->elemento==elemento ||
            arv_pertence(arvore->esquerdo, elemento) ||
            arv_pertence(arvore->direito, elemento)
        );
    }

}

void arv_imprime (Arv* arvore){
    if(!arv_vazia(arvore)){
        printf("%c", arvore->elemento);
        arv_imprime(arvore->esquerdo);
        arv_imprime(arvore->direito);
    }
}

void processa(Arv* arvore){
    printf("%c\n", arvore->elemento);
}

void pre_ordem(Arv* arvore){
    if(!arv_vazia){
        processa(arvore);
        pre_ordem(arvore->esquerdo);
        pre_ordem(arvore->direito);
    }
}

void in_ordem(Arv* arvore){
    if(!arv_vazia){
        in_ordem(arvore->esquerdo);
        processa(arvore);
        in_ordem(arvore->direito);
    }
}

void pos_ordem(Arv* arvore){
    if(!arv_vazia){
        pos_ordem(arvore->esquerdo);
        pos_ordem(arvore->direito);
        processa(arvore);
    }
}