#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>

using namespace std;

class LexicoAnalysis {
    private:
        vector <string> symbolTable;
    public:
        LexicoAnalysis();
        vector<string> analysis(vector<string> tokens);
        bool isNumeric(string n);
        bool isIdentifier(string s);
};

LexicoAnalysis::LexicoAnalysis(){
    this->symbolTable = {"int","dec","bool","chr","str","+","-","*","/","%","**","!","_/","++","--","AND","OR","NAND","XOR","XNOR","XNAND","NOT",">>","<<","|","&","^","==","!=",">","<","<=",">=","+=","-=","*=","/=","%=","**=","_/=","=","def","const","iter","to","while","if","else if","print","main","return","void", ",", ";", "(", ")", "{", "}", "[", "]", "true", "false"};
}

vector<string> LexicoAnalysis::analysis(vector<string> tokens) {
    vector <string> errors;
    for(string token : tokens) {
        if(token[0] == '"' && token[token.size()-1] == '"') continue;
        if((find(symbolTable.begin(),symbolTable.end(),token) == symbolTable.end())){
            // Is it a valid identifier?
            bool isIdent = isIdentifier(token);
            bool isNum = isNumeric(token);
            if(!isIdent && !isNum) { // no
                if((token[0] >= 65 && token[0] <= 90) || (token[0] >= 97 && token[0] <= 122) || ((token[0] >= 48 && token[0] <= 57))) {
                    errors.push_back(token + ", invalid identifier.");
                }
                else errors.push_back(token + ", invalid symbol.");
            }
        }
    }
    return errors;
}

bool LexicoAnalysis::isNumeric(string n){
    for(char s : n)
        if(!((s >= '0' && s <= '9') || s == '.'))
            return false;
    return true;
}

bool LexicoAnalysis::isIdentifier(string s){
    if(!(s[0] >= 'a' && s[0]<= 'z'))
        return false;
    for(unsigned int i=1;i<s.length();i++)
        if(!((s[i] >= 'a' && s[i] <= 'z') || (s[i] >= 'A' && s[i] <= 'Z') || (s[i] >='0' && s[i] <= '9')))
            return false;
    return true;
}
