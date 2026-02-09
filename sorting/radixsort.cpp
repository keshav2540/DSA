#include <bits/stdc++.h>
using namespace std;
void countsort(vector<int>&arr,int exp,int n){
    int output[n];
    int count[10]={0};
    for(int i=0;i<n;i++){
        count[(arr[i]/exp)%10]++;
    }
    for(int i=1;i<n;i++){
        count[i]+=count[i-1];
    }
    for(int i=n-1;i>=0;i--){
        output[count[(arr[i]/exp)%10]-1]=arr[i];
        count[(arr[i]/exp)%10]--;
    }
    for(int i=0;i<n;i++){
        arr[i]=output[i];
    }
}
void radix_sort(vector<int>&arr){
    int n=arr.size();
    int maxi=0;
    for(int i=0 ;i<n;i++){
        maxi=max(maxi,arr[i]);
    }
    for(int exp=1;maxi/exp>0;exp*=10){
        countsort(arr,exp,n);
    }
    for(int i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
}
int main() {
vector<int>arr={10,20,30,405,5003 ,204,040};
radix_sort(arr);
    return 0;
}