#include <bits/stdc++.h>
using namespace std;
vector<int>solve(vector<vector<int>>matrix,int target){
    int n=matrix.size();
    int m=matrix[0].size();
    int row=0,col=m;
    while(row<n&& col>=0){
        if(matrix[row][col]== target) return {row,col};
        else if(matrix[row][col]>target) col--;
        else row++;
    } return{-1,-1};
}

int main() {
    vector<vector<int>>matrix={{1,4,7,11,15},{2,5,8,12,19},{3,6,9,16,22},{10,13,14,17,24},{18,21,23,26,30}};
    int target=14;
    cout<<solve(matrix,target)[0]<<" "<<solve(matrix,target)[1];
    return 0;
}