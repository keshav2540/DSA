#include <bits/stdc++.h>
using namespace std;

int findpeak(vector<int> nums)
{
    int end = nums.size() - 2;
    int st = 1;
    if (end == 0)
        return nums[0];
    int peak = -1;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid - 1] < nums[mid] && nums[mid + 1] < nums[mid])
            peak = max(peak, nums[mid]);
        if (nums[mid] >= nums[mid - 1])
        {
            // we is left hand side
            st = mid + 1;
        }
        else
            end = mid - 1;
    }
    if (peak == -1)
    {
        if (nums[0] <= nums[nums.size() - 1])
        {
            peak = max(peak, nums[nums.size() - 1]);
        }
        else
            peak = max(peak, nums[0]);
    }
    return peak;
}

int main()
{
    vector<int> nums = {1, 10, 13, 7, 6, 5, 4, 2, 1, 0};
    cout << findpeak(nums);
    return 0;
}