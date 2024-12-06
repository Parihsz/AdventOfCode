#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
using namespace std;

int main(){
    ifstream file("inputdata.txt");
    vector<string> grid;
    string line;
    while (getline(file,line))grid.push_back(line);
    //print grid
    for (int i=0;i<grid.size();i++) {
        for (int j=0;j<grid[i].size();j++) {
            cout<<grid[i][j];
        }
        cout<<endl;
    }
    int y=0,x=0; //starting coords
    int dx=0,dy=-1; //direction
    for (int i=0;i<grid.size();i++) {
        for (int j=0;j<grid[i].size();j++) {
            if (grid[i][j] == '^') { //mark starting point.
                y=i; x=j;
                grid[i][j] ='.';
            }
        }
    }
    map<pair<int,int>,bool> visited;
    int res=0;
    int bound_x=grid[0].size(),bound_y=grid.size();
    while(y>=0&&y<grid.size()&&x>=0&&x<grid[0].size()){
        visited[{y,x}]=true;
        int nx=x+dx,ny=y+dy;
        if(ny<0||ny>=bound_y||nx<0||nx>=bound_x){
            break;
        }else if(grid[ny][nx] =='#'){
            //turn right
            int temp=dy;
            dy=dx;
            dx=-temp;
        }else if(grid[ny][nx]=='.'){
            x=nx;
            y=ny;
        }
    }
    cout<<visited.size()<<endl;
}