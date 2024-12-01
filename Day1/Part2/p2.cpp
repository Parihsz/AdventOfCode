#include <iostream>
#include <fstream>
#include <string>
#include <unordered_map>
#include <vector>
using namespace std;

int main(){
    ifstream file("inputdata.txt");
    vector<int> a,b;
    string line;
    unordered_map<int, int>f;
    int l,r,s=0;
    while (file>>l>>r){
        a.push_back(l);
        b.push_back(r);
        f[r]++;
    }
    file.close();
    for (int i:a)s+=i*f[i];
    cout<<s<<endl;
}