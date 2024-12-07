#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>
#include <chrono>
using namespace std;

int main() {
    ifstream file("inputdata.txt");
    string line;
    long long res=0;
    auto start = chrono::high_resolution_clock::now();
    while (getline(file, line)) {
        stringstream ss(line);
        string temp;
        vector<long long>nums;
        string n;

        getline(ss,temp,':');
        long long ans;
        ans=stoll(temp); 

        while (ss >>n)nums.push_back(stoll(n));

        int c=pow(2,nums.size()-1);
        bool found=false;

        stack<pair<int, long long>>s;
        s.push({0,nums[0]});
        while(!s.empty()&&!found){
            auto[i,current] =s.top();
            s.pop();
            if (i==nums.size()-1) { 
                if (current==ans) {
                    found=true;
                    res+=ans;
                }
                continue;
            }
            s.push({i+1,current+nums[i+1]}); 
            s.push({i+1,current*nums[i+1]}); 
        }
    }
    auto end = chrono::high_resolution_clock::now();
    auto duration = chrono::duration_cast<chrono::milliseconds>(end - start);
    cout<<res<<endl;
    cout<<"Time: "<<duration.count()<<" milliseconds"<<endl;
    return 0;
}
