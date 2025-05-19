#include <stdio.h>
#include <string.h>
#include "arvore.h"

int main(){

///////////////////////
    if(isdigit(arvore->elemento)){
        empilhar(arvore->elemento, *expressao);
    }else{
        int valor1 = (int)desempilhar(*expressao);
        int valor2 = (int)desempilhar(*expressao);
        switch(arvore->elemento){
            case '+' :
                empilhar((char)(valor1+valor2), *expressao);
                break;
            case '-' :
                empilhar((char)(valor1-valor2), *expressao);
                break;
            case '*' :
                empilhar((char)(valor1*valor2), *expressao);
                break;
            case '/' :
                empilhar((char)(valor1/valor2), *expressao);
                break;
        }
    }
///////////////////////////
Arvore* arvore_cria(char* elemento, Arvore* esquerdo, Arvore* direito){
    Arvore* arvore = (Arvore*)malloc(sizeof(Arvore));
    arvore->elemento = malloc(strlen(elemento) + 1); // Allocate memory for the string
    strcpy(arvore->elemento, elemento); // Copy the string
    arvore->esquerdo = esquerdo;
    arvore->direito = direito;
    return arvore;
}
////////////////////////////////
    return 0;
}