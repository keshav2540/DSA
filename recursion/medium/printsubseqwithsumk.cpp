// this is pattern 1
#include <bits/stdc++.h>
using namespace std;
void prints(int ind,vector<int>&ans,int s,int sum,int arr[],int n){
if(ind==n){
    if(s==sum){
        for(auto i:ans){
            cout<<i<<" ";
        }cout<<endl;
        return ;
    } return;
}
ans.push_back(arr[ind]);
s+=arr[ind];
prints(ind+1,ans,s,sum,arr,n);
s-=arr[ind];
ans.pop_back();
prints(ind+1,ans,s,sum,arr,n);
}
int main() {
 int arr[]={1,2,1};
 int n=3;
 int sum=2;
 vector<int>ans;
 prints(0,ans,0,sum,arr,n);
    return 0;
}