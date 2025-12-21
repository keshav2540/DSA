#include <bits/stdc++.h>
using namespace std; // can flip  k zero
int maxlengthbf(vector<int> nums, int k)
{
    ;
    int maxlength = 0;
    for (int i = 0; i < nums.size(); i++)
    {
        set<int> s;
        for (int j = i; j < nums.size(); j++)
        {
            s.insert(nums[j]);
            if (s.size() <= k)
                maxlength = max(maxlength, j - i + 1);
            else
                break;
        }
    }
    return maxlength;
}
int maxlengthbetter(vector<int> nums, int k)
{
    int l = 0, r = 0, maxlength = 0;
    map<int, int> m;
    while (r < nums.size())
    {
        m[nums[r]]++;
        while (m.size() > k)
        {  m[nums[l]]--;
            if(m[nums[l]]==0) m.erase(nums[l]);
            l++;  
        }
        if (m.size()<= k)
        {
            maxlength = max(maxlength, r - l + 1);
        }
        r++;
    }
    return maxlength;
}
int maxlengthoptimal(vector<int> nums, int k)
{
    int l = 0, r = 0, maxlength = 0;
    map<int, int> m;
    while (r < nums.size())
    {
        m[nums[r]]++;
        if(m.size() > k)
        {  m[nums[l]]--;
            if(m[nums[l]]==0) m.erase(nums[l]);
            l++;  
        }
        if (m.size()<= k)
        {
            maxlength = max(maxlength, r - l + 1);
        }
        r++;
    }
    return maxlength;
}



int main()
{
    vector<int> nums = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << maxlengthoptimal(nums, 3);
    return 0;
}