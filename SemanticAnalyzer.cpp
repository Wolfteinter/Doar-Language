#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <vector>
#include <string>
#include <algorithm>
#include "Extractor.cpp"
#include "Preprocessor.cpp"

#define watch(x) cout << (#x) << " is " << (x) << endl;

using namespace std;

class Function {
    private:
        string name;
        vector<string> params;
        string typeOfReturn;
    public:
        Function();
        ~Function();
        bool testName(string);
        bool testParams(vector<string>);
        bool testTypeOfReturn(string);
        string getName();
        vector<string> getParams();
        string getTypeOfReturn();
        void setName(string);
        void setParams(vector<string>);
        void setTypeOfReturn(string);
};

Function::Function() {
    this->name = "";
    this->typeOfReturn = "";
}

Function::~Function() {
    if(!this->name.empty()) this->name.clear();
    if(!this->params.empty()) this->params.clear();
    if(!this->typeOfReturn.empty()) this->typeOfReturn.clear();
}

bool Function::testName(string name) {
    return (this->name == name);
}

bool Function::testParams(vector <string> args) {
    bool ans = true;

    if(args.size() != this->params.size()) ans = false;
    // Compare each type of argument
    else {
        for (unsigned int i = 0; i < args.size(); i++) {
            if(args[i] != this->params[i]) {
                ans = false;
                break;
            }
        }
    }
    return ans;
}

bool Function::testTypeOfReturn(string type) {
    return (this->typeOfReturn == type);
}

// Access methods
string Function::getName() {
    return this->name;
}

vector<string> Function::getParams() {
    return this->params;
}

string Function::getTypeOfReturn() {
    return this->typeOfReturn;
}

void Function::setName(string name) {
    this->name = name;
}

void Function::setParams(vector<string> args) {
    this->params = args;
}

void Function::setTypeOfReturn(string type) {
    this->typeOfReturn = type;
}

class Analyzer {
    private:
        vector<string> tokens;
        int cont;
        bool isThereAnError;
        vector<Function> functions;
    public:
        Analyzer(vector<string>);
        ~Analyzer();
        string getToken();
        string postGetToken();
        void program();//Ready
        void block();//David
        bool proposition();//David
        void expression();//David
        bool condition();//David
        string sorter();//Onder Ready
        string postSorter();
        bool isIdentifier(string word);//Onder Ready
        bool isNumber(string word);//Onder Ready
        bool isText(string word);//Onder Ready
        bool isBoolean(string word);//Onder Ready
        void aux1();//Onder
        bool aux2();//Onder
        bool aux3();//Onder
        bool aux4();//Onder
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
        bool aux31();//David
        bool aux32();//David
        void aux33();//David
        bool aux34();//David
        bool aux35();//David
        void aux36();//David
        bool aux37();//David
        void reportError(int);//Onder Y David
};

// Constructor
Analyzer::Analyzer(vector<string> tokens) {
    this->cont = -1;
    this->tokens = tokens;
    this->isThereAnError = false;
}

// Destructor
Analyzer::~Analyzer() {
    this->cont = -1;
    if(!this->tokens.empty())
        this->tokens.clear();
}

// Utility: Get token in current position [value of cont]
string Analyzer::getToken() {
    if(this->tokens.size() > 0 && this->cont < (int)this->tokens.size())
        return this->tokens[this->cont];
    else
        return ""+(char)0; // null char
}

// Utility: Get token in current position [value of cont+1]
string Analyzer::postGetToken() {
    if(this->tokens.size() > 0 && this->cont+1 < (int)this->tokens.size())
        return this->tokens[this->cont+1];
    else
        return ""+(char)0; // null char
}

void Analyzer::program() {
    cout<<"---program---"<<endl;
    block();
    this->cont++;
    string str = getToken();
    if((int)str[0] == 0) {
        if(this->isThereAnError) cout << "The compilation has failed" << endl;
        else cout << "Successful compilation" << endl;
    }
    else {
        reportError(0);
        cout << "The compilation has failed" << endl;
    }
}

void Analyzer::block() {
    cout<<"---block---"<<endl;
    aux1();
    aux9();
    //aux16();
}

