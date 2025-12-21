#include <bits/stdc++.h>
using namespace std;
int returnmini(vector<int>nums){
     int low=0,high=nums.size()-1,ans=INT32_MAX;
     while(low<=high){
         int mid=low+(high-low)/2;
         if(nums[low]<=nums[mid]&&nums[mid]<=nums[high]) {ans=min(ans,nums[low]); break;}
        if(nums[low]<=nums[mid]){
            ans=min(ans,nums[low]);
            
            low=mid+1;
        }
        else{
              ans=min(ans,nums[mid]);
                        
              high=mid-1;
        }
     } 
     return ans;
}

int main() {
    vector<int>nums={4,5,6,7,1,2,3};
    cout<<returnmini(nums);

    return 0;
}