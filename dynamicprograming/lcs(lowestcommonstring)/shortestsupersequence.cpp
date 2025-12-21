#include <bits/stdc++.h>
using namespace std;
int  helper(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
     for(int i=0;i<=ind1;i++)dp[i][0]=0;
     for(int j=0;j<=ind2;j++)dp[0][j]=0;
     for(int i=1;i<=ind1;i++){
          for(int j=1;j<=ind2;j++){
          if(s1[i-1]==s2[j-1]) dp[i][j]=1+dp[i-1][j-1];
          else dp[i][j]=max(dp[i][j-1],dp[i-1][j]);
           }
     }
     int length=dp[ind1][ind2];
     string ans="";
    while(ind1>0 && ind2>0){
        if(s1[ind1-1]==s2[ind2-1]){
          ans+=s1[ind1-1];
          ind1--;
          ind2--;
        }
        else if(dp[ind1][ind2-1]>dp[ind1-1][ind2]){
            ans+=s2[ind2-1];
            ind2--;
        }
        else {ans+=s1[ind1-1];
            ind1--;
        }
    }
    while(ind1>0){ans+=s1[ind1-1];ind1--;}
    while(ind2>0){ans+=s2[ind2-1];ind2--;}
    reverse(ans.begin(),ans.end());
    cout<<ans<<endl;
 return s1.size()+s2.size()-length;
}

int shortestsuperseqence(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    return helper(n,m,s1,s2,dp);
}

int main() {
 cout<<shortestsuperseqence("brute","groot")<<endl;
    return 0;
}