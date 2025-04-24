#include <stdio.h>
#include "arv.h"

int main(){

    Arv* arvore = arv_cria(
        '+',
        arv_cria(
            '*',
            arv_cria(
                '+',
                arv_cria('3', arv_criavazia(), arv_criavazia()),
                arv_cria('6', arv_criavazia(), arv_criavazia())
            ),
            arv_cria(
                '-',
                arv_cria('4', arv_criavazia(), arv_criavazia()),
                arv_cria('1', arv_criavazia(), arv_criavazia())
            )
        ),
        arv_cria('5', arv_criavazia(), arv_criavazia())
    );

    arv_imprime(arvore);

    return 0;
}
