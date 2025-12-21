#include <bits/stdc++.h>
using namespace std;
vector<int> nextsmaller(vector<int> nums)
{
    vector<int> ans(nums.size(), nums.size());
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[i] < nums[s.top()])
        {
            s.pop();
        }
        if (!s.empty())
            ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
vector<int> nextmax(vector<int> nums)
{
    vector<int> ans(nums.size(), nums.size());
    stack<int> s;
    for (int i = nums.size() - 1; i >= 0; i--)
    {
        while (!s.empty() && nums[i] > nums[s.top()])
        {
            s.pop();
        }
        if (!s.empty())
            ans[i] = s.top();
        s.push(i);
    }
    return ans;
}
int sumofsubarraymin(vector<int> nums)
{
    int ans = 0;
    vector<int> nextmaxinum = nextsmaller(nums);
    int presmall;
    stack<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!s.empty() && nums[i] <= nums[s.top()])
        {
            s.pop();
        }
        if (!s.empty())
        {
            presmall = s.top();
        }
        else
            presmall = -1;
        s.push(i);
        ans += ((i - presmall) * (nextmaxinum[i] - i))*nums[i];
    }
    return ans;
}
int sumofsubarraymaxi(vector<int> nums)
{
    int ans = 0;
    vector<int> nextsmall = nextmax(nums);
    int presmall;
    stack<int> s;
    for (int i = 0; i < nums.size(); i++)
    {
        while (!s.empty() && nums[i] >= nums[s.top()])
        {
            s.pop();
        }
        if (!s.empty())
        {
            presmall = s.top();
        }
        else
            presmall = -1;
        s.push(i);
        ans += ((i - presmall) * (nextsmall[i] - i))*nums[i];
    }
    return ans;
}
int sumofrange(vector<int>nums){
     return ( sumofsubarraymaxi(nums)-sumofsubarraymin(nums));
}
int main()
{
    vector<int> nums = {3,1,2,4};
    cout<<sumofsubarraymaxi(nums)<<endl;
    cout<<sumofsubarraymin(nums)<<endl;
    cout<< sumofrange(nums);
    return 0;
}