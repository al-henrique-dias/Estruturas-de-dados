#include <stdio.h>
#include <string.h>
#include "arvore.h"

int main(){

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

    return 0;
}