#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <map>
#include <unordered_map>
#include <unordered_set>
using namespace std;

long long pack_coords_to_number(int x, int y){
    return x*10000+y;
}

int main(){
    ifstream f("inputdata.txt");
    vector<string> lines;
    for(string s; getline(f,s);)lines.push_back(s);

    map<pair<int,int>,char>grid;
    unordered_map<char,vector<pair<int,int>>>a;

    int res=0;

    for (int i=0;i<lines.size();i++){
        for (int j=0;j<lines[i].size();j++){
            if((grid[{i,j}]=
                lines[i][j])!='.'
            )a[lines[i][j]].push_back({i,j});
        }
    }
    
    unordered_set<long long>coords;
    for (auto &kv:a) {
        auto &v=kv.second;
        for (int i=0; i<v.size(); i++){
            for (int j=i+1; j<v.size(); j++){
                int ax=v[i].first,ay=v[i].second,bx=v[j].first,by=v[j].second;
                coords.insert(pack_coords_to_number(bx+(bx-ax),by+(by-ay)));
                coords.insert(pack_coords_to_number(ax+(ax-bx),ay+(ay-by)));
            }
        }
    }

    for (auto &p:coords) {
        int x=p/10000;
        int y=p%10000;
        if(grid.find({x,y})!=grid.end())res++;
    }

    cout<<res<<endl;
}
