/**************************************************
*
* Nome dos(as) estudantes: Henrique Dias Albernaz
* Trabalho 2
* Disciplina: Estrutura de Dados
* Objetivo: Cadastro de estudantes utilizando árvore AVL
* Principais referências: https://www.hello-algo.com/en/chapter_tree/avl_tree/; https://www.geeksforgeeks.org/dsa/introduction-to-avl-tree/; Programe seu futuro (YouTube); Materiais de aula;
* Repositório online: https://github.com/al-henrique-dias/Estruturas-de-dados/
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "avl-tree.h"

int main(){

    int menu = 0;

    Node *estudantes = NULL;//Árvore AVL dos estudantes

    //Buffers para estudante
    int rga;
    char nome[60];
    Data_nascimento data_nasc;
    int codigo_curso;
    int ano_ingresso;

    do{
        printf("\nO que deseja?\n");
        printf("1 - Inserir novo Estudante\n");
        printf("2 - Atualizar Estudante\n");
        printf("3 - Remover Estudante\n");
        printf("4 - Listar Estudantes\n");
        printf("0 - Sair\n");
        printf("Insira o numero de sua escolha: ");
        scanf("%d", &menu);
        switch(menu){
            case 1:
                //Inserir estudante
                printf("\nInsira os dados do novo estudante\nRGA: ");
                scanf("%d", &rga);
                printf("Nome: ");
                scanf(" %59[^\n]", nome);
                printf("Data de nascimento:\n");
                printf("Dia: ");
                scanf("%d", &data_nasc.dia);
                printf("Mes: ");
                scanf("%d", &data_nasc.mes);
                printf("Ano: ");
                scanf("%d", &data_nasc.ano);
                printf("Codigo do curso: ");
                scanf("%d", &codigo_curso);
                printf("Ano de ingresso: ");
                scanf("%d", &ano_ingresso);
                estudantes = insert_node(rga, nome, data_nasc, codigo_curso, ano_ingresso, estudantes);
                printf("\n");
                break;
            case 2:
                //Buscar estudante
                printf("\nInsira o RGA do estudante para atualizacao: ");
                scanf("%d", &rga);
                Node *estudante = search_node(rga, estudantes);
                if(search_node(rga, estudantes) != NULL){
                    printf("\nInsira os novos dados do estudante\n");
                    printf("Nome: ");
                    scanf(" %59[^\n]", nome);
                    printf("Data de nascimento:\n");
                    printf("Dia: ");
                    scanf("%d", &data_nasc.dia);
                    printf("Mes: ");
                    scanf("%d", &data_nasc.mes);
                    printf("Ano: ");
                    scanf("%d", &data_nasc.ano);
                    printf("Codigo do curso: ");
                    scanf("%d", &codigo_curso);
                    printf("Ano de ingresso: ");
                    scanf("%d", &ano_ingresso);
                    update_node(estudante, rga, nome, data_nasc, codigo_curso, ano_ingresso);
                } else
                    printf("O estudante nao foi encontrado no sistema\n");
                break;
            case 3:
                //Remover estudante
                Node *aux = estudantes;
                printf("\nInsira o RGA do estudante para remocao: ");
                scanf("%d", &rga);
                estudantes = remove_node(rga, estudantes);
                printf("\n");
                break;
            case 4:
                //Listar estudantes
                if(estudantes != NULL){
                    printf("\nLista de estudantes:\n\n");
                    //Traversal method choice
                    in_order(estudantes);
                    //pre_order(estudantes);
                    //post_order(estudantes);
                } else
                    printf("\nNenhum estudante cadastrado no sistema\n");
                break;
            case 0:
                estudantes = free_AVL(estudantes);
                printf("\nHave a nice day :)\n");
                break;
            default:
                printf("\nSua escolha nao faz sentido, digite algo que faz sentido\n");
                break;
        }
    }while(menu != 0); 

    return 0;
}