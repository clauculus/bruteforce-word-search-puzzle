#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>

using namespace std;

int main() {

    string myText;

    /* Read file input
    string inputFile;
    cout << "Enter the file name: ";
    cin >> inputFile;
    */

    // Read from the text file
    ifstream MyReadFile("testcase.txt");

    vector<vector<string>> wordpuzzle;
    vector<string> line;
    vector<string> wordlist;
    string parsed;
    bool found = false; 

    // Use a while loop together with the getline() function to read the file line by line
    while (getline (MyReadFile, myText)) {


        if (myText != "" and not found){
            line = {};
            stringstream input_stringstream(myText);
            while (getline(input_stringstream, parsed, ' '))
            {
                line.push_back(parsed);
            }
            wordpuzzle.push_back(line);
        } else {
            found = true;
        }

        if (found){
            if (myText == ""){
                // do nothing
            } else {
                wordlist.push_back(myText);
            }
        }

    }

    /*
    cout << wordpuzzle.size() << endl;
    cout << wordpuzzle[0][0] << endl;
    cout << wordpuzzle[0][1] << endl;
    cout << wordpuzzle[0][2] << endl;
    cout << wordpuzzle[0][3] << endl;
    cout << wordpuzzle[0][4] << endl;
    cout << wordpuzzle[0][5] << endl;
    cout << wordpuzzle[0][6] << endl;
    cout << wordpuzzle[0][7] << endl;
    cout << wordpuzzle[1][0] << endl;    
    cout << wordpuzzle[1][1] << endl;
    cout << wordpuzzle[1][2] << endl;
    cout << wordpuzzle[1][3] << endl;
    cout << wordpuzzle[1][4] << endl;
    cout << wordpuzzle[1][5] << endl;
    cout << wordpuzzle[1][6] << endl;
    cout << wordpuzzle[1][7] << endl;
    cout << wordlist.size() << endl; 
    cout << wordlist[5] << endl;
    cout << wordlist[6] << endl;
    cout << wordlist[7] << endl; */
    //cout << wordlist[1].size() << endl;

    // Close the file
    MyReadFile.close();

}