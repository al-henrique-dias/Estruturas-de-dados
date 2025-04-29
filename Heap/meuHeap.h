//@param posicao >posição de elemento heap
//@return posição do pai esquerdo do parâmetro
int get_pai(int posicao);
//@param posicao >posição de elemento heap
//@return posição do filho esquerdo do parâmetro
int get_esquerdo(int posicao);
//@param posicao >posição de elemento heap
//@return posição do filho direito do parâmetro
int get_direito(int posicao);
//@param posicao >posição de elemento heap
//@param vetor >vetor de árvore heap
//@param tamanho >tamanho de árvore heap.
void desce(int posicao, int *heap, int tamanho);
//@param posicao >posição de elemento heap
//@param vetor >vetor de árvore heap
//@param tamanho >tamanho de árvore heap.
void sobe(int posicao, int *heap, int tamanho);
//@param vetor >vetor de árvore heap
//@param tamanho >tamanho de árvore heap.void constroi_heap(int *vetor, int tamanho);
//@param vetor >vetor de árvore heap
//@return
int consulta_max(int *heap);
//@param vetor >vetor de árvore heap
//@param tamanho >tamanho de árvore heap.
//@return
int extrai_max(int *heap, int tamanho);
//@param prioridade >prioridade
//@param posicao >posição de elemento heap
//@param vetor >vetor de árvore heap
//@param tamanho >tamanho de árvore heap.
void aumenta_prioridade(int prioridade, int posicao, int *heap, int tamanho);
//@param elemento >elemento
//@param vetor >vetor de árvore heap
//@param tamanho >tamanho de árvore heap.
void insere_lista(int elemento, int *heap, int *tamanho);
//@param vetor >Vetor a ser ordenado.
//@param tamanho >Tamanho do vetor a ser ordenado.
void heapsort(int *vetor, int tamanho);