#include <iostream>
#include <fstream>
#include <vector>
#include <string>
using namespace std;

int main() {
    ifstream file("inputdata.txt");
    vector<string> g;
    string line;
    while(getline(file, line))g.push_back(line);
    file.close();
    string target= "XMAS";
    int dir_vectors[8][2]={{0,1},{0,-1},{1,0},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}};
    int res=0;
    for (int i=0;i<g.size();i++){
        for (int j=0;j<g[0].size();j++) {
            if (g[i][j] ==target[0]) {
                for (int d=0;d<8;d++) { 
                    int x = i, y = j, k;
                    for (k=0;k<target.size();k++) {
                        int nx=x+k*dir_vectors[d][0];
                        int ny=y+k*dir_vectors[d][1];
                        if (nx<0|| 
                            ny<0|| 
                            nx>=g.size()|| 
                            ny>=g[0].size()||
                            g[nx][ny]!=
                            target[k]
                        )break;
                    }
                    if (k==target.size())res++;
                }
            }
        }
    }
    cout<<res<<endl;
}