bool Analyzer::proposition(){
    cout<<"---proposition---"<<endl;
    this->cont++;
    string str = getToken();
    string type = sorter();
    bool ans = true;

    if(str == "if") {
        this->cont++;
        str = getToken();
        if(str == "(") {
            if(condition()) {
                this->cont++;
                str = getToken();
                if(str == ")") {
                    aux22();
                    aux26();
                    aux29();
                }
                else reportError(15);
            }
        }
        else reportError(15);
    }
    else if(str == "while") {
        this->cont++;
        str = getToken();
        if(str == "(") {
            if(condition()) {
                this->cont++;
                str = getToken();
                if(str == ")") {
                    this->cont++;
                    str = getToken();
                    if(str == "{") {
                        aux17();
                        this->cont++;
                        str = getToken();
                        if(str != "}") reportError(16);
                    }
                    else reportError(16);
                }
                else reportError(15);
            }
        }
        else reportError(15);
    }
    else if(str == "iter") {
        this->cont++;
        str = getToken();
        if(str == "(") {
            if(aux31()) {
                this->cont++;
                str = getToken();
                if(str == "to") {
                    if(aux31()) {
                        this->cont++;
                        str = getToken();
                        if(str == ")") {
                            this->cont++;
                            str = getToken();
                            if(str == "{") {
                                aux17();
                                this->cont++;
                                str = getToken();
                                if(str != "}") reportError(16);
                            }
                            else reportError(16);
                        }
                        else reportError(15);
                    }
                }
                else reportError(17);
            }
        }
        else reportError(15);
    }
    // Firsts aux2, variables declaration
    else if(str == "int") {
        aux6();
        this->cont++;
        str = getToken();
        if(str != ";") reportError(3);
    }
    else if(str == "dec") {
        aux6();
        this->cont++;
        str = getToken();
        if(str != ";") reportError(3);
    }
    else if(str == "bool") {
        aux6();
        this->cont++;
        str = getToken();
        if(str != ";") reportError(3);
    }
    else if(str == "chr") {
        aux6();
        this->cont++;
        str = getToken();
        if(str != ";") reportError(3);
    }
    else if(str == "str") {
        aux6();
        this->cont++;
        str = getToken();
        if(str != ";") reportError(3);
    }
    // With sorter, for identifiers
    else if(type == "identifier") {
        this->cont++;
        str = getToken();
        // Calling a function
        if(str == "(") {
            aux19();
            this->cont++;
            str = getToken();
            if(str == ")") {
                this->cont++;
                str = getToken();
                if(str != ";") reportError(3);
            }
            else {
                reportError(15);
            }
        }
        // Asigning calling a function
        else if(str == "=" && postSorter() == "identifier") {
            this->cont += 2;
            str = getToken();
            if(str == "(") {
                aux19();
                this->cont++;
                str = getToken();
                if(str == ")") {
                    this->cont++;
                    str = getToken();
                    if(str != ";") reportError(3);
                }
                else {
                    reportError(15);
                }
            }
            else {
                this->cont--;
                if(aux34()) {
                    this->cont -= 2;
                    str = getToken();
                    if(str == "=" || str == "+=" || str == "-=" || str == "*=" ||
                        str == "/=" || str == "%=" || (str == "**" && postGetToken() == "=")
                        || (str == "_/" && postGetToken() == "=")) {
                        this->cont -= 2;
                        expression();
                    }
                    else {
                        reportError(19);
                    }
                }
                else {
                    reportError(23);
                }
            }
        }
        // Simple asigning with expression
        else if(str == "=" || str == "+=" || str == "-=" || str == "*=" ||
            str == "/=" || str == "%=" || (str == "**" && postGetToken() == "=")
            || (str == "_/" && postGetToken() == "=")) {
            this->cont -= 2;
            expression();
        }
        else {
            reportError(19);
        }
    }
    else {
        reportError(2);
        ans = false;
    }
    return ans;
}

