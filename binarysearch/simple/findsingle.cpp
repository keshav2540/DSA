// if vector ka size define kar to sari value fill with zero and better for your first index 0 and index n-1 write code manually beacuse its over flow when we return mid
#include <bits/stdc++.h>
using namespace std;
int findsingle(vector<int> nums)
{
    int end = nums.size() - 1;
    int st = 0;
    if (end == 0)
        return 0;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (nums[mid] != nums[mid - 1] && nums[mid] != nums[mid + 1])
        {
            return mid;
        }
        //  if(mid%2==0){ //left alll element in even
        //     if(nums[mid]!=nums[mid-1]&& nums[mid]==nums[mid+1]){
        //         st=mid+1;
        //     }
        //     else end=mid-1;
        //  }
        //  else{ if(nums[mid]!=nums[mid-1]&& nums[mid]==nums[mid+1]){
        //     end=mid-1;
        //  }else st=mid+1;
        //  }

        if (mid % 2 == 0 && nums[mid] != nums[mid - 1] && nums[mid] == nums[mid + 1] || (nums[mid] == nums[mid - 1] && nums[mid] != nums[mid + 1]) && (mid % 2 == 1))
        {
            st = mid + 1;
        }
        else
            end = mid - 1;
    }
    return -1;
}

int main()
{
    vector<int> nums = {-1};
    cout << findsingle(nums) << " " << nums[findsingle(nums)];
    return 0;
}