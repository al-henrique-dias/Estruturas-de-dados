#include <stdio.h>
#include <stdlib.h>
#include "binary-search-tree.h"

Node * create_node(int item){

    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node->key = item;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;

}

Node * insert(int new_key, Node* root){

    Node *new_node = create_node(new_key);

    //if the tree is empty
    if(root == NULL)
        return new_node;

    Node *parent = NULL, *current = root;

    while(current != NULL){
        parent = current;
        if(new_key < current->key)
            current = current->left;
        else if(new_key > current->key)
            current = current->right;
        else //if the key already exists
            return NULL;
    }

    if(new_key < parent->key)
        parent->left = new_node;
    else
        parent->right = new_node;

    return new_node;

}

Node * search(int key, Node* root){

    Node *current = root;

    while(current != NULL){
        if(key < current->key)
            current = current->left;
        else if(key > current->key)
            current = current->right;
        else
            break;
    }

    return current;

}

//work in progress
void remove(int key, Node* root){

    Node *node = search(key, root);

    if(node == NULL){
        printf("Key not found or tree is empty.");
        return;
    }
    
    if(node->right == NULL){
        Node *aux = node->left;
        node = aux->left;
        free(aux);
        return;
    }

    if(node->left == NULL){
        Node *aux = node;
        node = aux->right;
        free(aux);
        return;
    }

    Node *current = node->right;
    int aux;

    while(current->left != NULL)
        current = current->left;
    aux = node->key;
    node->key = current->key;
    current->key = aux;
    

}   