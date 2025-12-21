#include <bits/stdc++.h>
using namespace std;
int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};
int mindeffort(int strow, int stcol, int endrow, int endcol, vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;//both are same work dis. is constant
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[strow][stcol] = 0;
    pq.push({0, {strow, stcol}});
    while (!pq.empty())
    {
        auto node = pq.top().second;
        int r = node.first;
        int c = node.second;
        int nodedist = pq.top().first;
        pq.pop();
      if(r==endrow&& c==endcol) return nodedist;
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m  && dist[nrow][ncol] > max(nodedist,(abs(grid[r][c]-grid[nrow][ncol]))))
            { 
                dist[nrow][ncol] = max(nodedist,(abs(grid[r][c]-grid[nrow][ncol])));
                pq.push({dist[nrow][ncol], {nrow, ncol}});
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> grid { {1, 2,2}, {3,8, 2}, {5,3,5}};
    cout << mindeffort(0, 0, 2,2, grid);
    return 0;
}