void Analyzer::expression() {
    cout<<"---expression---"<<endl;
    this->cont++;
    string type = sorter();
    string str = getToken();
    if(type == "identifier") {
        aux32();
        aux31();
        aux33();
        this->cont++;
        str = getToken();
        if(str != ";") reportError(3);
    }
    else reportError(18);
}

bool Analyzer::condition() {
    cout<<"---condition---"<<endl;
    bool ans = true;
    if(aux15()) {
        if(aux35()) {
            if(aux15()) {
                aux36();
            }
            else ans = false;
        }
        else ans = false;
    }
    else ans = false;

    return ans;
}

string Analyzer::sorter() {
    string word = getToken();
    if(isBoolean(word)) return "boolean";
    else if(isIdentifier(word)) return "identifier";
    else if(isNumber(word)) return "number";
    else if(isText(word)) return "text";
    else return "other";
}

string Analyzer::postSorter() {
    this->cont++;
    string word = getToken();
    this->cont--;
    if(isBoolean(word)) return "boolean";
    else if(isIdentifier(word)) return "identifier";
    else if(isNumber(word)) return "number";
    else if(isText(word)) return "text";
    else return "other";
}

bool Analyzer::isIdentifier(string word) {
    if(!(word[0] >= 'a' && word[0]<= 'z'))
        return false;
    for(unsigned int i = 1; i < word.length(); i++)
        if(!((word[i] >= 'a' && word[i] <= 'z') || (word[i] >= 'A' && word[i] <= 'Z') ||
            (word[i] >='0' && word[i] <= '9')))
            return false;
    return true;
}

bool Analyzer::isNumber(string word) {
    for(char s : word)
        if(!((s >= '0' && s <= '9') || s == '.'))
            return false;
    return true;
}

bool Analyzer::isText(string word) {
    return (word[0] == 34 and word[word.length()-1] == 34);
}

bool Analyzer::isBoolean(string word) {
    return (word == "true" || word == "false");
}

void Analyzer::aux1() {
    cout<<"---aux1---"<<endl;
    this->cont++;
    string str = getToken();
    if(str == "const") {
        if(aux2() && aux3() && aux4()) {
            this->cont++;
            str = getToken();
            if(str == ";") aux1();
            else reportError(3);
        }
    }
    else this->cont--;
}

bool Analyzer::aux2() {
    cout<<"---aux2---"<<endl;
    this->cont++;
    string str = getToken();
    // watch(str);
    if(str == "int" || str == "dec" || str == "bool" || str == "chr" || str == "str")
        return true;
    else {
        reportError(27);
        return false;
    }
}

bool Analyzer::aux3() {
    cout<<"---aux3---"<<endl;
    this->cont++;
    bool ans = false;
    //watch(getToken());
    if(sorter() == "identifier") {
        this->cont++;
        string str = getToken();
        if(str == "=") ans = true;
    }
    return ans;
}

bool Analyzer::aux4() {
    cout<<"---aux4---"<<endl;
    this->cont++;
    string word = sorter();
    bool ans = false;
    if(word == "number" || word == "boolean" || word == "text") {
        ans = true;
    }
    return ans;
}

void Analyzer::aux6() {
    cout<<"---aux6---"<<endl;
    this->cont++;
    if(sorter() == "identifier") {
        aux8();
        aux7();
    }
}

void Analyzer::aux7() {
    cout<<"---aux7---"<<endl;
    this->cont++;
    string str = getToken();
    // watch(str);
    if(str == ",") aux6();
    else this->cont--;
}

void Analyzer::aux8() {
    cout<<"---aux8---"<<endl;
    this->cont++;
    string str = getToken();
    // watch(str);
    if(str == "=") aux4();
    else this->cont--;
}

