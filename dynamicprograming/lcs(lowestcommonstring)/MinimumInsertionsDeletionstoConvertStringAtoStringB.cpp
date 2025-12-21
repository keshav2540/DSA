#include <bits/stdc++.h>
using namespace std;
int  helper3(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
     for(int i=0;i<=ind1;i++)dp[i][0]=0;
     for(int j=0;j<=ind2;j++)dp[0][j]=0;
     for(int i=1;i<=ind1;i++){
          for(int j=1;j<=ind2;j++){
          if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
          else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
           }
     }
    return dp[ind1][ind2];
}

int longestcommonstringprint_with_lenght(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    // return n-helper3(n,m,s1,s2,dp)+m-helper3(n,m,s1,s2,dp);
     return (n+m-(2*helper3(n,m,s1,s2,dp)));
}

int main() {
 cout<<longestcommonstringprint_with_lenght("abcd","anc")<<endl;
 // abcd to delete bd and insert n ; total 3
    return 0;
}