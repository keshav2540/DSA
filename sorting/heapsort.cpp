#include <bits/stdc++.h>
using namespace std;
void heapify(vector<int>&arr,int i,int n){
  
    int left=2*i+1;
    int right=2*i+2;
    int largest=i;
    if(left<n&& arr[left]>arr[largest]){
         largest=left;
    }
    if(right<n&& arr[right]>arr[largest]){
        largest=right;
    }
    if(largest!=i){
        swap(arr[largest],arr[i]);
        heapify(arr,largest,n);
    }
}
void heapsort(vector<int>&arr){
      int n=arr.size();
    for(int i=n/2-1;i>=0;i--){
        heapify(arr,i,n);
    }
    for(int i=n-1;i>=0;i--){
        swap(arr[0],arr[i]);
         heapify(arr,0,i);
        
    }
}

int main() {
    vector<int>arr={9,7,5,89,45,89};
    heapsort(arr);
    for(int i:arr) cout<<i<<" ";

    return 0;
}