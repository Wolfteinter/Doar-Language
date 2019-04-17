#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include "Extractor.cpp"
#include "Preprocessor.cpp"

using namespace std;

class Analyzer {
    private:
        vector<string> tokens;
        int cont;
    public:
        Analyzer(vector<string>);
        ~Analyzer();
        string getToken();
        void program();
        void block();
        void proposition();
        void expression();
        void condition();
        void identifier();
        void number();
        void text();
        void boolean();
        void aux1();
        void aux2();
        void aux3();
        void aux4();
        void aux5();
        void aux6();
        void aux7();
        void aux8();
        void aux9();
        void aux10();
        void aux11();
        void aux12();
        void aux13();
        void aux14();
        void aux15();
        void aux16();
        void aux17();
        void aux18();
        void aux19();
        void aux20();
        void aux21();
        void aux22();
        void aux26();
        void aux28();
        void aux29();
        void aux30();
        void aux31();
        void aux32();
        void aux33();
        void aux34();
        void aux35();
        void aux36();
        void aux37();
        void reportError(int);
};

// Constructor
Analyzer::Analyzer(vector<string> tokens) {
    this->cont = 0;
    this->tokens = tokens;
    cout << tokens.size() << endl;
}

// Destructor
Analyzer::~Analyzer() {
    this->cont = 0;
    if(!this->tokens.empty())
        this->tokens.clear();
}

// Get token in current position [value of cont]
string Analyzer::getToken() {
    if(this->tokens.size() > 0 && this->cont < (int)this->tokens.size())
        return this->tokens[this->cont];
    else
        return ""+(char)0; // null char
}

void Analyzer::program() {
    block();
    this->cont++;
    string str = getToken();
    if((int)str[0] == 0)
        cout << "Successful compilation" << endl;
    else
        reportError(0);
}

void Analyzer::block() {

}

void Analyzer::reportError(int codeError) {
    switch (codeError) {
        case 0:
            cout << "Unexpected symbol in EOF" << endl;
            break;
        case 1:
            break;
        case 2:
            break;
        case 3:
            break;
        case 4:
            break;
        case 5:
            break;
        case 6:
            break;
        case 7:
            break;
        case 8:
            break;
        case 9:
            break;
        case 10:
            break;
        default:
            cout << "" << endl;
    }
}

int main() {
    string fileName = "code.txt";
    Extractor extractor(Preprocessor::preprocessFile(fileName));
    Analyzer analyzer(extractor.extractTokens());
    // Now, we will remove the temporary file
    remove(("temp_"+fileName).c_str());
    return 0;
}

// Notas:

/*
En algunas funciones como los identificadores necesitamos saber si
se es identificador retornando la palabra 'ident', para ello se debe resolver así:
string str = identifier(getToken());

Lo mismo se aplica para número, texto y boolean (true o false)
*/
