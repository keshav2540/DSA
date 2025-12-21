#include <bits/stdc++.h>
using namespace std;
bool ispalindrome(string s){
    string s2=s;
    reverse(s2.begin(),s2.end());
    return s==s2;
}
bool ispalindrome(int i,int j,string s){
    while(i<j){
        if(s[i]!=s[j])return false;
        i++;
        j--;
    }return true;
}
int helper(int i,string s){
    if(i==s.size()) return 0;
    string temp="";
    int min_cost=1e9;
   for(int j=i;j<s.size();j++){
    temp+=s[j];
    if(ispalindrome(temp)) {int cost= 1+helper(j+1,s);
       min_cost=min(min_cost,cost);}
   } return min_cost;}

int helper2(string s){
    int n=s.size();
    vector<int>dp(n+1,0);
    dp[n]=0;
    for(int i=n-1;i>=0;i--){
      int min_cost=1e9;
      for(int j=i;j<s.size();j++){
       if(ispalindrome(i,j,s)) {int cost= 1+dp[j+1];
       min_cost=min(min_cost,cost);}
   }
    dp[i]=min_cost;
}
   return dp[0];
    }
int minpartition(string s){
    return helper(0,s)-1;
}

int main() {
    string s="bababcbadcede";
    cout<<minpartition(s);
    return 0;
}