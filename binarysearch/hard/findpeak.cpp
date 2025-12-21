#include <bits/stdc++.h>
using namespace std;
int maxElement( const vector<vector<int>>&matrix,int n,int m,int mid){
    int maxmaxi=matrix[0][mid],idx=0;
    for(int i=0;i<n;i++) {
        if(matrix[i][mid]>maxmaxi){
            maxmaxi=matrix[i][mid];
            idx=i;
        }   
    } return idx;

}
vector<int>findpeak(vector<vector<int>>&matrix){
    int n=matrix.size();
    int m=matrix[0].size();
    int lowcol=0,highcol=m-1;
    while(lowcol<=highcol){
        int mid=(lowcol+highcol)/2;
        int row=maxElement(matrix,n,m,mid);
        int left=mid-1>=0? matrix[row][mid-1]:-1;
        int right=mid+1<m? matrix[row][mid+1]:-1;
        if(left<=matrix[row][mid] &&right<=matrix[row][mid]) return {row,mid};
     else if(left>matrix[row][mid]) highcol=mid-1;
        else lowcol=mid+1;
    } return{-1,-1};
}

main() {
    vector<vector<int>>matrix={{4,2,5,1,4,5},{2,9,3,2,3,2},{1,7,6,0,1,3},{3,6,2,3,7,2}};
    auto ans=findpeak(matrix);
    cout<<ans[0]<<" "<<ans[1];
    return 0;
}