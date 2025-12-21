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
int sumofsubarray(vector<int> nums)
{
    int ans = 0;
    vector<int> nextsmall = nextsmaller(nums);
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
        cout << (i - presmall) << " " << (nextsmall[i] - i) << " " << ((i - presmall) * (nextsmall[i] - i)) << endl;
        ans += ((i - presmall) * (nextsmall[i] - i))*nums[i];
    }
    return ans;
}
int main()
{
    vector<int> nums = {3,1,2,4};
    cout << sumofsubarray(nums);
    return 0;
}