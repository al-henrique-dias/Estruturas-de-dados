#include <stdio.h>
#include <stdlib.h>
#include "avl-tree.h"

Node * create_node(int item){

    Node *new_node = (Node*)malloc(sizeof(Node));

    new_node->key = item;
    new_node->height = 0;
    new_node->left = NULL;
    new_node->right = NULL;

    return new_node;

}

int get_height(Node* node){
    return node == NULL ? -1 : node->height;
}

void updateHeight(Node *node){
    //Node height is the height of the tallest subtree + 1
    node->height = get_height(node->left) > get_height(node->right) ? get_height(node->left) + 1 : get_height(node->right) + 1;
}

int balance_factor(Node *node){
    return node == NULL ? 0 : get_height(node->left) - get_height(node->right);
}

Node * rotate_left(Node *node){

    Node * child = node->right;
    Node * grandchild = child->left;

    child->left = node;
    node->right = grandchild;

    updateHeight(node);
    updateHeight(child);

    return child;

}

Node * rotate_right(Node *node){
    Node * child = node->left;
    Node * grandchild = child->right;

    child->right = node;
    node->left = grandchild;

    updateHeight(node);
    updateHeight(child);

}

Node * rotate(Node *node){

    int balance = balance_factor(node);

    //Unbalanced to the left
    if(balance > 1){
        if(balance_factor(node->left) >= 0)
            return rotate_right(node);
        else{
            node->left = rotate_left(node->left);
            return rotate_right(node);
        }
    }
    //Unbalanced to the right
    if(balance < -1){
        if(balance_factor(node->right) <= 0)
            return rotate_left(node);
        else{
            node->right = rotate_right(node->right);
            return rotate_left(node);
        }
    }

    //Balanced
    return node;

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

    updateHeight(new_node);

    new_node = rotate(new_node);

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

        node->key = aux->key;

        free(aux);

    }

    return root;

}   