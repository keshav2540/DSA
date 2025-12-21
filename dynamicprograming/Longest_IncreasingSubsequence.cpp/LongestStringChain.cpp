#include <bits/stdc++.h>
using namespace std;
bool comp(string &s1,string &s2){
    return s1.size()<s2.size();
}
bool compare(string s1,string s2){
     if(s1.size()!=s2.size()+1)return false;
     int first=0;
     int second=0;
     while(first<s1.size()){
        if(s1[first]==s2[second]){
            first++;
            second++;
        }
        else first++;
     }
    if(first==s1.size()&& second==s2.size()) return true;
    return false; 
}
int lcs(int n,vector<string>&arr){
     sort(arr.begin(),arr.end(),comp);
    int lcs=1;
    vector<int>dp(n,1);       
    for(int i=0;i<n;i++){
        for(int j=0;j<i;j++){
            if(compare(arr[i],arr[j])&& dp[i]<dp[j]+1){
                dp[i]=dp[j]+1;
                lcs=dp[i];
            }
            lcs=max(lcs,dp[i]);
        }
    }
     return lcs;
}
int main() {
 vector<string>arr={"a","b","ba","bda","bca","bdca"};
 cout<<lcs(6,arr);
    return 0;
}