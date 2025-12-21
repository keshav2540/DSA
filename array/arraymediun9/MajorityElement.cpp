#include <bits/stdc++.h>
using namespace std;
int hashing(vector<int> nums) {}
int mooreVatingAlgo(vector<int> nums)
{
    int frq = 0, n = nums.size();
    int ans;
    for (int i = 0; i < n; i++)
       { if (frq == 0)
            ans = nums[i];
    if (ans == nums[i])
        frq++;
    else
        frq--;}
        frq=0;
        for( int i=0;i<n;i++){
            if(ans==nums[i])frq++;
            if(frq>n/2) return ans;

        }
        return -1;
}

int main()
{
    vector<int> nums = {2, 2, 3, 3, 1, 2, 2,3,3,3,3,3,3,};
    cout<< mooreVatingAlgo(nums);
    return 0;
}