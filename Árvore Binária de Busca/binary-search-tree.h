typedef struct binary_search_tree Node;

//BST - Binary Search Tree
struct binary_search_tree {
    int key;
    Node* left;
    Node* right;//caso algo dê errado, talvez seja a terminodelogia, tente: struct arvore* direito;
};

//Creates a new BST node with a given item as the node's key and NULL children
//@param item The new node's key
//@return Pointer to the new node
Node * create_node(int item);

//Inserts a new node to a BST
//@param new_key New node's key to be inserted
//@param root Pointer to the tree's root
//@return If the new key is not already in the tree, the function returns a pointer to the new node.
//@return If it already exists, the function returns NULL.
Node * insert(int new_key, Node* root);

//Searches for a given key in a BST
//@param key Key being searched for
//@param root Pointer to the tree's root
//@return If the given key is found, the function returns a pointer to it's node.
//@return If it is not found, the function returns NULL.
Node * search(int key, Node* root);

//Removes a node with a given key from the BST
//@param key Key of the node to be removed
//@param root Pointer to the tree's root
//@return  A pointer to the new root of the tree. If the key was not found, the root remains unchanged.
Node * remove(int key, Node* root);