#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <algorithm>
class LexicoAnalysis{
    private:
        vector<string> symbolTable;
    public:
        LexicoAnalysis();
        vector<string> analysis(vector<string> tokens);
        bool isNumeric(string n);
        bool isIdentificator(string s);
};
LexicoAnalysis::LexicoAnalysis(){
    this->symbolTable = {"int","dec","bool","chr","str","//","/*","*/","+","-","*","/","%","**","!","_/","++","--","AND","OR","NAND","XOR","XNOR","XNAND","NOT",">>","<<","|","&","^","==","!=",">","<","<=",">=","+=","-=","*=","/=","%=","**=","_/=","=","def","const","iter","to","while","if","else if","print","main","return","void"};
}
vector<string> LexicoAnalysis::analysis(vector<string> tokens){
    vector<string> errors;
    for(string token : tokens){
        if((find(symbolTable.begin(),symbolTable.end(),token) == symbolTable.end())){
            //verificar si es un identificador valido
            if(!isIdentificator(token) && !isNumeric(token) ){
                //cout<<"entre"<<endl;
                errors.push_back(token);
            }
        }
    }
    return errors;
}
bool LexicoAnalysis::isNumeric(string n){
    for(char s : n)
        if(!((s>='0' && s<='9') || s=='.'))
            return false;
    return true;
}
bool LexicoAnalysis::isIdentificator(string s){
    if(!(s[0] >= 'a' && s[0]<= 'z'))
        return false;
    for(int i=1;i<s.length();i++)
        if(!((s[i] >= 'a' && s[i]<= 'z') || (s[i] >= 'A' && s[i]<= 'Z') || (s[i]>='0' && s[i]<='9')))
            return false;
    return true;
}
