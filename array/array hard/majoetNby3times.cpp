#include <bits/stdc++.h>
using namespace std;
// bF and hashing formal if sorked count method
// something unique dnf version
vector<int> majorityel(vector<int> nums, int n)
{
    int count1 = 0;
    int count2 = 0;
    int el1 = 0;
    int el2 = 0;
    for (int i = 0; i < n; i++)
    {
        if (count1 ==0 && nums[i] != el2)
        {
            el1 = nums[i];
            count1=1;
        }
        else if (nums[i] == el1)
            count1++;
        else if (count2 == 0 && nums[i] != el1)
        {
            el2 = nums[i];
            count2=1;
        }
        else if (nums[i] == el2)
            count2++;
        else
            {count1--;
             count2--;}
    }
    cout << el1 << " " << el2;
}

int main()
{
    vector<int> nums = {1, 1, 1, 3, 3,3,3, 2, 2, 2, 2};
    int n = 11;
    majorityel(nums, n);
    // our chance is n/3=2 max 2 element come more tha n/3 times
    return 0;
}