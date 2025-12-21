#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> nums, int mid, int cows){
    sort(nums.begin(),nums.end());
    int a=nums[0], countcow=1;
    for(int i=0;i<nums.size();i++){
        if((nums[i]-a)>=mid){
            countcow++;
            a=nums[i];
        }
        if((nums[i]-a)>mid) countcow++;
    }if(countcow>=cows) return true;
    return false;
}
int distance(vector<int> nums, int cows)
{
    int low = 0, ans,high = *max_element(nums.begin(), nums.end()) - *min_element(nums.begin(), nums.end());
    while (low <= high)
{        int mid = (low + high) / 2;
    if (ispossible(nums, mid ,cows))
    { ans=mid;
        low = mid + 1;
    }
    else
        high = mid - 1;}

    return high;
}

int main()
{
    vector<int> nums = {0, 3, 4, 7, 10, 9};
    int cows = 4;
    cout << distance(nums, cows);
    return 0;
}