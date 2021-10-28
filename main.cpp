#include <iostream>
#include <fstream>
#include <string>
#include "binarySearchTree.h"

using namespace std;

string* readFile(string filename, int size){
    string line;
    string* array = new string[size];
    ifstream inputfile;
    int count = 0;
    inputfile.open(filename);
    if(inputfile.is_open()){
        while(getline(inputfile, line)){
            array[count++] = line;
        }
        inputfile.close();
        return array;
    }
}

int numWords(string str){
    string value;
    if(str.substr(0, 4) == "perm"){
        if(str.length() == 11){
            value = str.substr(4, 2);
            return stoi(value) * 1000;
        }
        else if(str.length() == 12){
            value = str.substr(4, 3);
            return stoi(value) * 1000;
        }
    }
    else if(str.substr(0, 6) == "sorted"){
        if(str.length() == 13){
            value = str.substr(6, 2);
            return stoi(value) * 1000;
        }
        else if(str.length() == 14){
            value = str.substr(6, 3);
            return stoi(value) * 1000;
        }
    }
}

int main(){
    int menuChoice = 0;
    int fileTypeChoice = 0;
    int fileChoice = 0;
    int treeChoice = 0;
    int n = 0;
    string searchWord;
    string find, str;
    string files[10];
    string *words;
    BST BST;
    Node * found;

     while(true){
        cout << "Enter which instruction you would like to execute." << endl;
        cout << "1: Search for Word" << endl;
        cout << "2: Construct Binary Search Tree with file" << endl;
        cout << "3: Construct Red Black Tree with file" << endl;
        cout << "0: Exit" << endl;
        cout << "Choice: ";
        cin >> menuChoice;
        cout << "\n\n";

        while(menuChoice < 0 || menuChoice > 3){
            cout << "Invalid Input." << endl;
            cout << "Choice: ";
            cin >> menuChoice;
        }

        if(menuChoice == 0) break;

        if(menuChoice == 1){
            cout << "Which tree you would like to search?" << endl;
            cout << "1: Binary Search Tree" << endl;
            cout << "2: Red Black Tree" << endl;
            cout << "0: Exit" << endl;
            cout << "Choice: ";
            cin >> treeChoice;
            cout << "\n\n";

            while(treeChoice < 0 || treeChoice > 2){
                cout << "Invalid Input." << endl;
                cout << "Choice: ";
                cin >> treeChoice;
            }

            if(treeChoice == 0) break;

            if(treeChoice == 1){
                cout << "Type a word you would like to search for:";
                cin >> searchWord;
                cout << "\n\n\n";

                found = BST.search(BST.getRootNode(), searchWord);

                if(found != nullptr)
                    cout << searchWord << " was found" << endl;
                else if(found == nullptr)
                    cout << searchWord << " was not found" << endl;
            }
            else if(treeChoice == 2){
                //search Red Black Tree
            }

        }
        else if(menuChoice == 2){
            cout << "Enter which type of file you wish to import." << endl;
            cout << "1: Unsorted Input" << endl;
            cout << "2: Sorted Input" << endl;
            cout << "0: Exit" << endl;
            cout << "Choice: ";
            cin >> fileTypeChoice;
            cout << "\n\n";

              while(fileTypeChoice < 0 || fileTypeChoice > 2){
                    cout << "Invalid Input." << endl;
                    cout << "Choice: ";
                    cin >> fileTypeChoice;
                }

                if(fileTypeChoice == 0) break;

                if(fileTypeChoice == 1){
                    find = "perm";
                }
                else if(fileTypeChoice == 2){
                    find = "sorted";
                }

                //Print files and add to array
                for(int j = 1; j <= 10; j++){
                    str = find + to_string(15*j) + "K.txt";
                    cout << j << ": " << str << endl;
                    files[j - 1] = str;
                }     
                cout << "Choice: ";
                cin >> fileChoice;
                cout << "\n\n";
                    
                while(fileChoice < 0 || fileChoice > 10){
                    cout << "Invalid Input." << endl;
                    cout << "Choice: ";
                    cin >> fileChoice;
                }

                if(fileChoice == 0) break;

                    str = files[fileChoice - 1];
                    n = numWords(str);
                    words = new string[n];
                    words = readFile(str, n);
                    //Insert into Binary Search Tree
                    for(int i = 0; i < n; i++){
                        BST.insert(words[i]);
                    }
                    cout << "Here is the results of your insertion: " << endl;
                    BST.inorder(BST.getRootNode());

            }    
            else if(menuChoice == 3){
                 //construct red black tree
            }
      }

    return 0;
}