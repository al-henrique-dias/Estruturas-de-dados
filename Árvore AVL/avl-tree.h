typedef struct avl_tree Node;

//AVL Tree - Self Balancing Binary Search Tree
struct avl_tree {
    int key;
    int height;
    Node* left;
    Node* right;//caso algo dê errado, talvez seja a terminodelogia, tente: struct avl_tree * right;
};

//Creates a new AVL Tree node with a given item as the node's key and NULL children
//@param item The new node's key
//@return Pointer to the new node.
Node * create_node(int item);

//Returns the height of a given node
//@param node Pointer to the node
//@return Height (description) of the given node.
int get_height(Node* node);

//Updates the height of a given node based on the height of it's children
//@param node Pointer to node for height update
void update_height(Node *node);

//Returns the balance factor of a given node
//@param node Pointer to node for balance factor analysis
//@return Balance factor (description) of the given node.
int get_balance_factor(Node *node);

//Performs a left rotation for an unbalanced subtree
//@param node Pointer to reference node for rotation
//@return Pointer to the child of the rotated node (now as it's new parent).
Node * rotate_left(Node *node);

//Performs a right rotation for an unbalanced subtree
//@param node Pointer to reference node for rotation
//@return Pointer to the child of the rotated node (now as it's new parent).
Node * rotate_right(Node *node);

//Analyzes the possible rotation cases for a given node and performs the one that fits
//@param node Pointer to reference node for rotation
//@return Pointer to node result from rotation.
Node * rotate(Node *node);

//Inserts a new node to a AVL Tree
//@param new_key New node's key to be inserted
//@param root Pointer to the tree's root
//@return If the new key is not already in the tree, the function returns a pointer to the new node.
//@return If it already exists, the function returns NULL.
Node * insert(int new_key, Node* root);

//Searches for a given key in a AVL Tree
//@param key Key being searched for
//@param root Pointer to the tree's root
//@return If the given key is found, the function returns a pointer to it's node.
//@return If it is not found, the function returns NULL.
Node * search(int key, Node* root);

//Removes a node with a given key from the AVL Tree
//@param key Key of the node to be removed
//@param root Pointer to the tree's root
//@return A pointer to the new root of the tree. If the key was not found, the root remains unchanged.
Node * remove(int key, Node* root);