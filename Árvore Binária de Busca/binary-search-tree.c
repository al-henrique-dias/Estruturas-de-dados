#include <stdio.h>
#include <stdlib.h>
#include "binary-search-tree.h"

Node* new_node(int item){

    Node *new = (Node*)malloc(sizeof(Node));

    new->key = item;
    new->left = NULL;
    new->right = NULL;

    return new;

}

Node* insert(int new_key, Node* root){

    Node *new = new_node(new_key);

    //if the tree is empty
    if(root == NULL)
        return new;

    Node *parent = NULL, *current = root;

    while(current != NULL){
        parent = current;
        if(new_key < current->key)
            current = current->left;
        else if(new_key > current->key)
            current = current->right;
        //if the key already exists
        else
            return NULL;
    }

    if(new_key < parent->key)
        parent->left = new;
    else
        parent->right = new;

    return new;

}

void search(){

}

void remove(){

}