#include <bits/stdc++.h>
using namespace std;
 int returnRowBF(vector<vector<int>>matrix){
    int n=matrix.size();
    int maxcount=-1,row;
    for(int i=0;i<n;i++)
    { int count=0;
        for(int j=0;j<n;j++){
            if(matrix[i][j]==1){
                count++;
            }
            if(count>maxcount){
                maxcount=count;
                row=i;
            }
        }
    } return row;
}
int returnRowBs(vector<vector<int>>matrix){
    int n=matrix.size();
    int count=0,maxcount=-1;
    int row;
    for(int i=0;i<n;i++){
        int st=0; 
        int end=n-1;
        while(st<=end){
            int mid=(st+end)/2;
            if(matrix[i][mid]>=1){
                end=mid-1;
            }else st=mid+1;
        }
        count=n-st;
         if(count>maxcount){
                maxcount=count;
                row=i;
            }
    } return row;
}
int main() {
    vector<vector<int>>matrix={{0,0,1,1,1},{1,1,1,1,1},{0,1,1,1,1},{0,0,0,0,0},{0,1,1,1,1}};
    cout<<returnRowBs(matrix);
    return 0;
}