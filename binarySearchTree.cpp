#include <iostream>

using namespace std;

struct Node{
    Node(string str):word(str), left(nullptr), right(nullptr), parent(nullptr) {}
    string word;
    struct Node *left, *right, *parent;
};

class BST {



    private:

    Node *root;

    public:

    BST(){
        root = nullptr;
    }

    Node * BST::getRootNode(){
        return root;
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
            cout << n->word << endl;
            inorder(n->right);
        }
    }

    void insert(string word){
        if(root == nullptr){
            root = new Node(word);
        } 
        else{
            Node *newNode = new Node(word);
            Node *find = root;
            while(find != nullptr){
                newNode->parent = find;
                if(newNode->word < find->word)
                    find = find->left;
                else
                    find = find->right;
            }
            if(newNode->word < newNode->parent->word)
                newNode->parent->left = newNode;
            else
                newNode->parent->right = newNode;
        }
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