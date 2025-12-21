#include <bits/stdc++.h>
using namespace std;

void dfs(int row,int col,int row0,int col0,vector<vector<int>>&grid,vector<vector<int>>&visited,vector<pair<int,int>>&vec,vector<int>&delrow,vector<int>&delcol){
    visited[row][col]=1;
    vec.push_back({row-row0,col-col0});
    int n=grid.size();//row
    int m=grid[0].size();//col
     for(int i=0;i<4;i++){
         int nrow=row+delrow[i];
         int ncol=col+delcol[i];
          if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!visited[nrow][ncol]&&grid[nrow][ncol]==1){
            dfs(nrow,ncol,row0,col0,grid,visited,vec,delrow,delcol);
          }
}}
int numberofislanddistict(vector<vector<int>>&grid){
 vector<int>delrow={-1,0,1,0};
 vector<int>delcol={0,1,0,-1};
    int n=grid.size();
    int m=grid[0].size();
    set<vector<pair<int,int>>>st;
    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&grid[i][j]==1){
                  vector<pair<int,int>>vec;
                dfs(i,j,i,j,grid,visited,vec,delrow,delcol);
                st.insert(vec);
            }
        }
    } return st.size();
}
int main() {
    vector<vector<int>>grid={{1,1,0,1,1},{1,0,0,0,0},{0,0,0,1,1},{1,1,0,1,0}};
    cout<<numberofislanddistict(grid);

    return 0;}