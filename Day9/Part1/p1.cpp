#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int char_to_int(char c) {
    return c-'0';
}

int main(){
    ifstream file("inputdata.txt");
    string line;
    file>>line;
    file.close();
    
    vector<int> l;
    int id=0;
    
    bool a=true;
    for (int i=0;i<line.size();i++){
        int len=char_to_int(line[i]);
        if(a){
            for(int b=0;b<len;b++)l.push_back(id);
            id++;
        }else{
            for(int b=0;b<len;b++)l.push_back(-1);
        }
        a=!a;
    }
    while(true){
        //pointer1=left
        //pointer2=right
        int p1=-1;
        for (int i=0;i<l.size();i++) {
            if (l[i]==-1) {
                p1=i;
                break;
            }
        }
        if(p1==-1)break;
        int p2=-1;
        for (int i=l.size()-1;i>=0;i--) {
            if (l[i]!=-1) {
                p2=i;
                break;
            }
        }
        if (p1<p2) {
            l[p1]=l[p2];
            l[p2]=-1;
        }else{break;}
    }
    
    long long res=0;
    for(int i=0;i<l.size();i++)if (l[i]!=-1)res+=i*l[i];

    cout<<res<<endl;
    return 0;
}
