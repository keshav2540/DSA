#include <bits/stdc++.h>
using namespace std;
class disjointset
{
    vector<int> rank, parent, size;

public:
    disjointset(int n)
    {
        rank.resize(n + 1, 0);
        parent.resize(n + 1, 0);
        size.resize(n + 1, 1);
        for (int i = 0; i <= n; i++)
        {
            parent[i] = i;
        }
    }
    int findpar(int node)
    {
        if (node == parent[node])
            return node;
        return parent[node] = findpar(parent[node]);
    }
    void unionbyrank(int u, int v)
    {
        int pv = findpar(v);
        int pu = findpar(u);
        if (pv == pu)
            return;
        if (rank[pu] < rank[pv])
        {
            parent[pu] = pv;
        }
        else if (rank[pu] > rank[pv])
        {
            parent[pv] = pu;
        }
        else
        {
            parent[pv] = pu;
            rank[pu]++;
        }
    }
    void unionbysize(int u, int v)
    {
        int pv = findpar(v);
        int pu = findpar(u);
        if (pv == pu)
            return;
        if (size[pu] < size[pv])
        {
            parent[pu] = pv;
            size[pv] += size[pu];
        }
        else
        {
            parent[pv] = pu;
            size[pu] += size[pv];
        }
    }
};
int maximumstonecanremove(vector<vector<int>> &stone)
{
    int v = stone.size();
    int maxrow = 0;
    int maxcol = 0;
    for (auto it : stone)
    {
        maxrow = max(maxrow, it[0]);
        maxcol = max(maxcol, it[1]);
    }
    disjointset ds(maxrow + maxcol + 1); // tnink about insertion tech how to connect all node of componenet
    unordered_map<int, int> stonenodes;
    for (auto it : stone)
    {
        int noderow = it[0];
        int nodecol = it[1] + maxrow + 1;
        ds.unionbysize(noderow, nodecol);
        stonenodes[noderow] = 1;
        stonenodes[nodecol] = 1;
    }
    int count = 0;
    for (auto it : stonenodes)
    {
        if (ds.findpar(it.first) == it.first)
        {
            count++;
        }  
    } return (v - count);
}
int main()
{
    vector<vector<int>> adj = {{0, 0}, {0, 2}, {3, 1}, {3, 2}, {1, 3}, {4, 3}};
    //   {{1, 0, 1, 0},
    //    {0, 0, 0, 1},
    //    {0, 0, 0, 0},
    //    {0, 1, 1, 0},
    //    {0, 0, 0, 1},
    // idexing row row is as its
    // but col row+col+1;
    // best way to connecting node if row is same or col is same they connect each other
    //
    cout << maximumstonecanremove(adj);
}