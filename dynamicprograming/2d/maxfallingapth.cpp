// we can start on r0w=0and any position of col and end in col=lastcol and anyposoin of roe
#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, vector<vector<int>> &mat)
{
    if (j >= mat[0].size() || j < 0)
        return -1e9;
    if (i == 0)
        return mat[i][j];
    int up = helper(i - 1, j, mat) + mat[i][j];
    int left = helper(i - 1, j - 1, mat) + mat[i][j];
    int right = helper(i - 1, j + 1, mat) + mat[i][j];
    return max(up, max(right, left));
}
int helper2(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (j >= mat[0].size() || j < 0)
        return -1e9;
    if (i == 0)
        return dp[i][j] = mat[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = helper2(i - 1, j, mat,dp) + mat[i][j];
    int left = helper2(i - 1, j - 1, mat,dp) + mat[i][j];
    int right = helper2(i - 1, j + 1, mat,dp) + mat[i][j];
    return dp[i][j] = max(up, max(right, left));
}
int helper3(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    for (int i = 0; i < m; i++)
    {
        dp[0][i] = mat[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int up = -1e9, left = -1e9, right = -1e9;
            up = dp[i - 1][j] + mat[i][j];
            if (j > 0)
                left = dp[i - 1][j - 1] + mat[i][j];
            if (j < mat.size())
                right = dp[i - 1][j + 1] + mat[i][j];
            dp[i][j] = max(up, max(left, right));
        }
    }
    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, dp[n - 1][i]);
    }
    return maxi;
}
int helperspaceOptimization(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    vector<int> prev(m + 1, 0);
    for (int i = 0; i < m; i++)
    {
        prev[i] = mat[0][i];
    }
    for (int i = 1; i < n; i++)
    {
        vector<int> temp(m + 1, 0);
        for (int j = 0; j < n; j++)
        {
            int up = -1e9, left = -1e9, right = -1e9;
            up = prev[j] + mat[i][j];
            if (j > 0)
                left = prev[j - 1] + mat[i][j];
            if (j < mat.size())
                right = prev[j + 1] + mat[i][j];
            temp[j] = max(up, max(left, right));
        }
        prev = temp;
    }
    int maxi = 0;
    for (int i = 0; i < m; i++)
    {
        maxi = max(maxi, prev[i]);
    }
    return maxi;
}
int maximumpathsum(vector<vector<int>> mat)
{

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    int maxi = INT32_MIN;
    // for(int i=0;i<m;i++){
    //     maxi=max(maxi,helper2(n-1,i,mat,dp));
    // } return maxi;
    return helperspaceOptimization(n, m, mat, dp);
}
int main()
{
    vector<vector<int>> mat = {{1, 1, 100}, {2, 2, 3}, {3, 10, 2}};
    cout << maximumpathsum(mat);
    return 0;
}
