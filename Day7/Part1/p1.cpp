#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include <cmath>
#include <stack>
using namespace std;

int main() {
    ifstream file("inputdata.txt");
    string line;
    long long res=0;

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
    cout<<res<<endl;
    return 0;
}
