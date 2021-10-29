#ifndef BINARYSEARCHTREE_H
#define BINARYSEARCHTREE_H 
#include <iostream>

using namespace std;

struct Node{
    Node(string str):word(str), color("none"), left(nullptr), right(nullptr), parent(nullptr){}
    Node(string str, string col):word(str), color(col), left(nullptr), right(nullptr), parent(nullptr) {}
    string word;
    string color;
    struct Node *left, *right, *parent;
};

class BST {

    private:

    Node *root;
    Node *NIL;
    
    const string BLACK = "black";
    const string RED = "red";

    public:

    BST(){
        NIL = new Node("NIL");
        NIL->color = BLACK;
        NIL->left = nullptr;
        NIL->right = nullptr;
        NIL->parent = NIL;
        root = NIL;
    }

    Node * getRootNode(){
        return root;
    }

    void printParentKey(string key){
        Node *n = search(root, key);
        std::cout << "The parent of " << key << " is " << n->parent->word << endl;
    }

    void printLeftChild(string key){
        Node *n = search(root, key);
        if(n != NIL)
            std::cout << "The left child of " << key << " is " << n->left->word << endl;
        else
            std::cout << "The left child of " << key << " is " << NIL->word;
    }

    void printRightChild(string key){
        Node *n = search(root, key);
         if(n != NIL)
            std::cout << "The right child of " << key << " is " << n->left->word << endl;
        else
            std::cout << "The right child of " << key << " is " << NIL->word;
    }

    void printPathToRootHelper(Node * node){
      
       std::cout << " -> " << node->word;

        if(node->parent == NIL)
            return;

       printPathToRootHelper(node->parent);
        
    }

    void printPathToRoot(string key){
        Node * node = search(root, key);
        if(node != NIL){
            cout << node->word;
            printPathToRootHelper(node->parent);
            cout << endl;
        }
        else{
            std::cout << "node is null" << endl;
        }
    }

    void inorder(Node *n){
        if(n != NIL){
            inorder(n->left);
            std::cout << n->word << endl;
            inorder(n->right);
        }
    }

    void insert(string word){

        if(root == NIL){
            root = new Node(word);
            root->left = NIL;
            root->right = NIL;
            root ->parent = NIL;
            return;
        }
       
        Node * node = new Node(word);
        node->parent = nullptr;
        node->left = NIL;
        node->right = NIL;
        Node * x = root;
        Node * y = NIL;

        while(x != NIL){
            y = x;
            if(node->word < x->word)
                x = x->left;
            else
                x = x->right;
        }

        node->parent = y;
        if(y == NIL)
            root = node;
        else if(node->word < y->word)
            y->left = node;
        else
            y->right = node;

        node->left = NIL;
        node->right = NIL;
        
    }
    Node * search(Node *n, string key){
      if(n == NIL || key == n->word)
        return n;
      if(key < n->word)
        return search(n->left, key);
      else
        return search(n->right, key);
    }
};

#endif