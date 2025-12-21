#include <bits/stdc++.h>
using namespace std;
int solve(vector<vector<int>>mat){
    queue<pair<int,int>>q;
     int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(i==0||i==n-1|| j==0|| j==m-1){
                if(mat[i][j]==1 && vis[i][j]==0){
                    q.push({i,j});
                    vis[i][j]=1;
                }
            }
        }
    }
     vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
 
    while (!q.empty())
    {
        int r = q.front().first;
        int c = q.front().second;
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + delrow[i];
            int ncol = c + delcol[i];
            if (nrow>=0&&ncol>=0&&nrow<n&&ncol<m&&vis[nrow][ncol]==0 && mat[nrow][ncol] == 1)
            {   vis[nrow][ncol]=1;
                q.push({nrow, ncol});
            }
        }
    }     int count = 0;
     for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(mat[i][j]==1 && vis[i][j]==0){
                count++;
            }
        }
    } return count;
}
int main()
{
    vector<vector<int>> mat={{0,0,0,1},{0,1,1,0},{0,1,1,0},{0,0,0,1},{0,1,1,0}};
    cout<<solve(mat);
    return 0;
}