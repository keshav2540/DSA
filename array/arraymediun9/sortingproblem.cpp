#include <bits/stdc++.h>
using namespace std;
 void DNF(vector<int>&arr){
    int n=arr.size();
    int low=0,mid=0,high=n-1;
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[mid],arr[low]);
                low++;
                mid++;
        }
        else if(arr[mid]==1) mid++;
        else{
            swap(arr[high],arr[mid]);
             high--;
        }
    }
}
void countMethod(vector<int>&arr){
    int n=arr.size();
    int k=0;
    int count0=0,count1=0,count2=0;
    for(int i=0;i<n;i++){
        if(arr[i]==0) count0++;
        if(arr[i]==1) count1++;
        if(arr[i]==2) count2++;
    }
    for(int i=0;i<count0;i++){
        arr[k++]=0;
    }
    for(int i=0;i<count1;i++){
        arr[k++]=1;
    }
    for(int i=0;i<count2;i++){
        arr[k++]=2;
    }
}

int main() {
    vector<int>arr={ 0,1,2,0,1,2,1,2,0,0,0,1};
    countMethod(arr);
        for(int i:arr) cout<<i;
    return 0;
}