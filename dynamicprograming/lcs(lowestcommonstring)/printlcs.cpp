//based on shrink concept and shifting in dp
// this is for subhseqence not substring(conjucated element) 
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
     string ans="";
     int lenght=dp[ind1][ind2];
     for(int i=0;i<lenght;i++){
        ans+="$";
     }
     int index=lenght-1;
    while(ind1>0 && ind2>0){
        if(s1[ind1-1]==s2[ind2-1]){
          ans[index--]=s1[ind1-1];
          ind1--;
          ind2--;
        }
        else if(dp[ind1][ind2-1]>dp[ind1-1][ind2]){
            ind2--;
        }
        else ind1--;
    }
    cout<<ans<<endl;
 return lenght;
}

int longestcommonstringprint_with_lenght(string s1,string s2){
    int n=s1.length();
    int m=s2.length();
    vector<vector<int>>dp(n+1,vector<int>(m+1,0));
    return helper3(n,m,s1,s2,dp);
}

int main() {
 cout<<longestcommonstringprint_with_lenght("acd","ced")<<endl;
 cout<<longestcommonstringprint_with_lenght("bbabcbcab","bacbcbabb")<<endl;//it return palindrome of longest subseqence
 cout<<longestcommonstringprint_with_lenght("adebc","dcadb");
    return 0;
}