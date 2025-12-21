#include <bits/stdc++.h>
using namespace std;
//this problem is same as countpatition
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
int SumIspossiblewithdiff(vector<int> &arr, int diff)
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
int targetsum(vector<int>&arr,int target){
    return SumIspossiblewithdiff(arr,target);
}
int main() {
    vector<int>arr={1,2,3,1};// assign all element sign+ adn - and resulttant is targe count number of array 
    cout<<SumIspossiblewithdiff(arr,3);
    return 0;
}