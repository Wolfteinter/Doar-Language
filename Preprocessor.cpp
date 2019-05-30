#include <cstdio>
#include <cstdlib>
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Preprocessor {
    public:
        // Methods
        static string preprocessFile(string dirFile);
};

string Preprocessor::preprocessFile(string dirFile) {
    string nameTemp = "temp_" + dirFile;
    // Create temp file
    system(("echo > " + nameTemp).c_str());
    // Open the tempFile
    fstream tmpFile(nameTemp);
    // Open original source code file
    fstream originalFile;
    // Open the file
    originalFile.open(dirFile, ios::in);
    char c, prev = ' ';
    string line = "";
    // Read char by char
    if (originalFile.is_open()) {
        while (originalFile.get(c)) {
            if(c == ' ') {
                if((prev >= '0' && prev <= '9') || (prev >= 'A' && prev <= 'Z') || (prev >= 'a' && prev <= 'z')) {
                    originalFile.get(c);
                    if((int)c == 0) break; // enf of file
                    if((c >= '0' && c <= '9') || (c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z') || (c == '\"') || (c == '\'')) {
                        tmpFile << " "; // insert whitespace
                    }
                    tmpFile << c;
                }
            }
            // Ignore comments
            else if(c == '/') {
                originalFile.get(c);
                if((int)c == 0) break; // enf of file
                if(c == '/') { // single comment -> // content
                    while (originalFile.get(c)) {
                        if((int)c == 10) break;
                    }
                }
                else if(c == '*') { // multi-line comment -> /* */
                    prev = ' ';
                    while (originalFile.get(c)) {
                        if(c == '/' && prev == '*') break;
                        prev = c;
                    }
                }
                else {
                    tmpFile << "/";
                    tmpFile << c;
                }
            }
            else {
                if((int)c == 10) {
                    if(line != "") {
                        line = "";
                        tmpFile << c;
                    }
                }
                else {
                    line += ""+c;
                    tmpFile << c;
                }
            }
            prev = c;
        }
    }
    originalFile.close();
    tmpFile.close();
    return nameTemp;
}

/*
int main() {
    cout << Preprocessor::preprocessFile("code.txt") << endl;
    return 0;
}
*/
