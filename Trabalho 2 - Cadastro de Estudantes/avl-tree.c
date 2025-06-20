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
    return node == NULL ? -1 : node->height;
}

void update_height(Node *node){
    //Node height is the height of the tallest subtree + 1
    node->height = get_height(node->left) > get_height(node->right) ? get_height(node->left) + 1 : get_height(node->right) + 1;
}

int get_balance_factor(Node *node){
    return node == NULL ? 0 : get_height(node->left) - get_height(node->right);
}

Node * rotate_left(Node *node){

    Node * child = node->right;
    Node * grandchild = child->left;

    child->left = node;
    node->right = grandchild;

    update_height(node);
    update_height(child);

    return child;

}

Node * rotate_right(Node *node){

    Node * child = node->left;
    Node * grandchild = child->right;

    child->right = node;
    node->left = grandchild;

    update_height(node);
    update_height(child);

    return child;

}

Node * rotate(Node *node){

    int balance = get_balance_factor(node);

    //Unbalanced to the left
    if(balance > 1){
        if(get_balance_factor(node->left) >= 0)
            return rotate_right(node);
        else{
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }
    }
    //Unbalanced to the right
    if(balance < -1){
        if(get_balance_factor(node->right) <= 0)
            return rotate_left(node);
        else{
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }
    }

    //Balanced
    return node;

}

Node * insert_node(int rga, char *nome, Data_nascimento data_nasc, int codigo_curso, int ano_ingresso, Node *root){

    //if the tree is empty
    if(root == NULL){
        root = create_node(rga, nome, data_nasc, codigo_curso, ano_ingresso);;
        update_height(root);
        return root;
    }        

    if(rga < root->rga){
        root->left = insert_node(rga, nome, data_nasc, codigo_curso, ano_ingresso, root->left);
    }else if(rga > root->rga){
        root->right = insert_node(rga, nome, data_nasc, codigo_curso, ano_ingresso, root->right);
    }else{
        return root;
    }

    update_height(root);
    root = rotate(root);

    return root;

}

Node * search_node(int rga, Node *root){

    Node *current = root;

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

    while(node != NULL && node->rga != rga){
        parent = node;
        if(rga < node->rga)
            node = node->left;
        else if(rga > node->rga)
            node = node->right;
    }

    //rga not found or tree is empty.
    if(node == NULL){
        printf("O estudante não foi encontrado no sistema.\n");
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

        free(aux);

    }

    update_height(root);

    root = rotate(root);

    printf("O estudante foi removido com sucesso.\n");
    return root;

}  

void processa(Node *root){
    printf("RGA: %d\nNome: %s\nData de nascimento: %d/%d/%d\nCodigo do curso: %d\nAno de ingresso: %d\n",
            root->rga, root->nome, root->data_nasc.dia, root->data_nasc.mes, root->data_nasc.ano, root->codigo_curso, root->ano_ingresso);
}

void pre_order(Node *root){
    if(root != NULL){
        processa(root);
        pre_order(root->left);
        pre_order(root->right);
    }
}

void in_order(Node *root){
    if(root != NULL){
        in_order(root->left);
        processa(root);
        in_order(root->right);
    }
}

void post_order(Node *root){
    if(root != NULL){
        post_order(root->left);
        post_order(root->right);
        processa(root);
    }
}