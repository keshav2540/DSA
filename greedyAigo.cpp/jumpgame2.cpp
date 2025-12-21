#include <bits/stdc++.h>
using namespace std;
 int jumpreqire(vector<int>nums){
    int jump=0,l=0,r=0;
   while(l<nums.size()){
       int farest=0;
       for(int j=l;j<=r;j++){
        farest=max(farest,nums[j]+j);
        if(j>=nums.size()-1) return jump;
       }l=r+1;
       jump++;
       r=farest;
    }return jump;
 }
int main() {
    vector<int>nums={2,3,1,4,1,1,1,2};
    cout<<jumpreqire(nums);
    return 0;
}