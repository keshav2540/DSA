#include <bits/stdc++.h>
using namespace std;
 void generate(int n,string ans,vector<string>&res,int open,int close){
    if(ans.size()==(2*n)) {res.push_back(ans);return ;}
    if(open<n) generate(n,ans+"(",res,open+1,close);
    if(close<open) generate(n,ans+")",res,open,close+1);
 }
int main() {
    vector<string>res;
    int n=3;
    int open=1,close=0;
    string ans="(";
    generate(n,ans,res,open,close);
    for(auto i:res)cout<<i<<endl;
    return 0;
}