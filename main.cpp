/*
Equipo: David Betancourt Montellano, Onder Francisco Campos Garcia.
Núm. lista: 3 , 5.
Fecha: 27/02/2019.
Evidencia: Primera fase de la fase de compilación-> Análisis léxico.
Docente: Karina Rodríguez Mejía.
Programa académico: Ingeniería en sistemas computacionales.
Unidad de aprendizaje: Compiladores.

Compilar con g++ -std=c++11 main.cpp -o main
Para más información revisar 'Instructions.txt'.
*/

#include "Extractor.cpp"
#include "LexicoAnalysis.cpp"
#include "Preprocessor.cpp"

using namespace std;

int main() {
    string fileName = "code.txt";
    Extractor extractor(Preprocessor::preprocessFile(fileName));
    LexicoAnalysis analy;
    // Get set errors
    vector<string> errors = analy.analysis(extractor.extractTokens());
    // Errors:
    if(errors.size() != 0) {
        int err = 1;
        for(string e: errors) {
            cout << "Error " << err << ": " << e << endl;
            err++;
        }
    }
    else cout << "There are no errors" << endl;
    // Now, we will remove the temporary file
    remove(("temp_"+fileName).c_str());
    return 0;
}
