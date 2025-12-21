#include <bits/stdc++.h>
using namespace std;
vector<int>BSin2dMatrix(vector<vector<int>>matrix,int target){// think 2d array is liner
    int n=matrix.size(),m=matrix[0].size();
int st=0,end=matrix.size()*matrix[0].size();
while(st<=end){
    int mid=(st+end)/2;
    int row=mid/m;
    int col=mid%m;
    if(matrix[row][col]==target) return{row,col};
    if(matrix[row][col]>target) end=mid-1;
    else st=mid+1;
} return {-1,-1};
}
vector<int>searchIn2dMatrix(vector<vector<int>>matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size();
    for(int i=0;i<n;i++){
        if(matrix[i][0]<=target&& matrix[i][m-1]>=target){
         int st=0; 
        int end=m-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(matrix[i][mid]==target){return {i,mid};}
         else if (matrix[i][mid]>target)end=mid-1;
        else st=mid+1;
        }}
    } return {-1,-1};
}

int main() {
    vector<vector<int>>matrix={{3,4,7,9},{12,13,16,18},{20,21,23,29}};
    int target=4;
    cout<<BSin2dMatrix(matrix,target)[0]<<" "<<BSin2dMatrix(matrix,target)[1];
    return 0;
}