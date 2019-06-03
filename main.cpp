/*
Equipo: David Betancourt Montellano, Onder Francisco Campos Garcia.
Núm. lista: 3 , 5.
Fecha: Junio del 2019
Evidencia: Analizador semántico
Docente: Karina Rodríguez Mejía.
Programa académico: Ingeniería en sistemas computacionales.
Unidad de aprendizaje: Compiladores.

Compilar con g++ -std=c++11 main.cpp -o main
Para más información revisar 'Instructions.txt'.
*/

#include "Extractor.cpp"
#include "LexicoAnalysis.cpp"
#include "Preprocessor.cpp"
#include "SemanticAnalyzer.cpp"

using namespace std;

int main() {
    string fileName = "code.doa";
    Extractor extractor(Preprocessor::preprocessFile(fileName));
    LexicoAnalysis analy;
    vector<string> ans = extractor.extractTokens();
    // Get set errors
    vector<string> errors = analy.analysis(ans);
    // Errors:
    if(errors.size() != 0) {
        int err = 1;
        for(string e: errors) {
            cout << "Error " << err << ": " << e << endl;
            err++;
        }
    }
    else {
        // Syntactic analysis and semantic analysis
        Analyzer analyzer(ans);
        analyzer.program();
    }
    // Now, we will remove the temporary file
    remove(("temp_"+fileName).c_str());
    return 0;
}
