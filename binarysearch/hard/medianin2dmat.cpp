#include <bits/stdc++.h>
using namespace std;
int uperBound(vector<int>nums,int x){
   int n=nums.size();
   int st=0,end=n-1;
   while(st<=end){
    int mid=(st+end)/2;
    if(nums[mid]>x) end=mid-1;
   else st=mid+1;
} return st;
}
int blackBox(vector<vector<int>>matrix,int mid){
     int n=matrix.size();
     int count=0;
    for(int i=0;i<n;i++){
        count+=uperBound(matrix[i],mid);
    } return count;
}
int medianUsingBs(vector<vector<int>>matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int req=n*m/2; 
    int low=matrix[0][0],high=matrix[n-1][m-1];
    while(low<=high){
        int mid=(low+high)/2;
         int smallerEqual=blackBox(matrix,mid);
         if(smallerEqual<=req){
            low=mid+1;
         }else high=mid-1;
    } return low;
}

int main() {
    vector<vector<int>>matrix={{1,5,7,9,11},{2,3,4,5,10},{9,10,12,14,16}}; //allways odd
    cout<<medianUsingBs(matrix);
    return 0;
}