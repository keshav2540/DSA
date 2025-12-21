#include <bits/stdc++.h>
using namespace std;
void printsqformat(vector<vector<int>> &grid)
{
    int n = grid.size(), m = grid[0].size();
    int sr = 0, er = n - 1, sc = 0, ec = m - 1;
    while (sr <= er && sc <= er)
    {
        for (int i = sc; i <= ec; i++)
        {
            cout << grid[sr][i] << " ";
        }
        if (sr != er||sc != ec)
        {
            for (int i = sr + 1; i <= er; i++)
            {
                cout << grid[i][ec] << " ";
            }
        }
        if (sr != er && sc != ec)
        {
            for (int i = ec - 1; i >= sc; i--)
            {
                cout << grid[er][i] << " ";
            }
        }
        if (sr != er && sc != ec)
        {
            for (int i = er - 1; i >= sc + 1; i--)
            {
                cout << grid[i][sc] << " ";
            }
        }
        sc++;
        sr++;
        ec--;
        er--;
    }
}

int main()
{
    vector<vector<int>> grid = {{1, 2, 3, 4}, {20,21,22,23}, {19,32,8,4}, {18,31,36,35}, {17,30,29,2},{16,15,14,13}};
    printsqformat(grid);
    return 0;
}