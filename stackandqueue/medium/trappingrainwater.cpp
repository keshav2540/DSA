#include <bits/stdc++.h>
using namespace std;
vector<int> prefix(vector<int> nums)
{
    vector<int> ans(nums.size(), -1);
    ans[0] = nums[0];
    for (int i = 1; i < nums.size(); i++)
    {
        ans[i] = max(ans[i - 1], nums[i]);
    }
    return ans;
}
vector<int> suffix(vector<int> nums)
{
    vector<int> ans(nums.size(), -1);
    ans[nums.size() - 1] = nums[nums.size() - 1];
    for (int i = nums.size() - 2; i >= 0; i--)
    {
        ans[i] = max(ans[i + 1], nums[i]);
    }
    return ans;
}
int trapwater(vector<int> nums)
{
    int ans = 0;
    vector<int> PREFIX = prefix(nums);
    vector<int> SUFFIX = suffix(nums);
    for (int i = 0; i < nums.size(); i++)
    {
        ans += min(PREFIX[i], SUFFIX[i]) - nums[i];
    }
    return ans;
}
int mostoptimal(vector<int> nums)
{
    int leftmax = 0, rightmax = 0, total = 0, l = 0, r = nums.size() - 1;
    while (l < r)
    {
        if (nums[l] <= nums[r])
        {
            if (leftmax > nums[l])
                total += leftmax - nums[l];
            else
                leftmax = nums[l];
            l++;
        }
        else
        {
            if (rightmax > nums[r])
                total += rightmax - nums[r];

            else
                rightmax = nums[r];
            r--;
        }
    }
    return total;
}
int main()
{
    vector<int> nums = {0, 1, 0, 2, 1, 0, 1, 3, 2, 1, 2, 1};
    cout << mostoptimal(nums);
    return 0;
}