// which graph we can color with two diffrent color not have ajacent node same color
#include <bits/stdc++.h>
using namespace std;
bool detectDFS(int node, int col, vector<int> adj[], int color[])
{
    color[node] = col;
    for (auto it : adj[node])
    {
        if (color[it] == -1)
        {
          if(detectDFS(it, !col, adj, color)==false) return false;
        }
        else if (color[it] == col)
        {
            return false;
        }
    }
    return true;
}
bool isbipartitecycle(int v, vector<int> adj[])
{
    int color[v];
    for(int i=0;i<v;i++) color[i]=-1;
    for (int i = 1; i < v; i++)
    {
        if (color[i] == -1)
        {
            if (detectDFS(i, 0, adj, color) == false)
                return false;
        }
    }
    return true;
}
int main()
{
    vector<int> adj[9];
    adj[1] = {2};
    adj[2] = {1, 3, 6};
    adj[3] = {2, 4};
    adj[4] = {3, 5, 7};
    adj[5] = {6, 4};
    adj[6] = {5, 2};
    adj[7] = {4, 8};
    adj[8] = {7};
// vector<int> adj[8];
// adj[1] = {2};
// adj[2] = {1, 3};
// adj[3] = {2};
// adj[4] = {5, 7};
// adj[5] = {4, 6};
// adj[6] = {5, 7};
// adj[7] = {6, 4};
    cout << isbipartitecycle(8, adj);
    return 0;
}