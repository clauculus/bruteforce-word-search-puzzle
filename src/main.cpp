#include<iostream>
#include<fstream>
#include<vector>
#include<sstream>
#include<chrono>

using namespace std;

// function to convert parsed string to character
char string2char(string s){

    if (s == "A"){
        return 'A';
    } else if (s == "B"){
        return 'B';
    } else if (s == "C"){
        return 'C';
    } else if (s == "D"){
        return 'D';
    } else if (s == "E"){
        return 'E';
    } else if (s == "F"){
        return 'F';
    } else if (s == "G"){
        return 'G';
    } else if (s == "H"){
        return 'H';
    } else if (s == "I"){
        return 'I';
    } else if (s == "J"){
        return 'J';
    } else if (s == "K"){
        return 'K';
    } else if (s == "L"){
        return 'L';
    } else if (s == "M"){
        return 'M';
    } else if (s == "N"){
        return 'N';
    } else if (s == "O"){
        return 'O';
    } else if (s == "P"){
        return 'P';
    } else if (s == "Q"){
        return 'Q';
    } else if (s == "R"){
        return 'R';
    } else if (s == "S"){
        return 'S';
    } else if (s == "T"){
        return 'T';
    } else if (s == "U"){
        return 'U';
    } else if (s == "V"){
        return 'V';
    } else if (s == "W"){
        return 'W';
    } else if (s == "X"){
        return 'X';
    } else if (s == "Y"){
        return 'Y';
    } else {
        return 'Z';
    }          

}

// to find {i, j} exists in a 2d vector
// helper for printing
bool findpoint(vector<vector<int>> pointvector, int x, int y){
    int i = 0;
    bool found = false;

    while (i < pointvector.size() && (!found)){
        if ((pointvector[i][0] == x) && (pointvector[i][1] == y)){
            found = true;
        } else {
            i++;
        }
    }

    return found;
}

// to find {i, j} exists in which index in a 2d vector
// helper for printing
int findpointposition(vector<vector<int>> pointvector, int x, int y){
    int i = 0;
    bool found = false;

    while (i < pointvector.size() && (!found)){
        if ((pointvector[i][0] == x) && (pointvector[i][1] == y)){
            found = true;
        } else {
            i++;
        }
    }

    return i;
}

// function to return the coordinate of the string found in the puzzle
// { {x1, y1}, {x2, y2}, ...}
vector<vector<int>> returnpoint(vector<vector<char>> wordpuzzle, vector<string> wordlist, int R, int C, int row, int col, int i){

    vector<vector<int>> stringcoordinate;
    vector<int> coordinate;

    int x[8] = {1, 1, 1, 0, 0, -1, -1 ,-1};
    int y[8] = {1, 0, -1, 1, -1, 1, 0, -1};

    // search wordlist in 8 directions
    for (int d = 0; d < 8; d++) {


        int newrow = row + x[d];
        int newcol = col + y[d];
        int n;

        // will reset the coordinate and vector of coordinates if it changes direction
        coordinate = {}; 
        stringcoordinate = {};
        coordinate.push_back(newrow);
        coordinate.push_back(newcol);
        stringcoordinate.push_back(coordinate);

        // match remaining characters 
        for (n = 1; n < wordlist[i].size(); n++) {

            if (newrow >= R || newrow < 0 || newcol >= C || newcol < 0){ // out of bound
                break;                
            } else if (wordpuzzle[newrow][newcol] != wordlist[i][n]){ // stop the string matching if a character does not match
                break;                
            }

            // moving along
            newrow = newrow + x[d];
            newcol = newcol + y[d];
            
            // will reset the coordinate
            coordinate = {};
            coordinate.push_back(newrow);
            coordinate.push_back(newcol);
            stringcoordinate.push_back(coordinate);
        }

        // if matched
        if (n == wordlist[i].size()){
            return stringcoordinate;            
        }

    }
    return {};    
}