void Analyzer::aux9() {
    cout<<"---aux9---"<<endl;
    this->cont++;
    string str = getToken();
    //watch(str);
    if(str == "int") {
        this->cont++;
        str = getToken();
        if(str == "def") {
            this->cont++;
            str = getToken();
            if(str == "main"){
                aux16();
                return;
            }
            else {
                this->cont-=2;
            }
        }
        else {
            this->cont--;
        }
    }

    this->cont--;
    //watch(getToken());
    if(aux2()) { // int, dec, bool, chr o str
        this->cont++;
        string str = getToken();
        if(str == "def") { // methods or functions
            this->cont++;
            if(sorter() == "identifier") {
                this->cont++;
                str = getToken();
                if(str == "(") {
                    aux10();
                    this->cont++;
                    str = getToken();
                    if(str == ")") {
                        this->cont++;
                        str = getToken();
                        if(str == "{") {
                            aux12();
                            aux14();
                            this->cont++;
                            str = getToken();
                            if(str == "}") {
                                aux9();
                            }
                            else reportError(16);
                        }
                        else reportError(24);
                    }
                    else reportError(15);
                }
                else reportError(23);
            }
            else reportError(26);
        }
        else { // variables declaration
            this->cont--;
            aux6();
            this->cont++;
            string str = getToken();
            if(str != ";") {
                reportError(3);
            }
            else aux9();
        }
    }
    else this->cont--;
}

void Analyzer::aux10() {
    cout<<"---aux10---"<<endl;
    if(postGetToken() != ")") {
        if(aux2()) {
            this->cont++;
            if(sorter() == "identifier") aux11();
        }
        else this->cont--;
    }
}

void Analyzer::aux11() {
    cout<<"---aux11---"<<endl;
    this->cont++;
    string str = getToken();
    if(str == ",") aux10();
    else this->cont--;
}

void Analyzer::aux12() {
    cout<<"---aux12---"<<endl;
    if(proposition()) {
        aux13();
    }
}

void Analyzer::aux13() {
    cout<<"---aux13---"<<endl;
    this->cont++;
    string str = getToken();
    if(str != "return" && str != "}") {
        this->cont--;
        aux12();
    }
    else {
        this->cont--;
    }
}

void Analyzer::aux14() {
    cout<<"---aux14---"<<endl;
    this->cont++;
    string str = getToken();
    if(str == "return") {
        aux15();
        this->cont++;
        str = getToken();
        if(str != ";") reportError(3);
    }
    else this->cont--;
}

bool Analyzer::aux15() {
    cout<<"---aux15---"<<endl;
    this->cont++;
    string word = sorter();
    bool ans = false;
    if(word == "number" || word == "boolean" || word == "text" || word == "identifier") {
        ans = true;
    }
    return ans;
}

void Analyzer::aux16() {
    cout<<"---aux16---"<<endl;
    this->cont++;
    string str = getToken();
    if(str == "(") {
        this->cont++;
        str = getToken();
        if(str == ")") {
            this->cont++;
            str = getToken();
            if(str == "{") {
                aux17();
                this->cont++;
                str = getToken();
                if(str == "return") {
                    this->cont++;
                    str = getToken();
                    if(str == "0") {
                        this->cont++;
                        str = getToken();
                        if(str == ";") {
                            this->cont++;
                            str = getToken();
                            if(str != "}") reportError(16);
                        }
                        else reportError(3);
                    }
                    else reportError(4);
                }
                else reportError(5);
            }
            else reportError(24);
        }
        else reportError(15);
    }
    else reportError(23);

}

void Analyzer::aux17() {
    cout<<"---aux17---"<<endl;
    this->cont++;
    string str = getToken();
    if(str != "return" && str != "}") {
        this->cont--;
        if(proposition()) aux18();
    }
    else {
        this->cont--;
    }
}

void Analyzer::aux18() {
    cout<<"---aux18---"<<endl;
    this->cont++;
    string str = getToken();
    if(str != "return" && str != "}") {
        this->cont--;
        aux17();
    }
    else this->cont--;
}

void Analyzer::aux19() {
    cout<<"---aux19---"<<endl;
    this->cont++;
    string str = getToken();
    if(str != ")") {
	this->cont--;
        if(aux15()) aux20();
        else reportError(20);
    }
    else this->cont--;
}

void Analyzer::aux20() {
    cout<<"---aux20---"<<endl;
    this->cont++;
    string str = getToken();
    if(str != ")") {
        if(str == ",") aux19();
        else reportError(21);
    }
    else this->cont--;
}

