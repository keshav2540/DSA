#include <bits/stdc++.h>
using namespace std;
void permutations(int arr[],list<int>&ds,list<list<int>>&ans,bool frq[],int n){
    if(ds.size()==n){
        ans.push_back(ds);
      return ;
    }
    for(int i=0;i<n;i++){
        if(!frq[i]){
            frq[i]=true;
            ds.push_back(arr[i]);
            permutations(arr,ds,ans,frq,n);
            ds.pop_back();
            frq[i]=false;
        }
    }
}
int main() {
    int arr[]={1,2,3};
    list<int>ds;
    list<list<int>>ans;
    int n=sizeof(arr)/sizeof(arr[0]);
    bool frq[n]={false};
    permutations(arr,ds,ans,frq,n);
    for(auto &s:ans){
    for(auto i:s){
        cout<<i<<" ";
    } cout<<endl;
   }

    return 0;
}