/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/
//Árvore binária
typedef struct arv {
    char elemento;
    struct arv* direito;
    struct arv* esquerdo;
} Arv;

//Cria uma árvore binária vazia.
//@return Árvore binária vazia.
Arv* arv_criavazia ();

//Cria uma árvore com a informação do nó raiz,
//subárvore esquerda e subárvore direita.
//@param elemento Elemento na raiz
//@param esquerdo Nó Esquerdo
//@param direito Nó Direito
//@return Árvore com raiz e subárvores definidos pelos parâmetros.
Arv* arv_cria (char elemento, Arv* esquerdo, Arv* direito);

//Libera o espaço de memória ocupado pela árvore binária.
//@param arvore Árvore binária
//@return Árvore binária vazia.
Arv* arv_libera (Arv* arvore);

//@param arvore Árvore Binária
//@return 0 - se a árvore não estiver vazia; 1 - se a árvore estiver vazia;
int arv_vazia (Arv* arvore);

//Indica a ocorrência ou não do caracter "elemento".
//@param arvore Árvore binária
//@return 0 - se o elemento não pertence à árvore; 1 - se o elemento pertence à árvore
int arv_pertence (Arv* arvore, char elemento);

//Imprime as informações dos nós da árvore.
//@param arvore Árvore binária
void arv_imprime (Arv* arvore);

void pre_ordem(Arv* arvore);
void in_ordem(Arv* arvore);
void pos_ordem(Arv* arvore);