// helper function
bool searchpoint(vector<vector<char>> wordpuzzle, vector<string> wordlist, int R, int C, int row, int col, int i){

    int x[8] = {1, 1, 1, 0, 0, -1, -1 ,-1};
    int y[8] = {1, 0, -1, 1, -1, 1, 0, -1};

    // if the first character of wordlist doesn't match 
    if (wordlist[i][0] != wordpuzzle[row][col]){
        return false;       
    }

    // search wordlist in 8 directions
    for (int d = 0; d < 8; d++) {

        int newrow = row + x[d];
        int newcol = col + y[d];
        int n;
        // match remaining characters 
        for (n = 1; n < wordlist[i].size(); n++) {

            if (newrow >= R || newrow < 0 || newcol >= C || newcol < 0){ // out of bound
                break;                
            } else if (wordpuzzle[newrow][newcol] != wordlist[i][n]){ // stop the string matching if a character does not match
                break;                
            }

            // moving along
            newrow = newrow + x[d];
            newcol = newcol + y[d];
        }

        // if matched
        if (n == wordlist[i].size()){
            return true;            
        }

    }
    return false;    
}

int main() {

    string myText;
    string fileName;
    // read from the text file
    cout << "Masukkan nama file yang ingin dibaca (beserta .txt): ";
    cin >> fileName;

    ifstream readFile(fileName);

    vector<vector<char>> wordpuzzle;
    vector<char> line;
    vector<string> wordlist;
    string parsed;
    bool found = false; 

    // read the file line by line
    while (getline (readFile, myText)) {

        if (myText != "" and not found){
            line = {};
            stringstream input_stringstream(myText);
            while (getline(input_stringstream, parsed, ' '))
            {
                line.push_back(string2char(parsed)); 
            }

            wordpuzzle.push_back(line);
        } else {
            found = true;
        }

        if (found){
            if (myText == ""){ // identifier between wordpuzzle and wordlist
                // do nothing
            } else {
                wordlist.push_back(myText);
            }
        }

    }

    // create output file    
    ofstream outputFile("output.txt");

    // check all strings in wordlist
    for (int i=0; i < wordlist.size(); i++){

        auto start = std::chrono::steady_clock::now();

        for (int row = 0; row < wordpuzzle.size(); row++){
            for (int col = 0; col < wordpuzzle[0].size(); col++){
                if (searchpoint(wordpuzzle, wordlist, wordpuzzle.size(), wordpuzzle[0].size(), row, col, i)){
    
                    vector<vector<int>> stringcoordinate = returnpoint(wordpuzzle, wordlist, wordpuzzle.size(), wordpuzzle[0].size(), row, col, i);
                    cout << wordlist[i] << endl;
                    for (int k=0; k < wordpuzzle.size(); k++){
                        for (int l=0; l < wordpuzzle[0].size(); l++){
                            if (k == row && l == col){
                                cout << wordlist[i][0];
                                outputFile << wordlist[i][0];
                                cout << " ";
                                outputFile << " ";
                            } else if (findpoint(stringcoordinate, k, l)){
                                int p = findpointposition(stringcoordinate, k, l);
                                cout << wordlist[i][p+1];
                                outputFile << wordlist[i][p+1];
                                cout << " ";
                                outputFile << " ";
                            } else {
                                cout << "- ";
                                outputFile << "- ";
                            }
                        }
                        cout << endl;
                        outputFile << endl;
                    }                    
                }
            }
        }

        auto stop = std::chrono::steady_clock::now();

        std::chrono::duration<double> diff = stop - start;
        std::cout << "Time taken: "<< diff.count() << " s" << endl;
        cout << endl;
        cout << endl;

        outputFile << "Time taken: ";
        outputFile << diff.count();
        outputFile << " s";
        outputFile << endl;
        outputFile << endl;
    }

    // Close the file
    readFile.close();
    outputFile.close();

}