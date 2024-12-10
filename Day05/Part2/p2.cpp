#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>
#include <limits>
using namespace std;

int main() {
    ifstream file("inputdata.txt");

    string line;
    int x,y;
    char delim;

    vector<pair<int,int>>rules; 
    vector<vector<int>>updates; 

    while (getline(file,line)&&!line.empty()) {
        int delimiter= line.find('|');
        rules.emplace_back(stoi(line.substr(0,delimiter)),stoi(line.substr(delimiter +1)));
    }
    unordered_map<int, vector<int>>d_map;
    for (auto& [key, value] :rules) {
        d_map[key].push_back(value);
        if (!d_map.count(value))d_map[value] = {};
    }
    while(getline(file,line)){
        if (line.empty())continue;
        vector<int>update;
        int page;
        int j=0;
        for (int i=0;i<line.size();i=j+1) {
            j= line.find(',',i);
            if(j==-1)j=line.size();
            update.push_back(stoi(line.substr(i,j-i)));
            if (j==line.size())break;
        }
        updates.push_back(update); 
    }
    file.close();

    int res=0;

    for (const auto& update:updates) {
        bool violated= false;
        for (int i=0;i<update.size()-1;i++) {
            int current=update[i];
            int next=update[i+1];
            if (d_map.count(current) && d_map.count(next) &&
                find(d_map[current].begin(),
                    d_map[current].end(),next)
                    == 
                    d_map[current].end()
            ){
                violated = true;
                break;
            }
        }
        if(violated){
            vector<int> processed_update=update;
            sort(processed_update.begin(),processed_update.end(),[&](int a, int b) {
                if(d_map.count(a) &&
                    find(d_map[a].begin(),
                        d_map[a].end(), b) 
                        !=
                        d_map[a].end()) {
                    return true;
                }
                return false; 
            });
            res+=processed_update[processed_update.size()/2];
        }
    }
    cout<<res<<endl;

    return 0;
}
