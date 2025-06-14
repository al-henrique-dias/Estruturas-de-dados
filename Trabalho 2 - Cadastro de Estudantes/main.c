#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl-tree.h"

int main(){

    int menu = 0;

    Node *estudantes = NULL;

    int rga;
    char nome[60];
    Data_nascimento data_nasc;
    int codigo_curso;
    int ano_ingresso;

    do{
        printf("O que deseja?\n");
        printf("1 - Inserir novo Estudante\n");
        printf("2 - Buscar Estudante\n");//remover?
        printf("3 - Remover Estudante\n");
        printf("4 - Listar Estudante\n");//usar para debug, depois mudar para atualizar estudante
        printf("0 - Sair\n");
        printf("Insira o número de sua escolha: ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                //Inserir estudante
                printf("\nInsira os dados do novo estudante\nRGA: ");
                scanf("%d", &rga);
                printf("\nNome: ");
                scanf("%s", nome);
                printf("\nData de nascimento:");
                printf("\nDia: ");
                scanf("%d", &data_nasc.dia);
                printf("\nMes: ");
                scanf("%d", &data_nasc.mes);
                printf("\nAno: ");
                scanf("%d", &data_nasc.ano);
                printf("\nCodigo do curso: ");
                scanf("%d", &codigo_curso);
                printf("\n Ano de ingresso");
                scanf("%d", &ano_ingresso);
                insert(rga, nome, data_nasc, codigo_curso, ano_ingresso, estudantes);
                prinft("\n");
                break;
            case 2:
                //Buscar estudante
                printf("\nInsira o RGA do estudante para busca: ");
                scanf("%d", &rga);
                estudantes = search(rga, estudantes);
                printf(estudantes != NULL ? "O estudante está registrado no sistema" : "O estudante não foi encontrado no sistema");
                prinft("\n");
                break;
            case 3:
                //Remover estudante
                Node *aux = estudantes;
                printf("\nInsira o RGA do estudante para remoção: ");
                scanf("%d", &rga);
                estudantes = remove(rga, estudantes);
                prinf(aux != estudantes ? "Estudante removido com sucesso" : "O estudante não foi encontrado no sistema");
                prinft("\n");
                break;
            case 4:
                //Listar estudantes
                prinft("\n");
                break;
            case 0:
                printf("Have a nice day :)\n");
                break;
            default:
                printf("Sua escolha não faz sentido, digite algo que faça sentido\n");
                break;
        }
    }while(menu != 0); 

    return 0;
}