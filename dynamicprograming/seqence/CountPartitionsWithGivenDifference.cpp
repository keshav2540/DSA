// change trhisproblem to other problem this problem is give a array and divided array in two part both parts diff is D and one part is brether than otner part always;
//  we change this( totalsum-D)/2 ,which array sum is equal to this find number of these arr which sum isequal to this
#include <bits/stdc++.h>
using namespace std;
int helper(int n, int target, vector<int> &arr)
{
    if (n == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    return (helper(n - 1, target, arr) + (target >= arr[n] ? helper(n - 1, target - arr[n], arr) : 0));
}
int helper2(int n, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    if (n == 0)
    {
        if (target == 0 && arr[0] == 0)
            return 2;
        if (target == 0 || arr[0] == target)
            return 1;
        return 0;
    }
    if (dp[n][target] != 0) return dp[n][target];
    return dp[n][target] = (helper2(n - 1, target, arr, dp) + (target >= arr[n] ? helper2(n - 1, target - arr[n], arr, dp) : 0));
}
int helper3(int n, int target, vector<int> &arr, vector<vector<int>> &dp)
{   if(arr[0]==0)dp[0][0]=2;
    else dp[0][0]=1;
    if(arr[0]!=0&& target>=arr[0])dp[0][arr[0]]=1;
    for (int i = 1; i <= n; i++)
    {
        for (int k = 0; k <= target; k++)
        {
            dp[i][k] = ((dp[i - 1][k]) + (k >= arr[i] ? dp[i - 1][k - arr[i]] : 0));
        }
    }
    return dp[n][target];
}
int helperSpaceOptimization(int n, int target, vector<int> &arr, vector<vector<int>> &dp)
{
    vector<int> prev(1 + target, 0), curr(1 + target, 0);
    prev[0] = curr[0] = 1;
    prev[arr[0]] = 1;
    if(arr[0]==0)prev[0]=2;
    for (int i = 1; i <= n; i++)
    {
        for (int k=0; k <= target; k++)
        {
            curr[k] = ((prev[k]) + (k >= arr[i] ? prev[k - arr[i]] : 0));
        }
        prev = curr;
    }
    return prev[target];
}
int SumIspossible(vector<int> &arr, int diff)
{
    int n = arr.size();
    int totalsum = 0;
    for (int i = 0; i < n; i++)
        totalsum += arr[i];
    int newtarget = (totalsum - diff) / 2;
    vector<vector<int>> dp(n, vector<int>(newtarget + 1, 0));
    if ((totalsum - diff) % 2 != 0||(totalsum - diff)<0)
        return 0;
    return helperSpaceOptimization(n - 1, newtarget, arr,dp);
}
int main()
{
    vector<int> arr = {1, 1, 2, 3};
    vector<int> arr1 = {1, 2, 3, 4};
    vector<int> arr2 = {0,0,1}; 
    cout << SumIspossible(arr, 1)<< endl;
    cout << SumIspossible(arr1, 0)<< endl;
    cout << SumIspossible(arr2, 1)<< endl;
    return 0;
}