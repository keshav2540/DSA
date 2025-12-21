#include <bits/stdc++.h>
using namespace std;
bool reach(vector<int>nums){
    int maxidx=0;
    for(int i=0;i<nums.size();i++){
        if(i>maxidx) return false;
        maxidx=max(maxidx,nums[i]+i);
    } return true;
}
int main() {
    vector<int>nums={1,2,3,1,1,0,2,5};
    cout<<reach(nums);
    return 0;
}