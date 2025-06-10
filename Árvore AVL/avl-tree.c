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

Node * remove(int key, Node* root){

    Node *node = root;
    Node *parent = NULL;

    while(node != NULL && node->key != key){
        parent = node;
        if(key < node->key)
            node = node->left;
        else if(key > node->key)
            node = node->right;
    }

    //Key not found or tree is empty.
    if(node == NULL)
        return root;

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

        //Treats parent's 
        if(node == parent->left)
            parent->left = current;
        else
            parent->right = current;

        free(node);

    } else {
        
        Node* aux = node->right;//aux is the in-order successor

        //Finds the in-order successor
        while(aux->left != NULL) {
            current = aux;//current will be treated as the parent of aux
            aux = aux->left;
        }

        if(current != NULL)
            current->left = aux->right;
        else
            node->right = aux->right;

        node->key = aux->key;

        free(aux);

    }

    return root;

}   