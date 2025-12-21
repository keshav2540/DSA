#include <bits/stdc++.h>
using namespace std;
void dfs(int row, int col, vector<vector<int>> &mat,   vector<vector<int>> &vis, vector<int> delrow, vector<int> delcol, int n, int m)
{
    vis[row][col] = 1;
    for (int i = 0; i < 4; i++)
    {
        int nrow = row + delrow[i];
        int ncol = col + delcol[i];
        if (nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && !vis[nrow][ncol] && mat[nrow][ncol]==0)
        {
            dfs(nrow, ncol, mat, vis, delrow, delcol, n, m);
        }
    }
}
vector<vector<int>> sol(vector<vector<int>> &mat)
{
    vector<int> delrow = {-1, 0, 1, 0};
    vector<int> delcol = {0, 1, 0, -1};
    int n = mat.size();
    int m = mat[0].size();
    vector<vector<int>> vis(n, vector<int>(m, 0));
    for (int i = 0; i < n; i++)
    {
        if (mat[i][0] == 0)
        {
            dfs(i, 0, mat, vis, delrow, delcol, n, m);
        }
        if (mat[i][m - 1] == 0)
        {
            dfs(i, m - 1, mat, vis, delrow, delcol, n, m);
        }
    }
    for (int i = 0; i < m; i++)
    {
        if (mat[0][i] == 0)
        {
            dfs(0, i, mat, vis, delrow, delcol, n, m);
        }
        if (mat[n-1][i] == 0)
        {
            dfs(n - 1, i, mat, vis, delrow, delcol, n, m);
        }
    }

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (mat[i][j] == 0 && vis[i][j] == 1)
            {
                mat[i][j] = 1;
            }
        }
    }
    return mat;
}

int main()
{
    vector<vector<int>> mat={{1, 1, 1, 1, 1},
                            {1, 0, 0, 1, 0},
                            {1, 0, 0, 1, 0},
                            {1, 0, 1, 0, 1},
                            {0, 1, 1, 1, 1}};

    for (auto i : sol(mat))
    {
        for (int j : i)
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}