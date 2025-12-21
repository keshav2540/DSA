#include <bits/stdc++.h>
using namespace std;
int countpalindromesubseq(string s){
    int n=s.size();
    vector<vector<long long>>dp(n,vector<long long>(n,0));
    for(int i=0;i<n;i++){
        dp[i][i]=1;//all single number is palindrone;
    }
    for(int len=2;len<=n;len++){
      for(int i=0;i+len-1<n;i++){
     int j=i+len-1;
     if(s[i]==s[j]){
        dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
     }
     else dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
      }   
    } return dp[0][n-1];
}

int main() {
    string s="abc";
    cout<<countpalindromesubseq(s);
    return 0;
}