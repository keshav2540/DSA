#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, vector<vector<int>> mat)
{   if(i>0&& j>0&&i<=mat.size()&& j<=mat[0].size()&& mat[i][j]==-1) return 0;
    if (i == 0 && j == 0)
        return 1;
    if (i < 0 || j < 0)
        return 0;
    int up = helper(i - 1, j, mat);
    int left = helper(i, j - 1, mat);
    return up + left;
}
int helper2(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{   if(i>0&& j>0&&i<=mat.size()&& j<=mat[0].size()&& mat[i][j]==-1) dp[i][j]=0;
    if (i == 0 && j == 0)
        return dp[0][0] = 1;
    if (i < 0 || j < 0)
        return 0;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = helper2(i - 1, j, mat,dp);
    int left = helper2(i, j - 1, mat,dp);
    return dp[i][j] = up + left;
}
int helper3(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
     dp[0][0] = 1;
    for(int i=0;i<=n;i++){
        for(int j=0;j<=m;j++){
            if(i>0&& j>0&&i<=mat.size()&& j<=mat[0].size()&& mat[i][j]==-1) dp[i][j]=0;
            else if(i==0&&j==0) dp[0][0]=1;
            else{
                int up=0,left=0;
                if(i>0) up=dp[i-1][j];
                if(j>0)left=dp[i][j-1];
                dp[i][j]=up+left;
            }

        }
    } return dp[n][m];
}
int helperspaceOptimization(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{   vector<int>prev(m+1,0);
     prev[0] = 1;
    for(int i=0;i<=n;i++){ 
        vector<int>temp(m+1,0);
        for(int j=0;j<=m;j++){
            if(i==0&&j==0) temp[0]=1;
            else if( mat[i][j]==-1) temp[j]=0;
            else{
                int up=0,left=0;
               temp[j]=prev[j]+(j>0?temp[j-1]:0);
            }
        }prev=temp;
    } return prev[m];
}
int uniquepath(vector<vector<int>> mat)
{
  
    int n = mat.size();
    int m = mat[0].size(); 
     vector<vector<int>> dp(n, vector<int>(m, -1));
    return helperspaceOptimization(n - 1, m - 1, mat,dp);
}
int main()
{
    vector<vector<int>> mat(3, vector<int>(3, 0));
    mat[1][1]=-1;
    cout << uniquepath(mat);
    return 0;
}