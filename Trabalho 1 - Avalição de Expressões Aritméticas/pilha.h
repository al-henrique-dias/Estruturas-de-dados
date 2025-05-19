/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/

//Estrutura de pilha por lista encadeada
typedef struct pilha Pilha;
struct pilha{
    char elemento;
    Pilha *ponteiro;
};

//Adiciona um item ao topo de uma estrutura de pilha
//@param item Item a ser adicionado ao topo de uma estrutura de Pilha
//@param topo Endereço do topo de uma estrutura de pilha
void empilhar(char item, Pilha **topo);

//Retorna o elemento do topo de uma estrutura de pilha e o remove
//@param topo Endereço do topo de uma estrutura de pilha a ser removido
//@return Elemento do topo de uma estrutura de pilha
char desempilhar(Pilha **topo);