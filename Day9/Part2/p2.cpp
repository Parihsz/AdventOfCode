#include <iostream>
#include <fstream>
#include <vector>
#include <string>

using namespace std;

int char_to_int(char c) {
    return c-'0';
}

int main() {
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
    
    int m=id-1;

    for(int f=m;f>=0;f--){
        int p1=-1;
        int p2=-1;

        for(int i=0;i<(int)l.size();i++){
            if(l[i]==f){
                if(p1==-1)p1=i;p2=i;
            }
        }
        
        if(p1==-1) continue; 
        int len=p2-p1+1;

        int s=-1,c=0,st=-1;

        for(int i=0;i<p1;i++){
            if(l[i]==-1){
                c++;
                if(st==-1)st=i;
                if(c==len){
                    s=st;
                    break;
                }
            }else{
                c=0;
                st=-1;
            }
        }
        if(s==-1)continue;

        for(int i=p1;i<=p2;i++)l[i]=-1;
        for(int i=s;i<s+len;i++)l[i]=f;
    }

    long long res=0;

    for(int i=0;i<l.size();i++)if(l[i]!=-1)res+=i*l[i];

    cout<<res<<endl;
}
