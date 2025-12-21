#include <bits/stdc++.h>
using namespace std;
bool check(vector<int> nums)
{
    for (int i = 0; i < nums.size(); i++)
    {
        int left = 2 * i + 1;
        int right = 2 * i + 2;
        if ((nums[left] > nums[i] || nums[right] > nums[i]) && left < nums.size() && right < nums.size())
            return false;
    }
    return true;
}

int main()
{
    vector<int> nums = {90, 15, 10, 7, 12, 2};
    cout << check(nums);
    return 0;
}