#include <bits/stdc++.h>
using namespace std;
int bf(vector<int>nums){
    map<int,int>m;
     for(int i=0;i<nums.size();i++) m[nums[i]]++;
     for(auto it:m)if(it.second==1) return it.first;
     return 0;
}
int better(vector<int>nums){
    int ans=0;
    for(int i=0;i<32;i++){
        int count=0;
        for(int j=0;j<nums.size();j++){
            if(nums[j]&(1<<i)) count++;
        }
        if(count%3==1){
            ans=ans|(1<<i);
        }
    } return ans;
}
int somethingoptimal(vector<int>nums){
    sort(nums.begin(),nums.end());
    for(int i=1;i<nums.size();i=i+3){
        if(nums[i-1]!=nums[i]) return nums[i-1];
    }
     return nums[nums.size()-1];
}int bucketmethold(vector<int>nums){
    int one=0,two=0;
    for(int i=0;i<nums.size();i++){
        one=one^nums[i]&~two;
        two=two^nums[i]&~one;
    } return one;
}

int main() {
    vector<int>nums={5,5,5,2,4,4,4};
    cout<<bucketmethold(nums);
    return 0;
}