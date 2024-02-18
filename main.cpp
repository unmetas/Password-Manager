#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;


int main(){
    string usrname, pswd;
    bool check1 = true;
    fstream myFile;
    // Conformation and getting Usernames/Passwords
    while (check1) {
        char aswr = 'n';
        char aswr2 = 'n';
        
        if (aswr == 'n') {
            cout << "Type in Username: " << endl;
            cin >> usrname;
            cout << "Do you confirm this Username [y/n]?" << endl;
            cin >> aswr;
            if (aswr == 'y') {
                cout << "Type in Password: " << endl;
                cin >> pswd;
                cout << "Do you confirm this Password [y/n]?" << endl;
                cin >> aswr2;
                if (aswr2 == 'y') {
                    cout << "Thank you!" << endl;
                    check1 = false;  // Exit the loop
                } else {
                    cout << "Please confirm the password again." << endl;
                }
            } else {
                cout << "Please confirm the username again." << endl;
            }
        }
    }

    printf("\ndgjhagh\n");
    // File Handling
    myFile.open("pswdHolder.txt", ios::out);
    if(myFile.is_open()) {
        cout << "" << endl;
    }

    // Adding information into file
    myFile.open("pswdHolder.txt", ios::app);
    if(myFile.is_open()) {
        myFile << usrname << ":" << pswd << endl;
        myFile.close();
    }
    return 0;
}