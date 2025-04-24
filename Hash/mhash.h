#define MAX 53
#define OCUPADA 'O'
#define VAZIA 'V'
#define REMOVIDA 'R'

typedef struct celula {
    int chave;
    char elemento[MAX];
    float elementoF;
    char estado;
} celula;

void iniciar(celula *tabela);
int espalhar(char *elemento, int tentativa);
int inserir(char *elemento, celula *tabela);
int buscar(char *elemento, celula *tabela);
int remover(char *elemento, celula *tabela);