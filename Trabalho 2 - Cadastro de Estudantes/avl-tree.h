typedef struct avl_tree Node;
typedef struct data_nascimento Data_nascimento;

struct data_nascimento{
    int dia;
    int mes;
    int ano;
};

//AVL Tree - Self Balancing Binary Search Tree
struct avl_tree{

    //Student
    int rga;//Node key
    char nome[60];
    Data_nascimento data_nasc;
    int codigo_curso;
    int ano_ingresso;

    int height;
    struct avl_tree *left;
    struct avl_tree *right;//caso algo dê errado, talvez seja a terminodelogia, tente: struct avl_tree * right;
};

//Creates a new AVL Tree node with a given item as the node's key and NULL children
//change
//@param item The new node's key
//@return Pointer to the new node.
Node * create_node(int rga, char *nome, Data_nascimento data_nasc, int codigo_curso, int ano_ingresso);

//Returns the height of a given node
//@param node Pointer to the node
//@return Height (description) of the given node.
int get_height(Node *node);

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
//change
//@param new_key New node's key to be inserted
//@param root Pointer to the tree's root
//@return If the new key is not already in the tree, the function returns a pointer to the new node.
//@return If it already exists, the function returns NULL.
Node * insert_node(int rga, char *nome, Data_nascimento data_nasc, int codigo_curso, int ano_ingresso, Node *root);

//Searches for a given key in a AVL Tree
//@param key Key being searched for
//@param root Pointer to the tree's root
//@return If the given key is found, the function returns a pointer to it's node.
//@return If it is not found, the function returns NULL.
Node * search_node(int rga, Node *root);

//Removes a node with a given key from the AVL Tree
//@param key Key of the node to be removed
//@param root Pointer to the tree's root
//@return A pointer to the new root of the tree. If the key was not found, the root remains unchanged.
Node * remove_node(int rga, Node *root);

void pre_order(Node* root);
void in_order(Node* root);
void post_order(Node* root);