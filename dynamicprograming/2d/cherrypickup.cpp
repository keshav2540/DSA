#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j1, int j2, int n, int m, vector<vector<int>> mat)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;
    if (i == n - 1)
    {
        if (j1 == j2)
            return mat[i][j1];
        else
            return mat[i][j1] + mat[i][j2];
    }
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {   int value=0;
            if (j1 == j2) value= mat[i][j1];
            else value=  mat[i][j1] + mat[i][j2];   
            value+=helper(i + 1, j1 + dj1, j2 + dj2, n, m, mat);
            maxi=max(value,maxi);
        }
    }
    return maxi;
}
int helper2(int i, int j1, int j2, int n, int m, vector<vector<int>> mat, vector<vector<vector<int>>> &dp)
{
    if (j1 < 0 || j1 >= m || j2 < 0 || j2 >= m)
        return -1e8;
    if (i == n - 1)
    {
        if (j1 == j2)
            return dp[i][j1][j2]=mat[i][j1];
        else
            return dp[i][j1][j2]=mat[i][j1] + mat[i][j2];
    }
    if(dp[i][j1][j2]!=-1)return dp[i][j1][j2];
    int maxi = -1e8;
    for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {   int value=0;
            if (j1 == j2) value= mat[i][j1];
            else value=  mat[i][j1] + mat[i][j2];   
            value+=helper(i + 1, j1 + dj1, j2 + dj2, n, m, mat);
            maxi=max(value,maxi);
        }
    }
    return dp[i][j1][j2]=maxi;
}
int helper3(int i, int j1, int j2, int n, int m, vector<vector<int>> mat, vector<vector<vector<int>>> &dp)
{
  for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
        if(i==j)dp[n-1][i][j]=mat[n-1][j];
        else dp[n-1][i][j]=mat[n-1][j]+mat[n-1][i];
    }
  }
  for(int i=n-2;i>=0;i--){
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            int maxi=-1e8;
     for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {   int value=0;
            if (j1 == j2) value= mat[i][j1];
            else value=mat[i][j1] + mat[i][j2]; 
            if(j1+dj1 >= 0 && j1+dj1<m && j2+dj2 >= 0 && j2+dj2<m) value+=dp[i + 1][j1 + dj1][j2 + dj2];
            else  value +=-1e8 ;   
            maxi=max(value,maxi);
        }
    }
     dp[i][j1][j2]=maxi;
        }
    }
  } return dp[0][0][m-1];
}
int helperspaceOptimization(int i, int j1, int j2, int n, int m, vector<vector<int>> mat, vector<vector<vector<int>>> &dp)
{  vector<vector<int>>prev(m,vector<int>(m,0));
  vector<vector<int>>curr(m,vector<int>(m,0));
    for(int i=0;i<m;i++){
    for(int j=0;j<m;j++){
        if(i==j)prev[i][j]=mat[n-1][j];
        else prev[i][j]=mat[n-1][j]+mat[n-1][i];
    }
  }
  for(int i=n-2;i>=0;i--){
    for(int j1=0;j1<m;j1++){
        for(int j2=0;j2<m;j2++){
            int maxi=-1e8;
     for (int dj1 = -1; dj1 <= 1; dj1++)
    {
        for (int dj2 = -1; dj2 <= 1; dj2++)
        {   int value=0;
            if (j1 == j2) value= mat[i][j1];
            else value=mat[i][j1] + mat[i][j2]; 
            if(j1+dj1 >= 0 && j1+dj1<m && j2+dj2 >= 0 && j2+dj2<m) value+=prev[j1 + dj1][j2 + dj2];
            else  value +=-1e8 ;   
            maxi=max(value,maxi);
        }
    }
     curr[j1][j2]=maxi;
        }
    }prev=curr;
  } return prev[0][m-1];
    
}
int maxcherrypick(vector<vector<int>> mat)
{

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m,-1)));
    return helperspaceOptimization(0,0,n-1,n, m, mat,dp);
}
int main()
{
    vector<vector<int>> mat = {{2, 3, 1, 2}, {3, 4, 2, 2}, {5, 6, 3, 5}};
    cout << maxcherrypick(mat);
    return 0;
}