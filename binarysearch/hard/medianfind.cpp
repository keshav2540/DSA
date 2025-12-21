#include <bits/stdc++.h>
using namespace std;
double usingbf(vector<int>nums1,vector<int>nums2){// count methold
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2;
     vector<int>temp(0,n1+n2-1);
    int first=0,second=0;
    while(first<=n1&& second<=n2){
        if(nums1[first]>nums2[second]){ temp.push_back(nums2[second++]);}
        else {temp.push_back(nums1[first++]);}
    }
    while(first<=n1)temp.push_back(nums1[first++]);
    while(second<=n2) temp.push_back(nums2[second++]);
    if(n%2==0) return(double)(temp[n/2]+temp[n/2-1])/2.0;
    else return temp[n/2];
}

 double somethingoptimal(vector<int>nums1,vector<int>nums2){
    int n1=nums1.size();
    int n2=nums2.size();
    int n=n1+n2; int count=0;
     int first=0,second=0;
    while(first<=n1&& second<=n2){if(count==n/2) break;
        if(nums1[first]>nums2[second]){second++; count++;}
        else {first++; count++;}}
    while(first<=n1){if(count==n/2){ break;}first++; count++;}
    while(second<=n2) {if(count==n/2) {break;}second++; count++;}
    if(n%2==0) return double((max(nums1[first-1],nums2[second-1])+min(nums1[first],nums2[second]))/2);
     else return max(nums1[first],nums2[second]);
 }
double medianbs(vector<int> nums1, vector<int> nums2)
{
    int n1 = nums1.size();
    int n2 = nums2.size();
    if(n2<n1) return medianbs(nums2,nums1);
    int left = (n1 + n2 + 1) / 2;
    int low = 0, high = n1;
    while (low <= high)
    {
        int mid1 = (low + high)>>1;
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
            if ((n1 + n2) % 2 == 0)
            {
                return (double)((max(l1, l2) + min(r1, r2)) / 2.0);
            }
            else
                return max(l1, l2);
        }
        if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    } return 0;
}
int main()
{
    vector<int> nums1 = {1,3,4,7,10,12};
    vector<int> nums2 = {2,3,6,15};
    cout << medianbs(nums1,nums2);
    return 0;
}