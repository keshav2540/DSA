// this is pattern 1
#include <bits/stdc++.h>
using namespace std;
bool prints(int ind,vector<int>&ans,int s,int sum,int arr[],int n){
if(ind==n){
    if(s==sum){
        for(auto i:ans){
            cout<<i<<" ";
        }cout<<endl;
        return true ;
    } return false;
}
ans.push_back(arr[ind]);
s+=arr[ind];
 if(prints(ind+1,ans,s,sum,arr,n)==true) return true;
s-=arr[ind];
ans.pop_back();
if(prints(ind+1,ans,s,sum,arr,n)==true)return true;
return false;
}
int main() {
 int arr[]={1,2,1};
 int n=3;
 int sum=2;
 vector<int>ans;
 prints(0,ans,0,sum,arr,n);
    return 0;
}