#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
#include <regex>
using namespace std;

int main() {
    ifstream file("inputdata.txt");
    string s;
    string line;
    
    regex p(R"(mul\((\d{1,3}),(\d{1,3})\))");
    int res = 0;

    while (getline(file,line)) {
        smatch m;
        while(regex_search(line,m,p)){
            res+=stoi(m[1].str())*stoi(m[2].str());
            line = m.suffix().str();
        }
    }
    
    cout<<res<<endl;
}
