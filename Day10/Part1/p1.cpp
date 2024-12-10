#include <iostream>
#include <fstream>
#include <vector>
#include <map>
#include <set>
using namespace std;

int char_to_int(char c) {
    return c-'0';
}

int main() {
    ifstream f("inputdata.txt");
    vector<string> lines;
    for (string s;getline(f,s);)lines.push_back(s);

    map<pair<int,int>,int>grid;
    for(int i=0;i<lines.size();i++) {
        for(int j=0;j<lines[0].size();j++){
            grid[{i,j}]=char_to_int(lines[i][j]);
        }
    }
    vector<pair<int,int>>dir_vecotrs={{-1,0},{1,0},{0,-1},{0,1}};
    int res=0;

    for (auto&[s,v]:grid) {
        if(v==0){
            set<pair<int,int>>valid;
            vector<pair<int,int>>stack={s};
        
            while(!stack.empty()){
                auto[x,y]=stack.back();
                stack.pop_back();
                if (grid[{x,y}]==9) {
                    valid.insert({x,y});
                } else {
                    for(auto[dx,dy]:dir_vecotrs){
                        int nx=x+dx;
                        int ny=y+dy;
                        if (grid.count({nx,ny})&&grid[{nx,ny}]==grid[{x,y}]+1)stack.push_back({nx,ny});
                    }
                }
            }
            res+=valid.size();
        }
    }

    cout<<res<<endl;
    return 0;
}
