
#include <bits/stdc++.h>
using namespace std;
int bf(vector<int> nums, int k)
{ // O(n^2)andO(n^3)
    int count = 0;

    int n = nums.size();
    for (int i = 0; i < n; i++)
    {
        int XOR = 0;
        for (int j = i; j < n; j++)
        {
            XOR ^= nums[j];
            if (XOR == k)
                count++;
        }
    }
    return count;
}
int prefixmethod(vector<int> nums, int k)
{
    int n = nums.size();
    unordered_map<int, int> m;
    int XOR = 0;
    int count = 0;
    m[0] = 1;
    int remove;
    for (int i = 0; i < n; i++)
    {
        XOR ^= nums[i];
        remove = XOR ^ k;
        count += m[remove];
        m[XOR]++;
       
    } return count;}

    int main()
    {
        vector<int> nums = {4, 2, 2, 6,4};
        cout << prefixmethod(nums, 6);
        return 0;
    }