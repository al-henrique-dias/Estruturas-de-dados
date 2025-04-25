//@param posição de elemento heap
//@return posição do pai esquerdo do parâmetro
int get_pai(int posicao);
//@param posição de elemento heap
//@return posição do filho esquerdo do parâmetro
int get_esquerdo(int posicao);
//@param posição de elemento heap
//@return posição do filho direito do parâmetro
int get_direito(int posicao);
//@param posição de elemento heap
//@param vetor de arvore heap (primeira posição - 0)
//@param tamanho de arvore heap
void desce(int posicao, int *heap, int tamanho);
//@param posição de elemento heap
//@param vetor de arvore heap (primeira posição - 0)
//@param tamanho de arvore heap
void sobe(int posicao, int *heap, int tamanho);
//@param vetor de arvore heap (primeira posição - 0)
//@param tamanho de arvore heap
void constroi_heap(int *vetor, int tamanho);
//@param vetor de arvore heap (primeira posição - 0)
int consulta_max(int *heap);
//@param vetor de arvore heap (primeira posição - 0)
//@param tamanho de arvore heap
int extrai_max(int *heap, int tamanho);
void aumenta_prioridade(int prioridade, int posicao, int *heap, int tamanho);
void insere_lista(int elemento, int *heap, int *tamanho);
void heapsort(int *vetor, int tamanho);