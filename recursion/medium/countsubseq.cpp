// this is pattern 1
#include <bits/stdc++.h>
using namespace std;
int prints(int ind,vector<int>&ans,int s,int sum,int arr[],int n){
if(ind==n){
    if(s==sum){
        for(auto i:ans){
            cout<<i<<" ";
        }cout<<endl;
        return 1;
    } return 0;
}
ans.push_back(arr[ind]);
s+=arr[ind];
int l=prints(ind+1,ans,s,sum,arr,n);
s-=arr[ind];
ans.pop_back();
int r=prints(ind+1,ans,s,sum,arr,n);
return l+r;
}
int main() {
 int arr[]={1,2,1};
 int n=3;
 int sum=2;
 vector<int>ans;
 cout<<prints(0,ans,0,sum,arr,n);
    return 0;
}