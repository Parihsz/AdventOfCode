#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
    ifstream file("inputdata.txt");
    string s;
    vector<int> a,b;
    string line;
    //parse inputs
    int l,r,res=0;
    while (file>>l>>r)a.push_back(l),b.push_back(r); //choose datastructures
    file.close();
    sort(a.begin(), a.end());
    sort(b.begin(),b.end());

    for(int i=0;i<a.size();i++)res+=abs(a[i]-b[i]); 
    //print outputs
    cout<<res<<endl;
}