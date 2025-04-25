#include <stdio.h>
#include <limits.h>
#include "meuHeap.h"

int get_pai(int posicao){
    if(posicao == 0)
        return 0;//se a posição for 0, o elemento da posição é pai dele mesmo
    else
        return (posicao-1)/2;
}

int get_esquerdo(int posicao){
    return posicao * 2 + 1;
}

int get_direito(int posicao){
    return posicao * 2 + 2;
}

void troca(int *x, int *y){

    int *aux = x;
    x = y;
    y = aux;

}

void desce(int posicao, int *heap, int tamanho){

    int maior = heap[posicao];
    int esquerdo = get_esquerdo(posicao);
    int direito = get_direito(posicao);

    if(esquerdo < tamanho && heap[esquerdo] > heap[maior])
        maior = esquerdo;
    if(direito < tamanho && heap[esquerdo] > heap[maior])
        maior = direito;
    if(maior != heap[posicao]){
        troca(&heap[posicao], &heap[maior]);
        desce(maior, heap, tamanho);
    }

}

void sobe(int posicao, int *heap, int tamanho){
    
    int pai = get_pai(posicao);

    while(heap[pai] < heap[posicao]){
        troca(&heap[pai], &heap[posicao]);
        posicao = pai;
    }

}

void constroi_heap(int *vetor, int tamanho){
    for(int i = tamanho/2 - 1; i >= 0; i--){
        desce(i, vetor, tamanho);
    }
}

int consulta_max(int *heap){
    return heap[0];
}

int extrai_max(int *heap, int tamanho){

    int maior;

    if(tamanho > 0){
        maior = heap[0];
        heap[0] = heap[tamanho - 1];
        tamanho = tamanho - 1;
        desce(0, heap, tamanho);
        return maior;
    }

    return INT_MIN;

}

void aumenta_prioridade(int elemento, int posicao, int *heap, int tamanho){
    if(elemento < heap[posicao])
        printf("Erro");
    else{
        heap[posicao] = elemento;
        sobe(posicao, heap, tamanho);
    }
}

void insere_lista(int elemento, int *heap, int *tamanho){

    heap[*tamanho] = elemento;
    *tamanho += 1;
    sobe(*tamanho - 1, heap, *tamanho);

}

void heapsort(int *vetor, int tamanho){

    constroi_heap(vetor, tamanho);
    for(int i = tamanho - 1; i > 0; i--){
        troca(&vetor[0], &vetor[i]);
        tamanho--;
        desce(i, vetor, tamanho);
    }

}