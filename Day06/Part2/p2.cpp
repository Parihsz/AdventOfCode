#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <map>
#include <set>
using namespace std;
//hahaha i love advent of code unotpimized code!!!
bool is_a_loop(vector<string>grid, int x,int y, int dy,int dx){
    int bound_x=grid[0].size(),bound_y=grid.size();
    set<pair<pair<int, int>,pair<int, int>>>visited; //we need to track direction here too. 
    while(y>=0&&y<bound_y&&x>=0&&x<bound_x){
        //check if this is a repeating point in the same direction
        if (!visited.insert({{y, x}, {dy, dx}}).second){
            return true; // Loop detected
        }
        int nx=x+dx,ny=y+dy;
        if(ny<0||ny>=bound_y||nx<0||nx>=bound_x){
            return false;
        }else if(grid[ny][nx] =='#'){
            //turn right
            int temp=dy;
            dy=dx;
            dx=-temp;
        }else if(grid[ny][nx]=='.'||grid[ny][nx]=='A'){
            x=nx;
            y=ny;
        }
    }
    return false;
}

int main(){
    ifstream file("inputdata.txt");
    vector<string> grid;
    string line;
    while (getline(file,line))grid.push_back(line);

    int y=0,x=0; //starting coords
    int dx=0,dy=-1; //direction
    for (int i=0;i<grid.size();i++) {
        for (int j=0;j<grid[i].size();j++) {
            if (grid[i][j] == '^') { //mark starting point.
                y=i; x=j;
                grid[i][j] ='A';//set it to a random char so we dont randomly turn it into a wall
            }
        }
    }
    int res=0;
    for (int i=0;i<grid.size();i++) {
        for (int j=0;j<grid[i].size();j++) {
            if(grid[i][j]=='.'){
                grid[i][j]='#';
                if(is_a_loop(grid,x,y,dy,dx)){
                    res++;
                }
                grid[i][j]='.';
            }
        }
    }

    cout<<res<<endl;
}