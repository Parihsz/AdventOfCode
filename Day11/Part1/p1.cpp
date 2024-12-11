#include <iostream>
#include <map>
#include <fstream>
#include <string>
using namespace std;

int main() {
    ifstream file("inputdata.txt");
    map<long long,long long>stones;
    long long temp;
    while (file>>temp)stones[temp]++;
    file.close();

    for (int b=1;b<=25;b++) {
        map<long long,long long>new_stones;
        for (auto[n,c]:stones) {
            string str=to_string(n);
            int m = str.length()/2;

            if (n==0)new_stones[1]+=c;
            else if(str.length()%2==0) {
                new_stones[stoll(str.substr(0,m))]+=c;
                new_stones[stoll(str.substr(m))]+=c;
            } else {
                new_stones[n*2024]+=c;
            }
        }
        stones=new_stones;
    }

    long long res=0;
    for (auto[n,c]:stones)res+=c;

    cout<<res<<endl;
    return 0;
}