#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector>
#include <sstream>
using namespace std;

int main() {
    ifstream file("inputdata.txt");
    string s;
    string line;
    int res = 0;
    vector<vector<int>> reports;
    while (getline(file,line)) {
        stringstream lineStream(line);
        vector<int> r;
        int l;
        while(lineStream>>l)r.push_back(l);
        reports.push_back(r);
    }
    for (auto& r:reports) {
        bool safe=false;
        for (int i = 0; i < r.size();i++) {
            vector<int> m = r;
            m.erase(m.begin() + i);
            int increase=0;
            int decrease=0;
            bool v = true;
            for (int j=1; j<m.size();j++) {
                if(m[j]>=m[j - 1])decrease++;
                if(m[j]<=m[j - 1]) increase++;
                if(abs(m[j]-m[j - 1])<1||abs(m[j]-m[j-1])>3) {
                    v=false;
                    break;
                }
            }
            if(v&&(increase==0||decrease==0)){
                safe=true;
                break;
            }
        }
        if(safe)res++;
    }
    cout <<res<<endl;
    return 0;
}
