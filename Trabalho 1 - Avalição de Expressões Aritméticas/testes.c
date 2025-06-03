#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdlib.h>
#include "arvore.h"

int extrai_numero_esq(char* expressao, int posicao);
int extrai_numero_dir(char* expressao, int posicao);

int main(){
    
    char* expressao = "(2278)";
    printf("%d\n", extrai_numero_esq(expressao, 3));
    printf("%d\n", extrai_numero_dir(expressao, 1));
    printf("%d\n", extrai_numero_esq(expressao, 2));
    printf("%d\n", extrai_numero_dir(expressao, 2));

    return 0;
}

int extrai_numero_esq(char* expressao, int posicao){
    if(!isdigit(expressao[posicao - 1]))
        return expressao[posicao] - '0';
    int digito = posicao;
    while(isdigit(expressao[digito]))
        digito--;
    int tamanho = posicao - digito;
    char elemento[tamanho+1];
    for(digito; digito <= posicao; digito++)
        elemento[digito] = expressao[digito+1];
    elemento[tamanho] = '\0';
    return atoi(elemento);
}
int extrai_numero_dir(char* expressao, int posicao){
    if(!isdigit(expressao[posicao + 1]))
        return expressao[posicao] - '0';
    int digito = posicao;
    while(isdigit(expressao[digito + 1]))
        digito++;
    int tamanho = digito - posicao + 1;
    char elemento[tamanho + 1];
    for(digito = 0; digito < tamanho; digito++)
        elemento[digito] = expressao[posicao + digito];
    elemento[tamanho] = '\0';
    return atoi(elemento);
}