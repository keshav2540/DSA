#include <bits/stdc++.h>
using namespace std;
// this is breute force way
vector<vector<int>>path(vector<vector<int>>&grid){
 int n=grid.size();
 for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          if(grid[i][j]==-1)//it mean do direst node between both
          {
            grid[i][j]=1e8;
          }
          if(i==j) grid[i][j]=0;
       }
 }
 for(int k=0;k<n;k++){
     for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          grid[i][j]=min(grid[i][j],grid[i][k]+grid[k][j]);
 }
 }}
//  for(int i=0;i<n;i++){if(grid[i][i]<0){ //reagative cycle}}
for(int i=0;i<n;i++){
      for(int j=0;j<n;j++){
          if(grid[i][j]==1e8)//it mean do direst node between both
          {
            grid[i][j]=-1;
          }
          cout<<grid[i][j]<<" ";
       }cout<<endl;
 } return grid;}

int main() {
    vector<vector<int>>grid={{1,1,43},{1,0,6},{-1,-1,0}};
     path(grid);
    return 0;
}