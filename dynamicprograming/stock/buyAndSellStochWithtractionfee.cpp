#include <bits/stdc++.h>
using namespace std; // buy and sell many times
int helper(int idx, bool buy, int fees, vector<int> &arr)
{
    if (idx == arr.size())
        return 0;
    int profit = 0;
    if (buy)
    {
        profit = max(-arr[idx] + helper(idx + 1, 0,fees, arr), helper(idx + 1, 1,fees, arr));
    }
    else
    {
        profit = max(arr[idx]-fees+ helper(idx + 1, 1,fees, arr), helper(idx + 1, 0,fees, arr));
    }
    return profit;
}
int helper2(int idx, bool buy, int fees, vector<int> &arr, vector<vector<int>> &dp)
{
    if (idx == arr.size())
        return 0;
    if (dp[idx][buy] != -1)
        return dp[idx][buy];
    int profit = 0;
    if (buy)
    {
        profit = max(-arr[idx] + helper2(idx + 1, 0,fees, arr, dp), helper2(idx + 1, 1,fees, arr, dp));
    }
    else
    {
        profit = max(arr[idx]-fees + helper2(idx + 1, 1,fees, arr, dp), helper2(idx + 1, 0,fees, arr, dp));
    }
    return dp[idx][buy] = profit;
}
int helper3(int idx, bool buy, int fees, vector<int> &arr, vector<vector<int>> &dp)
{
    int n = arr.size();
    int idex = n - 1;
    dp[n][0] = dp[n][1] = 0;
    for (int i = idex; i >= 0; i--)
    {
        for (int j = 0; j <= buy; j++)
        {
            int profit = 0;
            if (j)
            {
                profit = max(-arr[i] + dp[i + 1][0], dp[i + 1][1]);
            }
            else
            {
                profit = max(arr[i]-fees + dp[i + 1][1], dp[i + 1][0]);
            }
            dp[i][j] = profit;
        }
    }
    return dp[idx][buy];
}
int helper4(int idx, bool buy, int fees, vector<int> &arr, vector<vector<int>> &dp)
{
    vector<int> ahead(2, 0), curr(2, 0);
    int n = arr.size();
    int idex = n - 1;
    ahead[0] = ahead[1] = 0;
    for (int i = idex; i >= 0; i--)
    {
        for (int j = 0; j <= buy; j++)
        {
            int profit = 0;
            if (j)
            {
                profit = max(-arr[i] + ahead[0], ahead[1]);
            }
            else
            {
                profit = max(arr[i]-fees + ahead[1], ahead[0]);
            }
            curr[j] = profit;
        }
        ahead = curr;
    }
    return ahead[buy];
}
int helper5(int idx, bool buy, int fees, vector<int> arr, vector<vector<int>> &dp)
{
    vector<int> ahead(2, 0), curr(2, 0);
    int n = arr.size();
    int idex = n - 1;
    int aheadbuy, aheadsell, currsell, currbuy;
    aheadsell = aheadbuy = 0;
    currsell = currbuy = 0;
    for (int i = idex; i >= 0; i--)
    {
        for (int j = 0; j <= buy; j++)
        {
            int profit = 0;
            if (j)
            {
                profit = max(-arr[i] + aheadsell, aheadbuy);
            }
            else
            {
                profit = max(arr[i]-fees + aheadbuy, aheadsell);
            }
            j ? currbuy = profit : currsell = profit;
        }
        aheadbuy = currbuy;
        aheadsell = currsell;
    }
    return aheadbuy;
}
int maxprofitwithtransjectionfee(vector<int> &arr, int fee)
{
    vector<vector<int>> dp(arr.size() + 1, vector<int>(2, -1));
    return helper5(0, 1, fee, arr,dp);
}
int main()
{
    vector<int> arr = {7, 1, 5, 3, 6, 4};
    vector<int> arr1 = {1, 2, 1, 2, 1, 2, 1, 1, 5, 1};
    cout << maxprofitwithtransjectionfee(arr, 2) << endl;
    cout << maxprofitwithtransjectionfee(arr1, 1) << endl;
    return 0;
}