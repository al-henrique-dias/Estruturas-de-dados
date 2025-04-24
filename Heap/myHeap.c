#include <stdio.h>
#include <limits.h>
#include "myHeap.h"

int pai(int posicao){
    if(posicao == 0)
        return 0;//se a posição for 0, o elemento da posição é pai dele mesmo
    else
        return (posicao-1)/2;
}

int esquerdo(int posicao){
    return posicao * 2 + 1;
}

int direito(int posicao){
    return posicao * 2 + 2;
}

void desce(int tamanho, int posicao, int monte[]){

    int esquerdo = esquerdo(posicao);
    int direito = direito(posicao);
    int maior;

    if(esquerdo < tamanho && monte[esquerdo] > monte[posicao])//se a posição do elemento for maior que o tamanho da árvore, ela não existe
        maior = esquerdo;
    if(esquerdo < tamanho && monte[direito] > monte[maior])//se a posição do elemento for maior que o tamanho da árvore, ela não existe
        maior = direito;
    else
        maior = tamanho;//se a posição não existe
    
    

}