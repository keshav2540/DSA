//based on shrink concept and shifting in dp
#include <bits/stdc++.h>
using namespace std;
// int helper(int ind1,int ind2,string s1,string s2){
//     if(ind1<0||ind2<0){
//         return 0;
//     }
//     if(s1[ind1]==s2[ind2]) return 1+helper(ind1-1,ind2-1,s1,s2);
//     else return max(helper(ind1,ind2-1,s1,s2),helper(ind1-1,ind2,s1,s2));
// }
int helpershift(int ind1,int ind2,string s1,string s2){//shifting in dp pass original size not after -1
    if(ind1==0||ind2==0){// in shifting enhance dp size
        return 0;
    }
    if(s1[ind1-1]==s2[ind2-1]) return 1+helpershift(ind1-1,ind2-1,s1,s2);
    else return max(helpershift(ind1,ind2-1,s1,s2),helpershift(ind1-1,ind2,s1,s2));
}
int  helper2(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
     if(ind1==0||ind2==0){
        return 0;
    }
    if(dp[ind1][ind2]!=0) return dp[ind1][ind2];
    if(s1[ind1-1]==s2[ind2-1]) return dp[ind1][ind2]= 1+helper2(ind1-1,ind2-1,s1,s2,dp);
    else return dp[ind1][ind2]=max(helper2(ind1,ind2-1,s1,s2,dp),helper2(ind1-1,ind2,s1,s2,dp));
}
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
int  helperspaceoptimize(int ind1,int ind2,string s1,string s2,vector<vector<int>>&dp){
    vector<int>prev(ind2+1,0),curr(ind2+1,0);
     for(int j=0;j<=ind2;j++)prev[j]=0;
     prev[0]=0;
     for(int i=1;i<=ind1;i++){
          for(int j=1;j<=ind2;j++){
          if(s1[i-1]==s2[j-1]) curr[j]=1+prev[j-1];
          else curr[j]=max(curr[j-1],prev[j]);
           }prev=curr;
     }
 return prev[ind2];
}
int longestcommonstring(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    return helperspaceoptimize(n,m,s1,s2,dp);
}

int main() {
 cout<<longestcommonstring("acd","ced")<<endl;
 cout<<longestcommonstring("adebc","dcadb");
    return 0;
}