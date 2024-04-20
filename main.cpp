#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include <string>
#include <cstring>

using namespace std;

/*
*******************************
*          SET UP             *
*******************************
*/
// Function to display the content of a file (see in credits)

void displayFileContent(const string & filename) {
    ifstream file(filename); // Open file with given filename for reading
    string line; // Declare a string to store each line of text

  if (file.is_open()) { // Check if the file was successfully opened
        cout << "File content:" << endl; // Displaying a message indicating file content
    while (getline(file, line)) { // Read each line from the file
        cout << line << endl; // Display each line of the file
    }
    file.close(); // Close the file
  } else {
        cout << "Failed to open the file." << endl; // Display an error message if file opening failed
  }
}

// Function to search for a string in a file and display line numbers where it is found (see in credits)

void searchAndDisplayLineNumbers(const string & filename, const string & searchStr) {
  ifstream file(filename); // Open file with given filename for reading
  string line; // Declare a string to store each line of text
  vector<int> lineNumbers; // Vector to store line numbers where the search string is found
  int lineNumber = 1; // Variable to track the current line number

  while (getline(file, line)) { // Read each line from the file
    if (line.find(searchStr) != string::npos) { // Check if the search string is found in the line
      lineNumbers.push_back(lineNumber); // Store the line number where the search string is found
        cout << line << endl; // Grabbing the line where I wrote it
    }
    lineNumber++; // Increment the line number counter
  }

  file.close(); // Close the file after reading

  if (!lineNumbers.empty()) { // Check if any line numbers were stored
        cout << "String \"" << searchStr << line << "\" found at line number(s): "; // Display a message indicating the search string was found

    for (int i = 0; i < lineNumbers.size(); ++i) { // Loop through the stored line numbers
        cout << lineNumbers[i]; // Display each line number

      if (i != lineNumbers.size() - 1) {
            cout << ", "; // Display a comma between line numbers, except for the last one
      }
    }

        cout << endl; // Move to the next line after displaying line numbers
  } else {
        cout << "String \"" << searchStr << line << "\" not found in the file." << endl; // Display a message indicating the search string was not found
  }
}

// main func etc yk
int main(){
    // Variables
    string usrname, pswd;
    string website;
    bool check1 = true;
    string search;
    fstream myFile;
    int choice;

    // Setting up Files
        // Initual Adding to files.
    myFile.open("pswdHolder.txt", ios::out);
    if(myFile.is_open()) {
        myFile << "Password Mannager" << endl << "Website:Username:Password" << endl << endl;
        myFile.close();
    }


    // New Menu system!!
    do {
        // GI for menu
        cout << endl 
        << " 1 - Add Password\n"
        << " 2 - Search\n"
        << " 3 - Help\n"
        << " 4 - Exit\n"
        << " Enter your choice and press return:";
        // Reads Input
        cin >> choice;

        switch(choice) {
            // Code that does what the menu chooses
            case 1: {
                // Gets Passwords AND puts them in File

                // Conformation and getting Usernames/Passwords
                while (check1) {
                    char aswr = 'n';
                    char aswr2 = 'n';

                    // Website Name
                    cout << "Enter Website Name:" << endl;
                    cin >> website;

                    // Usernames and Passwords
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

                // Adding information into file
                myFile.open("pswdHolder.txt", ios::app);
                if(myFile.is_open()) {
                    myFile << website << ":" << usrname << ":" << pswd << endl;
                    cout << myFile.tellg() << endl;
                    myFile.close();
                } else {
                    printf("\n##################  'Adding Info into File' failed for some reason dumbass  ##################");
                }
                bool check1 = true;
                char aswr = 'n';
                char aswr2 = 'n';
                break;
            }
            case 2: {
                // File search

                cout << "Enter Thing you wanna search for: " << endl;
                cin >> search; // chanaged shit here
                string filename = "pswdHolder.txt"; // File to search
                displayFileContent("new_test.txt"); // Display content of "new_test.txt"
                cout << endl; // Output a newline for formatting

                string searchStr = search; // String to search
                searchAndDisplayLineNumbers(filename, searchStr); // Search for the string in the file and display line numbers where it's found

                break;
            }
            case 3: {
                
                break;
            }
            case 4: 
                exit(main());
            break;
            
        }
        

    } while (choice!=4);

    return 0;
}
