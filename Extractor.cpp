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
        vector <string> extractWords();
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
vector <string> Extractor::extractWords() {
    int c;
    vector <string> words;
    string aux = "";
    // until the character read is different from null
    while ((c = (int)extract())) {
        // is it a char or number?
        if((c >= 65 && c <= 90) || (c >= 97 && c <= 122) || (c >= 48 && c <= 57)) {
            aux += (char)c;
        }
        else {
            if(aux != "") words.push_back(aux);
            aux = "";
        }
    }

    return words;
}

int main() {
    Extractor ext("code.txt");
    vector <string> ans = ext.extractWords();
    cout << ans.size() << endl;
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
}
