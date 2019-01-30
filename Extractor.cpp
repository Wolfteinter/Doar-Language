/*
Compilar con g++ -std=c++11 Extractor -o prueba
Es necesario que el code.txt este en el mismo directoerio
*/

#include <string>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cstdio>
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
int main(){
    Extractor ext("code.txt");
    cout<<ext.extract(0)<<endl;
    cout<<ext.extract(0)<<endl;
    cout<<ext.extract(0)<<endl;
    cout<<ext.extract(0)<<endl;

    for (short i = 0; i < 18; i++) {
        cout << ext.extract() << endl;
    }

    cout << "Valor del puntero " << ext.getPointer() << endl;
}
