#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int>nums,int totalDay,int mid){
    int day=0; int a=0;
    for(int i=0;i<nums.size();i++){
        if(a+nums[i]<=mid){
            a+=nums[i];
        }
        else{
            day++;
            a=nums[i];
        }}
        if(a<=mid)day++;
        if(totalDay>=day) return true;
        return false;
}
int giveDay(vector<int>nums,int totalDay,int mid){
    int day=0; int a=0;
    for(int i=0;i<nums.size();i++){
        if(a+nums[i]<=mid){
            a+=nums[i];
        }
        else{
            day++;
            a=nums[i];
        }}
        if(a<=mid)day++;
        return day;
}
int leastcap(vector<int>nums,int totalDay){
    int low=INT_MIN;
    int high=0;
    for(int i=0;i<nums.size();i++){
        low=max (low,nums[i]);
        high+=nums[i];
    }
    while(low<=high){
         int mid=(low+high)/2;
         if(ispossible(nums,totalDay,mid)){
            high=mid-1;
         }
         else{
            low=mid+1;
         }
    } return low;
}
int ls(vector<int>nums,int totalDay){
   for(int i=10;i<=55;i++){
    int dayreq=giveDay(nums,totalDay,i);
    if(dayreq<=totalDay) return i;
   }

}

int main() {
    vector<int>nums={1,2,3,4,5,6,7,8,9,10};
    int totalDay =5;
    cout<<leastcap(nums,totalDay);
    cout<< endl<<ls(nums,totalDay);
    return 0;
}