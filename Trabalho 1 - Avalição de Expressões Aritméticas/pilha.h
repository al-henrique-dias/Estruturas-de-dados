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
//Adiciona um item ao topo da pilha
//@param pilha Estrutura de pilha.
void push(char item, Pilha *topo);
//Remove o item do topo da pilha
//@param pilha Estrutura de pilha.
void pop(Pilha *topo);
//Retorna 
//@param pilha Estrutura de pilha.
//@return (char) Elemento do topo da pilha.
char peek(Pilha *topo);