/*
Equipo = David Betancourt Montellano, Onder Francisco Campos Garcia
Núm. lista = 3 , 5
Fecha = 31/1/2019
Evidencia = Expresiones regulares para extraer la cadenas
Nombre de Maestro = Karina Rodríguez Mejía
Programa Académico = Ingeniería en sistemas computacionales
Unidad de Aprendizaje = Compiladores

Compilar con g++ -std=c++11 Extractor -o prueba
Es necesario que el code.txt este en el mismo directoerio
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
#include <vector>
using namespace std;
class Extractor{
    private:
        int pointer;
        fstream file;
    public:
        Extractor(string dirFile);
        ~Extractor();
        char extract();
        char extract(int position);
        int getPointer();
        vector <string> extractTokens();
};
Extractor::Extractor(string dirFile){
    this->file.open(dirFile,ios::in);
    this->pointer=0;
}
Extractor::~Extractor(){
    this->file.close();
}
//Extract a char of the txt in secuancial way
char Extractor::extract(){
    char letter[1];
    //this->file.seekg(this->pointer,ios::cur);//auto increase
    this->file.seekg(this->pointer);
    this->file.read(letter,1);
    this->pointer++;
    return letter[0];
}
//Extract a char of a specific position
char Extractor::extract(int position){
    char letter[1];
    this->file.seekg(position);
    this->file.read(letter,1);
    return letter[0];
}
//Get the value of the pointer
int Extractor::getPointer(){
    return this->pointer;
}

// Generate a words vector
// ([a-z]|[A-Z]) (([a-z]|[A-Z]) | [0-9])^*
vector <string> Extractor::extractTokens() {
    int c, sig;
    vector <string> tokens;
    string aux = "";
    // until the character read is different from null
    while ((c = (int)extract())) {
        // is it a char or number?
        cout<<c<<endl;
        if(c != 10){
            if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57) || c == 46){
                sig = extract(getPointer());
                if(c == 46 && (sig < 48 || sig > 57)) {
                    tokens.push_back(aux); // add token without point
                    tokens.push_back("."); // add point
                    this->pointer++; // increase pointer
                    aux = "";
                }
                else aux += (char)c;
            }
            // plus 43, minus 45, greater 62, less 60, asterisc 42
            else if(c == 43 || c == 45 || c == 62 || c == 60 || c == 42) {
                if(aux != "") tokens.push_back(aux);
                aux = "";
                sig = extract(getPointer());
                if(sig == c || sig == 61) {
                    this->pointer++;
                    aux += (char)c;
                    aux += (char)sig;
                    tokens.push_back(aux);
                    aux = "";
                }
                else {
                    aux += (char)c;
                    tokens.push_back(aux);
                    aux = "";
                }
            }
            // division 47, per cent 37, factorial 33, equal 61
            else if(c == 47 || c == 37 || c == 33 || c == 61) {
                if(aux != "") tokens.push_back(aux);
                aux = "";
                sig = extract(getPointer());
                if(sig == 61) {
                    this->pointer++;
                    aux += (char)c;
                    aux += (char)sig;
                    tokens.push_back(aux);
                    aux = "";
                }
                else {
                    aux += (char)c;
                    tokens.push_back(aux);
                    aux = "";
                }
            }
            // n-root
            else if(c == 95) {
                if(aux != "") tokens.push_back(aux);
                aux = "";
                sig = extract(getPointer());
                if(sig == 47) {
                    this->pointer++;
                    aux += (char)c;
                    aux += (char)sig;
                    tokens.push_back(aux);
                    aux = "";
                }
                else {
                    aux += (char)c;
                    tokens.push_back(aux);
                    aux = "";
                }
            }
            else if(c==34 || c==39){
                aux+=(char)c;
                do{
                    c=(int)extract();
                    aux+=(char)c;
                }while(c!=34 && c!=39);

                tokens.push_back(aux);
                aux = "";
            }
            //
            else {
                if(aux != "" ) {
                    tokens.push_back(aux);
                        aux = "";
                    if(c != 32 ){
                        aux+=(char)c;
                        tokens.push_back(aux);
                        aux = "";
                    }
                }else{
                    if(c != 32 ){
                        aux+=(char)c;
                        tokens.push_back(aux);
                        aux = "";
                    }
                }

            }
        }

        //cout<<aux<<endl;
    }

    return tokens;
}
/*
int main() {
    Extractor ext("code.txt");
    vector <string> ans = ext.extractTokens();
    for (unsigned int i = 0; i < ans.size(); i++) {
        cout << ans[i] << endl;
    }
    // cout<<ext.extract(0)<<endl;
    // cout<<ext.extract(0)<<endl;
    // cout<<ext.extract(0)<<endl;
    // cout<<ext.extract(0)<<endl;
    //
    // for (short i = 0; i < 100; i++) {
    //     char c =  ext.extract();
    //     cout << c << " " << (int)c << endl;
    // }
    //
    // cout << "Valor del puntero " << ext.getPointer() << endl;
}*/
