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
    
    regex p(R"(do\(\)|don't\(\)|mul\((\d{1,3}),(\d{1,3})\))");
    int res = 0;
    bool search=true; //flag to determine if we continue searching
    while (getline(file,line)) {
        smatch m;
        while(regex_search(line,m,p)){
            if(m[0].str()=="do()")search=true;
            else if(m[0].str()=="don't()")search=false;

            if(search&&m[1].matched&&m[2].matched)res+=stoi(m[1].str())*stoi(m[2].str());
            
            line=m.suffix().str();
        }
    }
    
    cout<<res<<endl;
}
