#include <bits/stdc++.h>
using namespace std;
 
 int localmethold(int arr[],int j,int n){ int count =0;
    for(int i=0;i<n;i++)if(j==arr[i]) count++;
return count;}



 void show(int arr[],int n){
      for(int i=0;i<n;i++){
        cout<<arr[i]<<" "<<localmethold(arr,arr[i],n)<<endl;  
 }};

void numarrayhash(int arr[],int n){
    int hasharray[12]={0};
    for(int i=0;i<n;i++){
        hasharray[arr[i]]++;
    }
     for(int i=0;i<n;i++){
        cout<<i<<" "<<hasharray[i]<<endl;
}}
void chararrayhash(char ary[],int n1){
    int hasharray[26]={0};
    for(int i=0;i<n1;i++){
        hasharray[ary[i]-'a']++;
    }
     for(int i=0;i<n1;i++){
        cout<<ary[i]<<" "<<hasharray[ary[i]-'a']<<endl;
}}
 void bestnum(int arr[],int n){
    unordered_map<int,int>m;
    for(int i=0;i<n;i++){
        m[arr[i]]++;
    }
    for(auto it:m) cout<<it.first<<" "<<it.second<<endl;
 }

  void bestchar(char ary[],int n1){
    unordered_map<char,int>m;
    for(int i=0;i<n1;i++){
        m[ary[i]]++;
    }
    for(auto it:m) cout<<it.first<<" "<<it.second<<endl;
 }
int main() {
    int arr[]={1,2,3,1,2,4,4};
    int n=sizeof(arr)/sizeof(arr[0]);//only work inside this not fun pass this 
    // show(arr,n);
    // numarrayhash(arr,n);
      char ary[]="ababcdklcd";
     int n1=sizeof(ary)/sizeof(ary[0])-1;//nullcharacter is add avoid make arr like this 
//  chararrayhash(ary, n1);
   bestchar(ary,n1);
    return 0;
}