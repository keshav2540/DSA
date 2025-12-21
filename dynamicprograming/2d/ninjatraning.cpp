#include <bits/stdc++.h>
using namespace std;
int helper(int day, int last, vector<vector<int>> arr)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, arr[0][i]);
            }
        }
        return maxi;
    }
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = arr[day][i] + helper(day - 1, i, arr);
            maxi = max(point, maxi);
        }
    }
    return maxi;
}
int helper2(int day, int last, vector<vector<int>> &arr, vector<vector<int>> &dp)
{
    if (day == 0)
    {
        int maxi = 0;
        for (int i = 0; i < 3; i++)
        {
            if (i != last)
            {
                maxi = max(maxi, arr[0][i]);
            }
        }
        return maxi;
    }
    if (dp[day][last] != -1)
        return dp[day][last];
    int maxi = 0;
    for (int i = 0; i < 3; i++)
    {
        if (i != last)
        {
            int point = arr[day][i] + helper2(day - 1, i, arr,dp);
            maxi = max(point, maxi);
        }
    }
    return dp[day][last] = maxi;
}
int helper3(int day, int lasti, vector<vector<int>> &arr, vector<vector<int>>&dp)
{
    dp[0][0] = max(arr[0][1], arr[0][2]);
    dp[0][1] = max(arr[0][0], arr[0][2]);
    dp[0][2] = max(arr[0][0], arr[0][1]);
    dp[0][3] = max(arr[0][1], max(arr[0][0], arr[0][2]));
    for (int i = 1; i < arr.size(); i++)
    {
        for (int last = 0; last < 4; last++)
        {
            dp[i][last] = 0;
            for (int j = 0; j < 3; j++)
            {
                if (j != last)
                {
                    int point = arr[i][j] + dp[i - 1][j];
                    dp[i][last] = max(point, dp[i][last]);
                }
            }
        }
    }
    return dp[day][lasti];
}
int maxpointinninjatraning(vector<vector<int>> arr, int n)
{
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper3(n - 1, 3, arr, dp);
}
int maxpointinninjatraningSPACCEOPTIMIZZZE(vector<vector<int>> arr, int n)
{
    vector<int> prev(4, 0);
    prev[0] = max(arr[0][1], arr[0][2]);
    prev[1] = max(arr[0][0], arr[0][2]);
    prev[2] = max(arr[0][0], arr[0][1]);
    prev[3] = max(arr[0][1], max(arr[0][0], arr[0][2]));
    for (int i = 1; i < arr.size(); i++)
    { vector<int> temp(4, 0);
        for (int last = 0; last < 4; last++)
        {
            temp[last] = 0;
            for (int j = 0; j < 3; j++)
            {
                if (j != last)
                {
                    int point = arr[i][j] + prev[j];
                    temp[last] = max(point, temp[last]);
                }
            } 
        }prev=temp;
    }
    return prev[3];
}
int main()
{
    vector<vector<int>> arr = {{1, 2, 5}, {3, 1, 1}, {2, 2, 2}};
    int n = 3;
    cout <<maxpointinninjatraning(arr, n);

    return 0;
}