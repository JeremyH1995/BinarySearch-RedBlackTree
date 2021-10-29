#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H 
#include <iostream>

using namespace std;

class RBT{

    private:

    const string BLACK = "black";
    const string RED = "red";

    Node *root;
    Node * NIL;

    public:

    RBT(){
        NIL = new Node("NIL");
        NIL->color = BLACK;
        NIL->left = nullptr;
        NIL->right = nullptr;
        NIL->parent = nullptr;
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
        std::cout << "The left child of " << key << " is " << n->left->word << endl;
    }

    void printRightChild(string key){
        Node *n = search(root, key);
       std::cout << "The right child of " << key << " is " << n->right->word << endl;
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
            std::cout << n->word << " color: " << n->color <<  endl;
            inorder(n->right);
        }
    }


    void printUncleColor(string key){
        Node *n = search(root, key);
        std::cout << "The Uncle nodes color is " << n->parent->parent->right->color << endl;
    }

   

    void printColor(string key){
        Node * n = search(root, key);
        if(n != NIL)
            std::cout << "The color of " << key << " is " << n->color << endl;
        else
            printf("key does not exist");
    }

   void insert(string word){

       if(root == NIL){
            root = new Node(word);
            root->left = NIL;
            root->right = NIL;
            root ->parent = NIL;
            root->color = BLACK;
            return;
        }
       
        Node * node = new Node(word);
        node->parent = NIL;
        node->left = NIL;
        node->right = NIL;
        node->color = RED;
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
        node->color = RED;

        insertFixup(node);
        
    }


    void insertFixup(Node * n){
        Node * temp;
        while(n->parent->color == RED){
            if(n->parent == n->parent->parent->right){
                temp = n->parent->parent->left;
                if(temp->color == RED){
                    n->parent->color = BLACK;
                    temp->color = BLACK;
                    n->parent->parent->color = RED;
                    n = n->parent->parent;
                }
                else{
                    if(n == n->parent->left){
                        n = n->parent;
                        rightRotate(n);
                    }
                    n->parent->color = BLACK;
                    n->parent->parent->color = RED;
                    leftRotate(n->parent->parent);
                }
            }
            else{
                temp = n->parent->parent->right;
                if(temp->color == RED){
                    n->parent->color = BLACK;
                    temp->color = BLACK;
                    n->parent->parent->color = RED;
                    n = n->parent->parent;
                }
                else{ 
                    if(n == n->parent->right){
                        n = n->parent;
                        leftRotate(n);
                    }
                    n->parent->color = BLACK;
                    n->parent->parent->color = RED;
                    rightRotate(n->parent->parent);
                }
            }
            if(n == root){
                break;
            }
        }
        root->color = BLACK;
    }

    void leftRotate(Node * n){
        Node * temp = n->right;
        n->right = temp->left;
        if(temp->left != NIL){
            temp->left->parent = n;
        }
        temp->parent = n->parent;
        if(n->parent == NIL){
            root = temp;
        }
        else if(n == n->parent->left){
            n->parent->left = temp;
        }
        else{
            n->parent->right = temp;
        }
        temp->left = n;
        n->parent = temp;
    }

    void rightRotate(Node * n){
        Node * temp = n->left;
        n->left = temp->right;
        if(temp->right != NIL){
            temp->right->parent = n;
        }
        temp->parent = n->parent;
        if(n->parent == NIL){
            root = temp;
        }
        else if(n == n->parent->right){
            n->parent->right = temp;
        }
        else{
            n->parent->left = temp;
        }
        temp->right = n;
        n->parent = temp;
    }

    Node * search(Node *n, string str){
        if(n == NIL || str == n->word)
            return n;
        if(str < n->word)
            return search(n->left, str);
        else
            return search(n->right, str);
    }
};

#endif