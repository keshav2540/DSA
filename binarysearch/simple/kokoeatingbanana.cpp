#include <bits/stdc++.h>
using namespace std;
bool mayans(vector<int>nums,int mid,int deadline){
    int count=0;
     for(int i=0;i<nums.size();i++){
        if(nums[i]<=mid) count++;
        else{
            count+=(nums[i]/mid);
            if(nums[i]%mid<mid&&nums[i]%mid!=0) count++;
        }
     }
     if(count<=deadline) return 1;
     else return 0;  
}
int minimumdaykokoeatbnana(vector<int>nums,int deadline){
int st=0,end=deadline;int ans=-1;
while(st<=end){
    int mid=st+(end-st)/2;
    if(mayans(nums,mid,deadline)){
        end=mid-1;
        ans=mid;
    }
    else st=mid+1;
}
return ans;
}

int main() {
    vector<int>nums={3,6,7,11,9,9};
    int deadline=9;
    cout<<minimumdaykokoeatbnana(nums,deadline);
    return 0;
}