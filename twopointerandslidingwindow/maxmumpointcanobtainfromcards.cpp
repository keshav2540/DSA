#include <bits/stdc++.h>
using namespace std;
 int sol(vector<int>nums,int k){
    int lsum=0,rsum=0,rindex=nums.size()-1;int maxsum=0;
    for(int i=0;i<=k-1;i++)lsum+=nums[i];
    maxsum=max(maxsum,lsum+rsum);
    for(int j=k-1;j>=0;j--){
        lsum=lsum-nums[j];
        rsum+=nums[rindex--];
        maxsum=max(maxsum,lsum+rsum);
    } return maxsum;
 }
int main() {
    vector<int>nums={6,2,3,4,7,2,1,7,1};
    int k=4; //numberofcards;
    cout<<sol(nums,k);
    return 0;
}