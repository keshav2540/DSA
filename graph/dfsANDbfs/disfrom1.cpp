#include <bits/stdc++.h>
using namespace std;
vector<vector<int>>nearest(vector<vector<int>>grid){
     vector<int>delrow={-1,0,1,0};
     vector<int>delcol={0,1,0,-1};
    int n=grid.size();
    int m=grid[0].size();
    vector<vector<int>>vis(n,vector<int>(m,0));
    vector<vector<int>>dis(n,vector<int>(m,0));
    queue<pair<pair<int,int>,int>>pq;
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            if(grid[i][j]==1){
                vis[i][j]=1;
                pq.push({{i,j},0});
            }
        }
    }
    while(!pq.empty()){
        int row=pq.front().first.first;
        int col=pq.front().first.second;
        int distance=pq.front().second;
        pq.pop();
        dis[row][col]=distance;
        for(int i=0;i<4;i++){
         int nrow=row+delrow[i];
         int ncol=col+delcol[i];
          if(nrow>=0&&nrow<n&&ncol>=0&&ncol<m&&!vis[nrow][ncol]){
            vis[nrow][ncol]=1;
            pq.push({{nrow,ncol},distance+1});
          }
        }
    } return dis;
}
int main() {
vector<vector<int>>mat={{0,0,0},{0,1,0},{1,0,1}};
vector<vector<int>>grid=nearest(mat);
 int n=grid.size();
    int m=grid[0].size();
    for(int i=0;i<n;i++){
        for(int j=0;j<n;j++){
            cout<<grid[i][j]<<" ";
        } cout<<endl;
    }
    return 0;
}