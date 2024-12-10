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

int gcd(int a,int b) {
    while(b){
        int t=b;
        b=a%b;
        a=t;
    }
    return a;
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
            if((grid[{i,j}]=lines[i][j])!='.')a[lines[i][j]].push_back({i,j});
        }
    }
    
    unordered_set<long long>coords;
    for (auto &i:a) {
        auto &v=i.second;
        for (int i=0; i<v.size(); i++){
            for (int j=i+1; j<v.size(); j++){
                int ax=v[i].first,ay=v[i].second,bx=v[j].first,by=v[j].second;
                int dx=bx-ax,dy=by-ay;
                
                int g=gcd(abs(dx),abs(dy));
                int ny=dy/g,nx=dx/g;

                int m=max(lines.size(),lines[0].size());

                for(int k=1;k<=m;k++){
                    coords.insert(pack_coords_to_number(ax+k*nx,ay+k*ny));
                    coords.insert(pack_coords_to_number(bx-k*nx,by-k*ny));
                }
                coords.insert(pack_coords_to_number(ax,ay));
                coords.insert(pack_coords_to_number(bx,by));
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
