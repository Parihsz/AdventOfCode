#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main(){
    ifstream file("inputdata.txt");
    string s;
    string line;
    int res = 0;
    //parse inputs
    while (getline(file,line)){
        istringstream iss(line);
        vector<int>r;
        int n;
        while(iss>>n)r.push_back(n);
        bool safe=true; //report safety flag
        int increase=0;
        int decrease=0; //init increasing/decreasing vectors(0=false,1=true)
        for(int i=0;i<r.size()-1;i++){
            int d=r[i+1]-r[i]; //cache the diff
            if(d==0||abs(d)>3){
                safe=false;
                break;
            }
            if(d>0)decrease++;
            if(d<0)increase++;
        }
        if (safe&&(increase==0||decrease==0))res++;
    }
    file.close();
    cout<<res<<endl;
}