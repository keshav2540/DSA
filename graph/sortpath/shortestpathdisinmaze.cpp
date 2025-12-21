/* we use  queue instead of priority queue because dist is incerase in constant / mean dist between two cell is same */
#include <bits/stdc++.h>
using namespace std;
int drow[] = {-1, 0, 1, 0};
int dcol[] = {0, 1, 0, -1};
int mindistance(int strow, int stcol, int endrow, int endcol, vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    queue<pair<int, pair<int, int>>> pq;//both are same work dis. is constant
    vector<vector<int>> dist(n, vector<int>(m, 1e9));
    dist[strow][stcol] = 0;
    pq.push({0, {strow, stcol}});
    while (!pq.empty())
    {
        auto node = pq.front().second;
        int r = node.first;
        int c = node.second;
        int nodedist = pq.front().first;
        pq.pop();
        for (int i = 0; i < 4; i++)
        {
            int nrow = r + drow[i];
            int ncol = c + dcol[i];
            if (nrow >= 0 && ncol >= 0 && nrow < n && ncol < m && grid[nrow][ncol] == 1 && dist[nrow][ncol] > nodedist + 1)
            {  if(nrow==endrow&& ncol==endcol) return  nodedist + 1;
                dist[nrow][ncol] = nodedist + 1;
                pq.push({dist[nrow][ncol], {nrow, ncol}});
            }
        }
    }
    return -1;
}
int main()
{
    vector<vector<int>> grid { {1, 1, 1, 1}, {1, 1, 0, 1}, {1, 1, 1, 1}, {1, 1, 0, 0}, {1, 0, 0, 0} };
    cout << mindistance(0, 1, 3,1, grid);
    return 0;
}