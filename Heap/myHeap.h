//@param posição de elemento heap
//@return posição do pai esquerdo do parâmetro
int pai(int posicao);
//@param posição de elemento heap
//@return posição do filho esquerdo do parâmetro
int esquerdo(int posicao);
//@param posição de elemento heap
//@return posição do filho direito do parâmetro
int direito(int posicao);
//@param tamanho de arvore heap
//@param posição de elemento heap
//@param vetor de arvore heap (primeira posição - 0)
void desce(int tamanho, int posicao, int *arvore);
//@param tamanho de arvore heap
//@param posição de elemento heap
//@param vetor de arvore heap (primeira posição - 0)
void sobe(int tamanho, int posicao, int *arvore);
//@param tamanho de arvore heap
//@param vetor de arvore heap (primeira posição - 0)
void constroi_heap(int tamanho, int *arvore);
int consulta_max();
int extrai_max();
void aumenta_prioridade();
void insere_lista();