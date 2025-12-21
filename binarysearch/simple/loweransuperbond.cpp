#include <bits/stdc++.h>
using namespace std;
int lowerbond(vector<int>nums,int x){// arr[idx]>=x
    int st=0;
    int n=nums.size();
    int end=n-1;
 int ans;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]>=x){
            ans=mid;
            end=mid-1;
        }
        else st=mid+1;
    }
    return ans;
}
int uperbond(vector<int>nums,int x){ //arr[idx]>x
    int st=0;
    int n=nums.size();
    int end=n-1;
 int ans;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]>x){
            ans=mid;
            end=mid-1;
        } 
        else{
            st=mid+1;
        }    
    } return ans;

}
int florr(vector<int>nums,int x){// arr[idx]<=x
    int st=0;
    int n=nums.size();
    int end=n-1;
 int ans;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]<=x){
            ans=mid;
            st=mid+1;
        }
        else end=mid-1;
    }
    return ans;
}
int cl(vector<int>nums,int x){ //arr[idx]>=x
    int st=0;
    int n=nums.size();
    int end=n-1;
 int ans;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]>=x){
            ans=mid;
            end=mid-1;
        } 
        else{
            st=mid+1;
        }    
    }

}

int main() {
    // vector<int>nums={1,2,3,3,5,8,8,10,10,11};
    // int x=4;
    // cout<<lowerbond(nums,x)<<" "<<nums[lowerbond(nums,x)]<<endl;
    // cout<<uperbond(nums,x)<<" "<<nums[uperbond(nums,x)]<<endl;
    // return 0;
vector<int>nums={10,20,30,40,50};
int x=35;
    cout<<florr(nums,x)<<" "<<nums[florr(nums,x)]<<endl;
    cout<<cl(nums,x)<<" "<<nums[cl(nums,x)]<<endl;
}