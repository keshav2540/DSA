#include <bits/stdc++.h>
using namespace std;

void bfs(int row,int col,vector<vector<int>>&grid,vector<vector<int>>&visited){
    visited[row][col]=1;
    int n=grid.size();//row
    int m=grid[0].size();//col
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty()){
         row=q.front().first;
         col=q.front().second;q.pop();
        for(int delrow=-1;delrow<=1;delrow++){
            for(int delcol=-1;delcol<=1;delcol++){
                int nrow=row+delrow;
                int ncol=col+delcol;
                if(nrow>=0&&ncol>=0&&nrow<n&&ncol<m&& grid[nrow][ncol]==1&&!visited[nrow][ncol]){
                    visited[nrow][ncol]=1;
                    q.push({nrow,ncol});
                }
            }
        }

    }
}
int numberofisland(vector<vector<int>>&grid){
    int n=grid.size();
    int m=grid[0].size();
    int count=0;
    vector<vector<int>>visited(n,vector<int>(m,0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(!visited[i][j]&&grid[i][j]==1){
                count++;
                bfs(i,j,grid,visited);
            }
        }
    } return count;
}
int main() {
    vector<vector<int>>grid={{0,1,1,0},{0,1,1,0},{0,0,1,0},{0,0,0,0},{1,1,0,1}};
    cout<<numberofisland(grid);

    return 0;
}