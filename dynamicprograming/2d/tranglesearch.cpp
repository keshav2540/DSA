#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, vector<vector<int>> mat)
{    if(j>=mat[i].size())  return INT32_MAX;
     if(i==mat.size()-1) return mat[i][j];
     int down=mat[i][j]+helper(i+1,j,mat);
     int diag=mat[i][j]+helper(i+1,j+1,mat);
     return min(down ,diag);
    }
int helper2(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{ 
    if(j>=mat[i].size())  return INT32_MAX;
     if(i==mat.size()-1) return dp[i][j]=mat[i][j];
     if(dp[i][j]!=-1) return dp[i][j];
     int down=mat[i][j]+helper(i+1,j,mat);
     int diag=mat[i][j]+helper(i+1,j+1,mat);
     return dp[i][j]= min(down ,diag);
    
}
int helper3(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
   for(int i=0;i<=m;i++){
    dp[n-1][i]=mat[n-1][i];
   }
   for(int i=n-1;i>=0;i--){
    for(int j=i;j>=0;j--){
     int down=mat[i][j]+helper2(i+1,j,mat,dp);
      int diag=mat[i][j]+helper2(i+1,j+1,mat,dp);
         dp[i][j]= min(down ,diag);
    }
   } return dp[0][0];
}
int helperspaceOptimization(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{   vector<int>prev(m+1,0),curr(m+1,0);
      for(int i=0;i<=m;i++){
    prev[i]=mat[n][i];
   }
   for(int i=n-1;i>=0;i--){
    for(int j=i;j>=0;j--){
     int down=mat[i][j]+prev[j];
      int diag=mat[i][j]+prev[j+1];
         curr[j]= min(down ,diag);
    }prev=curr;
   } return prev[0];
}
int tringlepathsum(vector<vector<int>> mat)
{
  
    int n = mat.size();
    int m = mat[n-1].size(); 
     vector<vector<int>> dp(n, vector<int>(m, -1));
    return helperspaceOptimization(n-1, m-1, mat,dp);
}
int main()
{
    vector<vector<int>> mat={{1},{2,3},{3,6,7},{8,9,6,10}};
    cout <<tringlepathsum(mat);
    return 0;
}