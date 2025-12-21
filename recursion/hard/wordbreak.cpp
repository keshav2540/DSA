#include <bits/stdc++.h>
using namespace std;
bool solve(int index,string &s,unordered_set<string>&dict,vector<int>&dp){
    int n=s.length();
    if(index==n)return true;
    if(dp[index]!=-1) return dp[index];
    string temp="";
    for(int i=index;i<n;i++){
        temp+=s[i];
        if(dict.count(temp)){// like find return itreator count returm 0\1
           if(solve(i+1,s,dict,dp)){
            return dp[index]=true;
           }
        }
    } 
    return dp[index]=false;
}
int main() {
    string s="takeyouforward";
    vector<string>worddict={"take","forward","u","you"};
    unordered_set<string>dict(worddict.begin(),worddict.end());
    vector<int>dp(s.size(),-1);
    cout<<solve(0,s,dict,dp);
    return 0;
}