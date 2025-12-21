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
    }

}
int first(vector<int>nums,int l){
    int st=0;
    int n=nums.size();
    int end=n-1;
 int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==l){ ans=mid;end=mid-1;}
       else if(nums[mid]>l){
            end=mid-1;
        }
        else st=mid+1;
    }
    return ans;

}
int last(vector<int>nums,int l){ //arr[idx]>x
    int st=0;
    int n=nums.size();
    int end=n-1;
 int ans=-1;
    while(st<=end){
        int mid=st+(end-st)/2;
        if(nums[mid]==l) {ans=mid ; st=mid+1;}
        else if(nums[mid]>l){
            end=mid-1;
        } 
        else{
            st=mid+1;
        }    
    }
 return ans;
}



int main() {
    vector<int>nums={2,4,6,8,8,8,11,13};
     int l=10;
     // in this case not work
    cout<<"first"<<lowerbond(nums,l)<<" "<<"last"<<uperbond(nums,l)-1<<endl;
     cout<<"first"<<first(nums,l)<<" "<<"last"<<last(nums,l)<<endl;
    return 0;
}