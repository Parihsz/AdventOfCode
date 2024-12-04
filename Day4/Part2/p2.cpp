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
    int res= 0;
    for (int i=1;i<g.size()-1;i++) {
        for (int j=1;j<g[0].size()-1;j++) { 
            if (g[i][j] =='A') {
                char t_l=g[i-1][j-1];
                char b_r=g[i+1][j+1];
                char t_r=g[i - 1][j+1];
                char b_l=g[i+1][j-1];
                if ((t_l =='M'&&b_r =='S'||t_l =='S'&&b_r=='M')&&
                    (t_r=='M'&&b_l=='S'||t_r=='S'&&b_l=='M')
                )res++;
            }
        }
    }
    cout<<res<<endl;
}
