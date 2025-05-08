/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 1
* Disciplina: Estrutura de Dados
* Objetivo:
*/

//Árvore binária
typedef struct arv Arv;
struct arv {
    char elemento;
    struct arv* direito;
    struct arv* esquerdo;
};

//Cria uma estrutura de árvore binária vazia
//@return Estrutura de árvore binária vazia
Arv* arv_criavazia ();

//Cria uma estrutura de árvore binária com a informação do nó raiz,
//subárvore esquerda e subárvore direita
//@param elemento Elemento (caracter) a ser adicionado na raiz da estrutura de árvore binária criada
//@param esquerdo Ponteiro para endereço de nó esquerdo da raiz da estrutura de árvore binária criada
//@param direito Ponteiro para endereço de nó esquerdo da raiz da estrutura de árvore binária criada
//@return estrutura de árvore binária com raiz e subárvores
Arv* arv_cria (char elemento, Arv* esquerdo, Arv* direito);

//Libera o espaço de memória ocupado por uma dada estrutura de árvore binária
//@param arvore Estrutura de árvore binária a ser liberada
//@return Estrutura de árvore binária vazia
Arv* arv_libera (Arv* arvore);

//Verifica se uma estrutura de árvore binária está vazia ou não
//@param arvore Estrutura de árvore binária a ser verificada
//@return Estado de estrutura de árvore: (1) - a árvore está vazia; (0) - a árvore não está vazia;
int arv_vazia (Arv* arvore);

//Indica a ocorrência ou não de um dado elemento (caracter) em uma estrutura de árvore binária
//@param arvore Estrutura de árvore binária onde se verificará a ocorrência do elemento
//@param elemento Caracter a ser verificado
//@return Ocorrência do elemento: (1) - o elemento pertence à árvore; (0) - o elemento não pertence à árvore;
int arv_pertence (Arv* arvore, char elemento);

//Imprime as informações dos nós da árvore
//@param arvore Estrutura de árvore binária para ser vizualizada
void arv_imprime (Arv* arvore);

//Executa certa operação em formato de pré-ordem (raiz, nó esquerdo, nó direito)
void pre_ordem(Arv* arvore);
//Executa certa operação em formato de em-ordem (nó esquerdo, raiz, nó direito)
void in_ordem(Arv* arvore);
//Executa certa operação em formato de pós-ordem (nó esquerdo, nó direito, raiz)
void pos_ordem(Arv* arvore);