#include <bits/stdc++.h>
using namespace std;
int rating(vector<int>nums){ int sum=0;
    vector<int>left(nums.size(),1);
    vector<int>right(nums.size(),1);
    for(int i=1;i<nums.size();i++){
        if(nums[i]>nums[i-1]){
            left[i]=left[i-1]+1;
        }
        else left[i]=1;
    }
    for(int i=(nums.size()-2);i>=0;i--){
        if(nums[i]>nums[i+1]){
            right[i]=right[i+1]+1;

        }else right[i]=1;
    }
    for(auto i:left) cout<<i<<" ";
    cout<<endl;
    for(auto i:right) cout<<i<<" ";
    cout<<endl;
     for(int i=1;i<nums.size();i++){
        sum+=max(left[i],right[i]);
     } return sum;
}
int slopemethold(vector<int>nums){
    int sum=1,i=1;
    while(i<nums.size()){
        if(nums[i]==nums[i-1]){
            sum+=1;i++;continue;
        } 
     int peak=1;
        while(i<nums.size()&&nums[i]<nums[i-1]) {
            sum+=peak;
            i++; 
            peak++;
        }
  int down=1;
     while(i<nums.size()&&nums[i]>nums[i-1]) {
        sum+=down;i++;down++;
     }
      if(down>peak)sum+=(down-peak);
}return sum;
}

int main() {
    vector<int>arr={0,2,4,3,2,1,1,1,3,5,6,4,0,0};
    cout<<slopemethold(arr);

    return 0;
}