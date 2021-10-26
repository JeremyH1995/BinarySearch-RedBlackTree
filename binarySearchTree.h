#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H

using namespace std;

struct Node{
    Node(string str);
    string word;
    struct Node *left, *right, *parent;
};

class BST {

    private:

    Node *root;

    public:

    BST();

    Node *getRootNode();

    void printParentKey(string key);

    void printLeftChild(string key);

    void printRightChild(string key);

    void printPathToRoot(string key);

    void inorder(Node *n);

    void insert(string str);

    bool search(string str);

};

#endif