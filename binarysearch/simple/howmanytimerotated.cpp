#include <bits/stdc++.h>
using namespace std;
int howmany(vector<int>nums){
     int low=0,high=nums.size()-1,ans=INT32_MAX; int id=-1;
     while(low<=high){
         int mid=low+(high-low)/2;
         if(nums[low]<=nums[high])
          {if(ans>nums[low]){
            id=low;
            ans=nums[low];
         }
          break;
        }
        if(nums[low]<=nums[mid]){
            if(ans>nums[low]){
                id=low;
                ans=nums[low];
            }
            
            low=mid+1;
        }
        else{
              if(ans>nums[mid]){
                id=mid;
                ans=nums[mid];
              }
                        
              high=mid-1;
        }
     } 
     return ans;

}

int main() {
    vector<int>nums{3,4,5,1,2};
    cout<<howmany(nums);
    return 0;
}