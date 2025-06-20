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

Node * create_node(int rga, char *nome, Data_nascimento data_nasc, int codigo_curso, int ano_ingresso){

    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node->rga = rga;
    strcpy(new_node->nome, nome);
    new_node->data_nasc = data_nasc;
    new_node->codigo_curso = codigo_curso;
    new_node->ano_ingresso = ano_ingresso;

    new_node->height = 0;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;

}

int get_height(Node *node){
    //If the node is NULL (as for an empty tree), the height is -1
    return node == NULL ? -1 : node->height;
}

void update_height(Node *node){
    //Node height is the height of the subtree with greater height + 1
    node->height = get_height(node->left) > get_height(node->right) ? get_height(node->left) + 1 : get_height(node->right) + 1;
}

int get_balance_factor(Node *node){
    //Balance factor is the difference between the height of the left subtree and the right subtree
    //Balanced trees have a balance factor of -1, 0 or 1
    //If the balance factor is greater than 1, it's a left-leaning tree
    //If the balance factor is lesser than -1, it's a right-leaning tree
    return node == NULL ? 0 : get_height(node->left) - get_height(node->right);
}

Node * rotate_left(Node *node){

    Node * child = node->right;//The right child of the node
    Node * grandchild = child->left;//The left child of the child

    //The node is rotated to become the left child of its own child
    child->left = node;
    //The grandchild (if any) maintains its position by becoming the right child of the node
    node->right = grandchild;

    //Update the heights of the node and the child
    update_height(node);
    update_height(child);

    //Returns a pointer to the child of the rotated node (now as it's new parent)
    return child;

}

Node * rotate_right(Node *node){

    Node * child = node->left;//The left child of the node
    Node * grandchild = child->right;//The right child of the child

    //The node is rotated to become the right child of its own child
    child->right = node;
    //The grandchild (if any) maintains its position by becoming the right child of the node
    node->left = grandchild;

    //Update the heights of the node and the child
    update_height(node);
    update_height(child);

    //Returns a pointer to the child of the rotated node (now as it's new parent)
    return child;

}

Node * rotate(Node *node){

    int balance = get_balance_factor(node);

    //Node's subtree leaning (unbalanced) to the left
    if(balance > 1){
        if(get_balance_factor(node->left) >= 0)
            return rotate_right(node);//Right rotation
        else{//If the node has a grandchild to the right it's child (child balance factor < 0), we first perform a left rotation to the child
            node->left = rotate_left(node->left);
            return rotate_right(node);//Left-right rotation
        }
    }
    //Node's subtree leaning (unbalanced) to the right
    if(balance < -1){
        if(get_balance_factor(node->right) <= 0)
            return rotate_left(node);//Left rotation
        else{//If the node has a grandchild to the left it's child (child balance factor > 0), we first perform a right rotation to the child
            node->right = rotate_right(node->right);
            return rotate_left(node);//Right-left rotation
        }
    }

    //The tree is already balanced
    return node;

}

Node * insert_node(int rga, char *nome, Data_nascimento data_nasc, int codigo_curso, int ano_ingresso, Node *root){

    //Note: I first tried to perform this function iteratively, but I couldn't get it :(

    //The node is empty, the insertion is performed
    if(root == NULL){
        root = create_node(rga, nome, data_nasc, codigo_curso, ano_ingresso);
        //Returns a pointer to the new node for balancing
        return root;
    }        

    //Recursive binary search for position to insert the new node
    if(rga < root->rga){
        root->left = insert_node(rga, nome, data_nasc, codigo_curso, ano_ingresso, root->left);
    }else if(rga > root->rga){
        root->right = insert_node(rga, nome, data_nasc, codigo_curso, ano_ingresso, root->right);
    }else{//The key already exists, the insertion is stopped
        return root;
    }

    //For every function call, we update the height of the node and perform a rotation (if necessary)
    update_height(root);
    root = rotate(root);

    //Returns a pointer to the new root of the tree
    return root;

}

Node * search_node(int rga, Node *root){

    Node *current = root;

    //Iterative binary search
    while(current != NULL){
        if(rga < current->rga)
            current = current->left;
        else if(rga > current->rga)
            current = current->right;
        else
            break;
    }

    return current;

}

Node * remove_node(int rga, Node *root){

    Node *node = root;
    Node *parent = NULL;

    //Iterative binary search storing the parent node
    while(node != NULL && node->rga != rga){
        parent = node;
        if(rga < node->rga)
            node = node->left;
        else if(rga > node->rga)
            node = node->right;
    }

    //rga not found or tree is empty.
    if(node == NULL){
        printf("O estudante nao foi encontrado no sistema.\n");
        return root;
    }

    Node* current = NULL;

    if(node->left == NULL || node->right == NULL) {

        //Checks wich child the node has
        if(node->right == NULL)
            current = node->left;
        else
            current = node->right;

        //If the node is the root
        if(parent == NULL){
            free(node);
            return current;
        }

        //The parent needs to point to something
        //So we point to current, which can be a node or NULL
        if(node == parent->left)
            parent->left = current;
        else
            parent->right = current;

        free(node);

    } else {
        
        Node* aux = node->right;//aux is the in-order successor (the smallest node in the right subtree)

        //Finds the in-order successor
        while(aux->left != NULL) {
            current = aux;
            aux = aux->left;
        }

        //The parent needs to point to something
        //So we point to the right child of aux, because it can be a node or NULL (great!)
        if(current != NULL)
        //if current isn't NULL, then it is aux's parent
            current->left = aux->right;
        else
        //if current is NULL, then the very node is aux's parent
            node->right = aux->right;

        node->rga = aux->rga;
        strcpy(node->nome, aux->nome);
        node->data_nasc = aux->data_nasc;
        node->codigo_curso = aux->codigo_curso;
        node->ano_ingresso = aux->ano_ingresso;

        free(aux);

    }

    //Update the height of the root and perform a rotation (if necessary)
    update_height(root);
    root = rotate(root);

    printf("O estudante foi removido com sucesso.\n");
    //Returns a pointer to the new root of the tree
    return root;

} 

void update_node(Node *node, int rga, char *nome, Data_nascimento data_nasc, int codigo_curso, int ano_ingresso){

    Node *current = search_node(rga, node);//Gets the node to be updated. If the node is not found, current will be NULL

    if(current != NULL){
        //Updates the node's data
        strcpy(current->nome, nome);
        current->data_nasc = data_nasc;
        current->codigo_curso = codigo_curso;
        current->ano_ingresso = ano_ingresso;
        printf("O estudante foi atualizado com sucesso.\n");
    }

}

Node * free_AVL(Node *root){
    //Post-order traversal to free all of the tree
    if(root != NULL){
        free_AVL(root->left);
        free_AVL(root->right);
        free(root);
    }
    return NULL;
}

void process(Node *root){
    printf("\nRGA: %d\nNome: %s\nData de nascimento: %d/%d/%d\nCodigo do curso: %d\nAno de ingresso: %d\n",
            root->rga, root->nome, root->data_nasc.dia, root->data_nasc.mes, root->data_nasc.ano, root->codigo_curso, root->ano_ingresso);
}

void pre_order(Node *root){
    if(root != NULL){
        process(root);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(Node *root){
    if(root != NULL){
        in_order(root->left);
        process(root);
        in_order(root->right);
    }
}

void post_order(Node *root){
    if(root != NULL){
        post_order(root->left);
        post_order(root->right);
        process(root);
    }
}