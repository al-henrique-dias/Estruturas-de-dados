typedef struct arvore Node;
typedef struct data_nascimento Data_nascimento;

struct arvore {
    int *rga;
    char nome[60];
    Data_nascimento data_nascimento;
    int codigo_curso;
    int ano_ingresso;
    Node* direito;//caso algo dê errado, talvez seja a terminologia, tente: struct arvore* direito;
    Node* esquerdo;
};

struct data_nascimento {
    int dia;
    int mes;
    int ano;
};

void buscar();
void visitas();
void criar();
void inserir();
void remover();
void atualizar();