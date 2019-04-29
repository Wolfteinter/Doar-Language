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
        void program();//Ready
        void block();//David
        void proposition();//David
        void expression();//David
        void condition();//David
        void identifier();//Onder
        void number();//Onder
        void text();//Onder
        void boolean();//Onder
        void aux1();//Onder
        void aux2();//Onder
        void aux3();//Onder
        void aux4();//Onder
        void aux5();//Onder
        void aux6();//Onder
        void aux7();//Onder
        void aux8();//Onder
        void aux9();//Onder
        void aux10();//Onder
        void aux11();//Onder
        void aux12();//Onder
        void aux13();//Onder
        void aux14();//Onder
        void aux15();//Onder
        void aux16();//Onder
        void aux17();//Onder
        void aux18();//David
        void aux19();//David
        void aux20();//David
        void aux21();//David
        void aux22();//David
        void aux26();//David
        void aux28();//David
        void aux29();//David
        void aux30();//David
        void aux31();//David
        void aux32();//David
        void aux33();//David
        void aux34();//David
        void aux35();//David
        void aux36();//David
        void aux37();//David
        void reportError(int);//Onder Y David
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