void Analyzer::aux21() {
    cout<<"---aux21---"<<endl;
    this->cont++;
    string type = sorter();
    this->cont++;
    string str = getToken();
    // Duda, porque se supone que puede ser identificador o bien expresión
    // sin embargo, el first de expression también es un identificador
    // para solventar eso, leo el siguiente token después del indentificador
    if(type == "identifier" && str != "=") {
        if(str == "(") {
            aux19();
            this->cont++;
            str = getToken();
            if(str == ")") {
                this->cont++;
                str = getToken();
                if(str != ";") reportError(3);
            }
            else reportError(15);
        }
        else reportError(23);
    }
    else {
        this->cont -= 2;
        expression();
    }
}

void Analyzer::aux22() {
    cout<<"---aux22---"<<endl;
    this->cont++;
    string str = getToken();
    string type = sorter();

    if(str != "else" && str != "int" && str != "dec" && str != "bool" &&
        str != "chr" && str != "str" && type != "identifier" && str != "if" &&
        str != "while" && str != "iter" && str != "return" && str != "}") {
        if(str == "{") {
            aux17();
            this->cont++;
            str = getToken();
            if(str != "}") reportError(16);
        }
        else reportError(24);
    }
    else this->cont--;
}

void Analyzer::aux26() {
    cout<<"---aux26---"<<endl;
    this->cont++;
    string str = getToken();
    // Aquí hay un detalle, ya los follow de aux26 incluyen el 'else' y en
    // aux26, cuando no se omite, comienza con 'else if'.
    // Para solucionarlo, se lee un siguiente token, para comprobar si es if
    /*
    if((str != "else" || (str == "else" && str2 == "if")) && str != "int" &&
        str != "dec" && str != "bool" && str != "chr" && str != "str" &&
        type != "identifier" && str != "if" && str != "while" && str != "iter"
        && str != "return" && str != "}") {
    */
    if(str == "else" && postGetToken() == "if"){
        this->cont += 2;
        str = getToken();
        if(str == "(") {
            if(condition()) {
                this->cont++;
                str = getToken();
                if(str == ")") {
                    aux22();
                    aux28();
                }
                else reportError(15);
            }
        }
        else reportError(23);
    }
    else this->cont--;
}

void Analyzer::aux28() {
    cout<<"---aux28---"<<endl;
    this->cont++;
    string str = getToken();
    string type = sorter();
    this->cont++;
    string str2 = getToken();

    if((str != "else" || (str == "else" && str2 == "if")) && str != "int" &&
        str != "dec" && str != "bool" && str != "chr" && str != "str" &&
        type != "identifier" && str != "if" && str != "while" && str != "iter"
        && str != "return" && str != "}") {
        aux26();
    }
    else this->cont -= 2;
}

void Analyzer::aux29() {
    cout<<"---aux29---"<<endl;
    this->cont++;
    string str = getToken();

    if(str != "int" && str != "dec" && str != "bool" && str != "chr" &&
        str != "str" && str != "if" && str != "while"
        && str != "iter" && str != "return" && str != "}") {
        if(str == "else") aux30();
        else reportError(25);
    }
    else this->cont--;
}

void Analyzer::aux30() {
    cout<<"---aux30---"<<endl;
    this->cont++;
    string str = getToken();
    string type = sorter();

    if(str != "int" && str != "dec" && str != "bool" && str != "chr" &&
        str != "str" && type != "identifier" && str != "if" && str != "while"
        && str != "iter" && str != "return" && str != "}") {
        if(str == "{") {
            aux17();
            this->cont++;
            str = getToken();
            if(str != "}") reportError(16);
        }
        else reportError(24);
    }
    else this->cont--;
}

bool Analyzer::aux31() {
    cout<<"---aux31---"<<endl;
    bool ans = true;
    this->cont++;
    string type = sorter();
    if(type != "identifier" && type != "number") ans = false;
    return ans;
}

bool Analyzer::aux32() {
    cout<<"---aux32---"<<endl;
    bool ans = true;
    this->cont++;
    string str = getToken();
    if(str != "=" && str != "+=" && str != "-=" && str != "*=" && str != "/=" &&
        str != "%=" && (str != "**" && postGetToken() != "=") && (str != "_/" && postGetToken() != "=")) {
        ans = false;
    }

    if((str == "**" && postGetToken() == "=") ||
        (str == "_/" && postGetToken() == "=")) {
        this->cont++;
    }
    return ans;
}

