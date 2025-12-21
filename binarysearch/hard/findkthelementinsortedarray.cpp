#include <bits/stdc++.h>
using namespace std;
double Kthelement(vector<int> nums1, vector<int> nums2, int k)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if (n2 < n1)
        return Kthelement(nums2, nums1, k);
    int left = k;
    int low = max(0, k - n2), high = min(k, n1);
    while (low <= high)
    {
        int mid1 = (low + high) >> 1;
        int mid2 = left - mid1;
        int l1 = INT32_MIN, l2 = INT32_MIN, r1 = INT32_MAX, r2 = INT32_MAX;
        if (mid1 - 1 >= 0)
            l1 = nums1[mid1 - 1];
        if (mid1 < n1)
            r1 = nums1[mid1];
        if (mid2 - 1 >= 0)
            l2 = nums2[mid2 - 1];
        if (mid2 < n2)
            r2 = nums2[mid2];
        if (l1 <= r2 && l2 <= r1)
        {
            return max(l1, l2);
        }
        if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }
    return 0;
}
int main()
{
    vector<int> nums1 = {2, 3,5,6, 7, 9};
    vector<int> nums2 = {1, 7, 8, 10};
    int k = 4;
    cout << Kthelement(nums1, nums2, k);
    return 0;
}