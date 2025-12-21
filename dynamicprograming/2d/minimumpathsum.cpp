#include <bits/stdc++.h>
using namespace std;
int helper(int i, int j, vector<vector<int>> mat)
{
    if (i == 0 && j == 0)
        return mat[0][0];
    if (i < 0 || j < 0)
        return 1e9;
    int up = helper(i - 1, j, mat) + mat[i][j];
    int left = helper(i, j - 1, mat) + mat[i][j];
    return min(up, left);
}
int helper2(int i, int j, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    if (i == 0 && j == 0)
        return dp[0][0] = mat[0][0];
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = helper2(i - 1, j, mat,dp) + mat[i][j];
    int left = helper2(i, j - 1, mat,dp) + mat[i][j];
    return dp[i][j] = min(up, left);
}
int helper3(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    dp[0][0] = mat[0][0];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                dp[0][0] = mat[0][0];
            else
            {
                int up = INT_MAX, left = 1e9;
                if (i > 0)
                    up = dp[i - 1][j] + mat[i][j];
                if (j > 0)
                    left = dp[i][j - 1] + mat[i][j];
                dp[i][j] = min(up, left);
            }
        }
    }
    return dp[n][m];
}
int helperspaceOptimization(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp)
{
    vector<int> prev(m+ 1, 0);
    prev[0] = mat[0][0];
    for (int i = 0; i <= n; i++)
    {
        vector<int> temp(m + 1, 0);
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 && j == 0)
                temp[j] = mat[i][j];
            else
            {
                int up = 1e9, left = 1e9;
                if (i > 0)
                    up = prev[j]+mat[i][j] ;
                if (j > 0)
                    left =temp[j - 1]+mat[i][j];
                temp[j] = min(up, left);
            }
        }
        prev = temp;
    }
    return prev[m];
}
int minimumpathsum(vector<vector<int>> mat)
{

    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helperspaceOptimization(n - 1, m - 1, mat, dp);
}
int main()
{
    vector<vector<int>> mat = {{5, 9, 6}, {11, 5, 2}};
    cout << minimumpathsum(mat);
    return 0;
}