#include <iostream>
#include <fstream>
#include <string>

using namespace std;


fstream myFile;

int main(){


    myFile.open("testing.txt", ios::out); //write mode, out will override a file.
    if(myFile.is_open()) {
        myFile << "hello\n"; // can use the subject file instead of cout
        myFile << "this is second line\n";
        myFile.close();
    }
    myFile.open("testing.txt", ios::app); //append mode, appends new info into file
    if(myFile.is_open()) {
        myFile << "hello2\n";
        myFile.close();
    }
    return 0;
}

int readFile(){
    myFile.open("testing.txt", ios::in);    
    if(myFile.is_open()) {
        string line;
        while(getline(myFile, line)){
            cout << line << endl;
        }
        myFile.close();
    }


    return 0;
}