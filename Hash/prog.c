#include <stdio.h>
#include "mhash.h"

int main(){

    celula turma[MAX];

    iniciar(turma);

    int menu = 1;
    int rga;
    char *nome;
 

    do{

        printf("\nO que tu quer?\n");
        printf("\n1 - Inserir aluno\n2 - Buscar aluno\n3 - Remover aluno\n0 - Sair\n\n");
        scanf("%d", &menu);

        switch (menu){
            case 1:
                
                printf("\nInsira o nome do aluno a ser inserido:\n");
                scanf("%s", nome);
                rga = inserir(nome, turma);
                if(rga != MAX){
                    printf("\nInsira a avaliacao de desempenho do aluno a ser inserido:\n");
                    scanf("%f", &turma[rga].elementoF);
                    printf("\nAluno inserido com sucesso:\n");
                    printf("\nRGA: %d\nNome: %s\nAvaliacao de desempenho:%.2f\n", turma[rga].chave, turma[rga].elemento, turma[rga].elementoF);
                }
                else
                    printf("\nO limite de alunos foi atingido. Operacao cancelada.\n");

                break;
            case 2:
            
                printf("\nInsira o nome do aluno que tu busca:\n");
                scanf("%s", nome);
                rga = buscar(nome, turma); 
                if(rga != MAX){
                    printf("\nO aluno que tu busca ta registrado:\n");
                    printf("\nRGA: %d\nNome: %s\nAvaliacao de desempenho:%.2f\n", turma[rga].chave, turma[rga].elemento, turma[rga].elementoF);
                }
                else
                    printf("\nO aluno que tu busca nao ta registrado.\n");

                break;
            case 3:
                printf("\nInsira o nome do aluno que tu deseja remover:\n");
                scanf("%s", nome);
                rga = remover(nome, turma); 
                if(rga != MAX){
                    printf("\nRemovendo:\nNome: %s\nRGA: %d\n", turma[rga].elemento, turma[rga].chave);
                    printf("\nO aluno foi removido com sucesso.\n");
                }
                else
                    printf("\nO aluno que tu busca nao ta registrado.\n");
                break;
            case 0:
                printf("\nUm bom dia pra ti.\n");
                break;
            default:
                printf("\nComando desconhecido.\n");
                break;
        }

    }while(menu != 0);

    return 0;
}