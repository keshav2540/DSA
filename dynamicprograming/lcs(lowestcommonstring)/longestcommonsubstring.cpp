#include <bits/stdc++.h>
using namespace std;
int  helper3(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
    int length=0;
     for(int i=0;i<=ind1;i++)dp[i][0]=0;
     for(int j=0;j<=ind2;j++)dp[0][j]=0;
     for(int i=1;i<=ind1;i++){
          for(int j=1;j<=ind2;j++){
          if(s1[i-1]==s2[j-1]){ dp[i][j]=1+dp[i-1][j-1];
          length=max(length,dp[i][j]);}
          else dp[i][j]=0;
           }
     }
 return length;
}

int longestcommon_substring_length(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    return helper3(n,m,s1,s2,dp);
}
int main(){
cout<<longestcommon_substring_length("abdefght","abcdefght");
}