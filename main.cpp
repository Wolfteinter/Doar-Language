#include "Extractor.cpp"
#include "LexicoAnalysis.cpp"
using namespace std;
int main(){
    Extractor extractor("code.txt");
    LexicoAnalysis analy;
    cout<<extractor.extract()<<endl;
    //vector<string> errors = analy.analysis(extractor.extractTokens());
    //cout<<"------"<<endl;
    //for(string s: extractor.extractTokens()){
    //    cout<<s<<endl;
    //}
    return 0;
}
