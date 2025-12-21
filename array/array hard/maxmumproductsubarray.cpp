//continue;
#include <bits/stdc++.h>
using namespace std;
int maximumproduct(vector<int>nums){
    int n=nums.size();
    int prefix=1;int suffix=1;
    int res= INT32_MIN;
    for(int i=0;i<n;i++){
        if(prefix==0) prefix==1;
        if(suffix==0) suffix==1;
        prefix=prefix*nums[i];
        suffix=suffix*nums[n-i-1];
        res=max(res,max(prefix,suffix));
    }
    return res;
}
int withoutcontineouswithrandomelement(vector<int>nums){
    int n=nums.size();
     int minmum=INT32_MAX;
    int res=1;
   for(int i=0;i<n;i++){
    if(nums[i]==0)continue;
    res=res*nums[i];
    minmum=min(minmum,nums[i]);
   }
 res>0 ?: res=res/minmum;
 return res;
}
 


int main() {
    vector<int>nums={-2,3,0,4,-1};
    cout<< withoutcontineouswithrandomelement(nums);
    return 0;
}