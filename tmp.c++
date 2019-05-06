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
        string sorter();//Onder Ready
        bool isIdentifier(string word);//Onder Ready
        bool isNumber(string word);//Onder Ready
        bool isText(string word);//Onder Ready
        bool isBoolean(string word);//Onder Ready
        bool aux1();//Onder
        bool aux2();//Onder
        bool aux3();//Onder
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
        bool aux15();//Onder
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
void aux1(){
    this->cont++;
    string str = getToken();
    if(str=="const"){
        if(aux2() && aux3() && aux4()){
            this->cont++;
            if(str == ";") aux1();
            else reportError(3);
        }
    }else{
        this->cont--;
    }
}
bool aux2(){
    this->cont++;
    string str = getToken();
    if(str == "int" || str == "dec" || str == "bool" || str == chr || str == "str") return true;
    else{
        reportError(4);
        return false;
    }
}
bool aux3(){
    this->cont++;
    string str = getToken();
    bool ans = false;
    if(sorter() == "identifier"){
        this->cont++;
        string str = getToken();
        if(str=="="){
            ans = true;
        }
    }
    return ans;
}
bool aux4(){
    this->cont++;
    string word = sorter();
    bool ans = false;
    if(word == "number" || word == "boolean" || word == "text"){
        ans = true;
    }
    return ans;
}

bool aux6(){
    this->cont++;
    if(sorter() == "identifier"){
        aux8();
        aux7();
    }
}
void aux7(){
    this->cont++;
    string str = getToken();
    if(str=","){
        aux6();
    }else{
        this->cont--;
    }
}
void aux8(){
    this->cont++;
    string str = getToken();
    if(str="="){
        aux4();
    }else{
        this->cont--;
    }
}
void aux9(){
    if(aux2){
        this->cont++;
        string str = getToken();
        if(str=="def"){
            this->cont++;
            if(sorter()=="identifier"){
                this->cont++;
                string str = getToken();
                if(str == "("){
                    aux10();
                    this->cont++;
                    string str = getToken();
                    if(str == ")"){
                        this->cont++;
                        string str = getToken();
                        if(str == "{"){
                            aux12()
                            aux14();
                            this->cont++;
                            string str = getToken();
                            if(str == "}"){
                                aux9();
                            }else{
                                //Error faltan llaves
                                reportError(16);
                            }
                        }
                    }
                }
            }
        }else{
            aux6();
            this->cont++;
            string str = getToken();
            if(str != ";"){
                reportError(3);
            }
        }
    }else{
        this->cont--;
    }
}
void aux10(){
    if(aux2()){
        this->cont++;
        if(sorter() == "identifier"){
            aux11();
        }
    }else{
        this->cont--;
    }
}
void aux11(){
    this->cont++;
    string str = getToken();
    if(str == ","){
        aux10();
    }else{
        this->cont--;
    }
}
void aux12(){
    if(proposition()){
        aux13();
    }
}
void aux13(){
    this->cont++;
    string str = getToken();
    if(str != "return" && str != "}"){
        aux12();
    }else{
        this->cont--;
    }
}
void aux14(){
    this->cont++;
    string str = getToken();
    if(str == "return"){
        aux15();
    }else{
        this->cont--;
    }
}
bool aux15(){
    this->cont++;
    string word = sorter();
    bool ans = false;
    if(word == "number" || word == "boolean" || word == "text" || word == "identifier"){
        ans = true;
    }
    return ans;
}
void aux16(){
    this->cont++;
    string str = getToken();
    if(str == "int"){
        this->cont++;
        string str = getToken();
        if(str == "def"){
            this->cont++;
            string str = getToken();
            if(str == "main"){
                this->cont++;
                string str = getToken();
                if(str == "("){
                    this->cont++;
                    string str = getToken();
                    if(str == ")"){
                        this->cont++;
                        string str = getToken();
                        if(str == "{"){
                            aux17();
                            this->cont++;
                            string str = getToken();
                            if(str == "return"){
                                this->cont++;
                                string str = getToken();
                                if(str == "0"){
                                    this->cont++;
                                    string str = getToken();
                                    if(str == ";"){
                                        this->cont++;
                                        string str = getToken();
                                        if(str != "}"){
                                            reportError(16);
                                        }
                                    }else{
                                        reportError(3);
                                    }
                                }else{
                                    reportError(4);
                                }
                            }else{
                                reportError(5);
                            }
                        }else{
                            reportError(24);
                        }
                    }else{
                        reportError(15);
                    }
                }else{
                    reportError(23);
                }
            }else{
                reportError(6);
            }
        }else{
            reportError(7);
        }
    }else{
        reportError(8);
    }
}
void aux17(){
    this->cont++;
    string str = getToken();
    if(str != "return" && str != "}"){
        if(proposition()){
            aux18();
        }
    }else{
        this.cont--;
    }
}

string sorter(){
    word = getToken();
    if(isIdentifier(word)) return "identifier";
    else if(isNumber(word)) return "number";
    else if(isText(word)) return "text";
    else if(isBoolean(word)) return "boolean";
    else reportError(1);
}
bool isIdentifier(string word){
    if(!(word[0] >= 'a' && word[0]<= 'z'))
        return false;
    for(unsigned int i = 1; i < word.length(); i++)
        if(!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') || (word[i] >='0' && word[i] <= '9')))
            return false;
    return true;
}
bool isNumber(string word){
    for(char s : word)
        if(!((s >= '0' && s <= '9') || s == '.'))
            return false;
    return true;
}
bool isText(string word){
    return (word[0]== 34 and word[word.length()-1] == 34);
}
bool isBoolean(string word){
    return (word == "true" || word == "false");
}

void Analyzer::reportError(int codeError) {
    switch (codeError) {
        case 0:
            cout<<"Unexpected symbol in EOF"<<endl;
            break;
        case 1:
            cout<<"Unexpected sentence"<<endl;
            break;
        case 2:
            break;
        case 3:
            cout<<"Was expected semicolon"<<endl;
            break;
        case 4:
            cout<<"Was expected a 0 (process code)"<<endl;
            break;
        case 5:
            cout<<"Was expected return"<<endl;
            break;
        case 6:
            cout<<"main entry don't found"<<endl;
            break;
        case 7:
            cout<<"Was expected def"<<endl;
            break;
        case 8:
            cout<<"De la funcion main falta tipo entero"<<endl;
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
