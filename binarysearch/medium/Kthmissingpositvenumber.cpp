#include <bits/stdc++.h>
using namespace std;
 int ls(vector<int>nums,int k){
    for(int i=0;i<nums.size();i++){
        if(nums[i]<=k) k++;
        else return k;
    }return -1;
 }

 int missingpositive(vector<int>nums,int k){
    int low=0,high=nums.size()-1;
     while(low<=high){
        int mid=(low+high)/2;
         int missing=nums[mid]-(mid+1);
         if(missing<k) low=mid+1;
         else high=mid-1;
     }
     return low+k;// because 

 }

int main() {
    vector<int>nums={2,3,4,7,11};
    int k=1;
    cout<<ls(nums,k)<<endl;
    cout<<missingpositive(nums,k)<<endl;
    return 0;
}