#ifndef REDBLACKTREE_H
#define REDBLACKTREE_H 
#include <iostream>

using namespace std;


class RBT{

    private:

    const string BLACK = "black";
    const string RED = "red";

    Node *root;

    public:

    RBT(){
        root = nullptr;
    }

    Node * getRootNode(){
        return root;
    }

    Node * newNode(string word, string col){
        return new Node(word, col);
    }

    void printParentKey(string key){
        Node *n = search(root, key);
        printf("The parent of %s is %s\n", key, n->parent->word);
    }

    void printLeftChild(string key){
        Node *n = search(root, key);
        printf("The left child of %s is %s\n", n->word, n->left->word);
    }

    void printRightChild(string key){
        Node *n = search(root, key);
        printf("The right child of %s is %s\n", n->word, n->right->word);
    }

    void printPathToRoot(string key){
        Node *n = search(root, key);
        printf("Path to Root from %s\n", key);
        while(n->parent != nullptr){
            printf("%s\n", n->parent);
        }
    }

    void inorder(Node *n){
        if(n != nullptr){
            inorder(n->left);
            cout << n->word << " || color: " << n->color << endl;
            inorder(n->right);
        }
    }

    void insert(string word){
       Node * n = new Node(word, RED);
       Node * y = nullptr;
       Node * x = root;

       while(x != nullptr){
           y = x;
           if(n->word < x->word){
               x = x->left;
           }
           else{
               x = x->right;
           }
       }

       n->parent = y;
       if(y == nullptr){
           root = n;
       }
       else if(n->word < y->word){
           y->left = n;
       }
       else{
           y->right = n;
       }

       if(n->parent == nullptr){
           n->color = BLACK;
           return;
       }

       if(n->parent->parent == nullptr){
           return;
       }

       insertFixup(n);
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
            root->color = BLACK;
        }
    }

    void leftRotate(Node * n){
        Node * temp = n->right;
        n->right = temp->left;
        if(temp->left != nullptr){
            temp->left->parent = n;
        }
        temp->parent = n->parent;
        if(n->parent == nullptr){
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
        if(temp->right != nullptr){
            temp->right->parent = n;
        }
        temp->parent = n->parent;
        if(n->parent == nullptr){
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
        if(n != nullptr | str == n->word)
            return n;
        if(str < n->word)
            return search(n->left, str);
        else
            return search(n->right, str);
    }
};

#endif