void Analyzer::aux33() {
    cout<<"---aux33---"<<endl;
    this->cont++;
    string str = getToken();
    if(str != ";") {
        this->cont--;
        if(aux34() && aux31()) aux33();
    }
    else this->cont--;
}

bool Analyzer::aux34() {
    cout<<"---aux34---"<<endl;
    bool ans = true;
    this->cont++;
    string str = getToken();
    if(str != "+" && str != "-" && str != "*" && str != "/" && str != "%" &&
        str != "**" && str != "_/") {
        ans = false;
    }
    return ans;
}

bool Analyzer::aux35() {
    cout<<"---aux35---"<<endl;
    bool ans = true;
    this->cont++;
    string str = getToken();

    if(str != "==" && str != "!=" && str != ">" && str != "<" && str != "<=" &&
        str != ">=") {
        ans = false;
        reportError(28);
    }
    return ans;
}

void Analyzer::aux36() {
    cout<<"---aux36---"<<endl;
    this->cont++;
    string str = getToken();
    if(str != ")") {
        this->cont--;
        if(aux37()) {
            if(condition()) {
                // no hacer nada
            }
        }
    }
    else this->cont--;
}

bool Analyzer::aux37() {
    cout<<"---aux37---"<<endl;
    bool ans = true;
    this->cont++;
    string str = getToken();
    if(str != "AND" && str != "OR" && str != "NAND" && str != "XOR" &&
    str != "XNOR" && str != "XNAND") {
        ans = false;
    }
    return ans;
}

void Analyzer::reportError(int codeError) {
    this->isThereAnError = true;
    switch (codeError) {
        case 0:
            cout << "Unexpected symbol in EOF." << endl;
            break;
        case 1:
            cout << "Unexpected sentence." << endl;
            break;
        case 2:
            cout << "Bad structure. A proposition was expected." << endl;
            break;
        case 3:
            cout << "Was expected semicolon." << endl;
            break;
        case 4:
            cout << "Was expected a 0 (process code)." << endl;
            break;
        case 5:
            cout << "Was expected return." << endl;
            break;
        case 6:
            cout << "Main entry don't found." <<endl;
            break;
        case 7:
            cout << "Was expected def." <<endl;
            break;
        case 8:
            cout << "Main function missing integer." << endl;
            break;
        case 15:
            cout << "Unbalanced expression with parentheses." << endl;
            break;
        case 16:
            cout << "Unbalanced expression in braces." << endl;
            break;
        case 17:
            cout << "It was expected 'to'." << endl;
            break;
        case 18:
            cout << "Bad structure. An expression was expected." << endl;
            break;
        case 19:
            cout << "Expected ')' or '='." << endl;
            break;
        case 20:
            cout << "Expected bool, text, number or identifier." << endl;
            break;
        case 21:
            cout << "A coma (,) expected." << endl;
            break;
        case 22:
            cout << "An identifier or number expected." << endl;
            break;
        case 23:
            cout << "A parentheses '(' expected." << endl;
            break;
        case 24:
            cout << "A key '{' was expected." << endl;
            break;
        case 25:
            cout << "It was expected 'else'." << endl;
            break;
        case 26:
            cout << "An identifier was expected." << endl;
            break;
        case 27:
            cout<<"Was expected a data type"<<endl;
            break;
        case 28:
            cout << "== or != or > or < or <= or >= operator was expected." << endl;
            break;
        default:
            cout << "";
    }
}

int main() {
    string fileName = "code.doa";
    Extractor extractor(Preprocessor::preprocessFile(fileName));
    vector<string> ans = extractor.extractTokens();
    for(unsigned int i = 0;i < ans.size();i++){
        cout<<ans[i]<<endl;
    }
    Analyzer analyzer(ans);
    analyzer.program();
    // Now, we will remove the temporary file
    remove(("temp_"+fileName).c_str());
    return 0;
}
