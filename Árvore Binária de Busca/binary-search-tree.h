typedef struct binary_search_tree Node;

//BST - Binary Search Tree
struct binary_search_tree {
    int key;
    Node* left;
    Node* right;//caso algo dê errado, talvez seja a terminodelogia, tente: struct arvore* direito;
};

//Creates a new BST node with the parameter item as the node's key and NULL children
//@param item The new node's key
//@return Pointer to the new node
Node* new_node(int item);

//Inserts a new node to a BST
//@param new_key New node's key to be inserted
//@param root Pointer to the tree's root
//@return If the new key is not already in the tree, the function returns the pointer to the new node.
//@return If it already exists, the function returns NULL
Node* insert(int new_key, Node* root);
void search();
void remove();