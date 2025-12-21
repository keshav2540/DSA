#include <bits/stdc++.h>
using namespace std;
int longestSubArraySum(vector<int> nums, int sum)
{ // teo pointer
    int i = 0, j = 0, n = nums.size();
    int ans = 0;
    int length = 0, maxlength = -1;
    while (i < n || j < n)
    {
        if (ans < sum && j<n)
        {
            ans += nums[j];
            j++;
        }
        else if (ans > sum && i<n)
        {
            ans -= nums[i];
            i++;
        }
        else if(ans==sum)
        {
            length = j - i;
            maxlength = max(maxlength, length);
            ans = ans + nums[j];
            j++;
        }
        else return maxlength;
    }
    if (ans == sum)
    {
        length = j - i;
        maxlength = max(maxlength, length);
    }
    return maxlength;
}



int main()
{
    vector<int> nums = {1, 2, 3, 1, 1, 0,0,0,1, 4, 2, 3};
    int sum = 13;
     cout << longestSubArraySum(nums, sum);
    return 0;
}