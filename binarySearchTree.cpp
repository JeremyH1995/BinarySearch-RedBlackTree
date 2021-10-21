#include <iostream>

using namespace std;

struct node{
    string key;
    struct node *left, *right, *parent;
};

class BST {

    node *root;

    public:

    node *getRootNode(){
        return root;
    }

    struct node *newNode(string item) {
        struct node *temp = (struct node *)malloc(sizeof(struct node));
        temp->key = item;
        temp->left = temp->right = NULL;
        return temp;
    }

    void printParentKey(string key){
        node *n = search(root, key);
        printf("The parent of %s is %s\n", key, n->parent->key);
    }

    void printLeftChild(string key){
        node *n = search(root, key);
        printf("The left child of %s is %s\n", n->key, n->left->key);
    }

    void printRightChild(string key){
        node *n = search(root, key);
        printf("The right child of %s is %s\n", n->key, n->right->key);
    }

    void printPathToRoot(string key){
        node *n = search(root, key);
        printf("Path to Root from %s", key);
        while(n->parent != nullptr){
            printf("%s\n", n->parent);
        }
    }

    void inorder(node *n){
        if(n != nullptr){
            inorder(n->left);
            cout << n->key << endl;
            inorder(n->right);
        }
    }

    void insert(string str){
        if(root == nullptr) 
            newNode(str);
    }

    node *search(node *n, string str){
        if(n != nullptr | str == n->key)
            return n;
        if(str < n->key)
            return search(n->left, str);
        else
            return search(n->right, str);
    }

    



};