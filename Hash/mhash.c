#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mhash.h"

void iniciar(celula *tabela){
    for(int i = 0; i<MAX; i++){
        tabela[i].estado = VAZIA;
    }
}

int espalhar(char *elemento, int tentativa){
    int elementoInt = 0;
    for(int i = 0; i < strlen(elemento); i++){
        elementoInt += (int)elemento[i];
    }
    return (elementoInt+tentativa) % MAX;//a tentativa inicia com com 0, não influenciando na chave do elemento,
                                        //porém se houver colisão com outra chave, a tentativa modificará o elemento para verificar a próxima posição
}

int inserir(char *elemento, celula *tabela){//inserção na tabela hash com endereçamento aberto

    int chave, tentativa = 0;

    do{//Repetição enquanto as tentativas nõ excedem o limite da tabela
        chave = espalhar(elemento, tentativa);
        if(tabela[chave].estado != OCUPADA) {//se a posição estiver livre, o elemento será alocado na posição, o estado da posição será restringido e o return encerrará a inserção
            tabela[chave].chave = chave;
            strcpy(tabela[chave].elemento, elemento);
            tabela[chave].estado = OCUPADA;
            return chave;//se o retorno for diferente de MAX, houve inserção
        }
        tentativa++;//se a posição não estiver livre, a tentativa modificará o elemento para verificar a próxima posição
    }while(tentativa != MAX);//o limite das tentativas de inserção é o tamanho da tabela
    //se não houver posições livres, não haverá inserção
    return MAX;//se o retorno for MAX, não houve inserção

}

int buscar(char *elemento, celula *tabela){//busca na tabela hash com endereçamento aberto
    
    int chave, tentativa = 0;

    do{//Repetição enquanto o estado das posições estiver ocupado e as tentativas não excedem o limite da tabela
        chave = espalhar(elemento, tentativa);//a busca inicia pela chave do elemento, caso não esteja na posição da chave a busca continuará nas chaves dos tratamentos de uma possível colisão
        if(strcmp(tabela[chave].elemento, elemento) == 0 && tabela[chave].estado == OCUPADA) {//se o elemento buscado for igual ao elemento da posição e o estado da posição seja "OCUPADA",
                                                                                //o return encerrará a busca
            return chave;//se o retorno for diferente de MAX, o elemento foi encontrado e este retorno será a chave do elemento encontrado
        }
        tentativa++;//se as condições não forem atendidas, a tentativa modificará o elemento para verificar a próxima posição
    }while(tabela[chave].estado != VAZIA && tentativa != MAX);

    //se todos as posições forem percorridas e o elemento não for encontrado, a busca se encerra
    return MAX;//se o retorno for MAX, o elemento não foi encontrado

}

int remover(char *elemento, celula *tabela){//busca e remoção na tabela hash com endereçamento aberto
    int chave, tentativa = 0;

    do{//Repetição enquanto o estado das posições estiver ocupado e as tentativas não excedem o limite da tabela
        chave = espalhar(elemento, tentativa);//a busca inicia pela chave do elemento, caso não esteja na posição da chave a busca continuará nas chaves dos tratamentos de uma possível colisão
        if(tabela[chave].estado == OCUPADA) {//se o estado da posição for "OCUPADA"
            if(strcmp(tabela[chave].elemento, elemento) == 0){//se o elemento buscado for igual ao elemento da posição, o estado da posição se tornará "REMOVIDA" e o return encerrará a remoção
                tabela[chave].estado = REMOVIDA;//mudar
                return chave;//se o retorno for diferente de MAX, o elemento foi encontrado e este retorno será a chave do elemento encontrado                
            }
        }
        if(tabela[chave].estado == VAZIA)
            return MAX;
        tentativa++;//se as condições não forem atendidas, a tentativa modificará o elemento para verificar a próxima posição
    }while(tentativa != MAX);

    //se todos as posições forem percorridas e o elemento não for encontrado, a busca se encerra
    return MAX;//se o retorno for MAX, o elemento não foi encontrado

}