#include <stdio.h>
#include "arvore.h"

int main(){

    Arvore* arvore = arvore_cria(
        '+',
        arvore_cria(
            '*',
            arvore_cria(
                '+',
                arvore_cria('3', arvore_criavazia(), arvore_criavazia()),
                arvore_cria('6', arvore_criavazia(), arvore_criavazia())
            ),
            arvore_cria(
                '-',
                arvore_cria('4', arvore_criavazia(), arvore_criavazia()),
                arvore_cria('1', arvore_criavazia(), arvore_criavazia())
            )
        ),
        arvore_cria('5', arvore_criavazia(), arvore_criavazia())
    );

    arvore_imprime(arvore);
    printf("\n\n");
    pre_ordem(arvore);
    printf("\n\n");
    in_ordem(arvore);
    printf("\n\n");
    pos_ordem(arvore);
    printf("\n\n");
    printf("\n"+arvore_pertence(arvore, '3') != 0 ? "três está na árvore\n" : "três não está na árvore\n");
    printf("\n"+arvore_pertence(arvore, '4') != 0 ? "quatro está na árvore\n" : "quatro não está na árvore\n");
    printf("\nfim\n");

    return 0;
}