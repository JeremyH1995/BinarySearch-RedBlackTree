#include <iostream>

using namespace std;

struct node{
    string key;
    struct node *left, *right;
};

class BST {

    node *root;

    public:

    node *getRootNode();

    struct node *newNode(string item);

    void printParentKey(string key);

    void printLeftChild(string key);

    void printRightChild(string key);

    void printPathToRoot(string key);

    void inorder(node *n);

    void insert(string str);

    bool search(string str);


};