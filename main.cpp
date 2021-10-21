#include <iostream>
#include <fstream>
#include <string>

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

int main(){
    int menuChoice = 0;

     while(true){
        cout << "Enter which type of sort you would like to execute." << endl;
        cout << "1: Search for Word" << endl;
        cout << "2: Construct Binary Search Tree with file" << endl;
        cout << "3: Construct Red Black Tree with file" << endl;
        cout << "0: Exit" << endl;
        cout << "Choice: ";
        cin >> menuChoice;
        cout << "\n\n";

        if(menuChoice == 0)
            break;
     }

     

    return 0;
}