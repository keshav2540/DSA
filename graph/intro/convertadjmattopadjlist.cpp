#include <bits/stdc++.h>
using namespace std;
int convert(vector<vector<int>> g)
{
    vector<int> adj[g.size()];
    for (int i = 0; i < g.size(); i++)
    {
        for (int j = 0; j <= g[i].size(); j++)
        {
            if (g[i][j] == 1)
            {
                adj[i].push_back(j);
            }
        }
    }
    for (int i = 0; i < g.size(); i++)
    {     cout<<i<<"   :   ";
        for (auto j : adj[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }
    return 0;
}
int main()
{
    vector<vector<int>>g(9, vector<int>(9, 0));
    g[1][2] = 1;
    g[2][1] = 1;
    g[3][2] = 1;
    g[2][3] = 1;
    g[4][5] = 1;
    g[5][4] = 1;
    g[5][6] = 1;
    g[6][5] = 1;
    g[8][7] = 1;
    g[7][8] = 1;
    cout << "hello";
    convert(g);
    return 0;
}