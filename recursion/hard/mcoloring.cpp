#include <bits/stdc++.h>
using namespace std;
bool issafe(int node, int color[], vector<int> arr[], int n, int col)
{
    for (int neigh : arr[node]) {
        if (color[neigh] == col) 
            return false;
    }
    return true;}

    // for (int k = 0; k < n; k++)
    // {
    //     if (k != node && arr[k][node] == 1 && color[k] == col)
    //     {
    //         return false;
    //     }
    // }
    // return true;
// }
bool solve(int node, int color[], int m, int n, vector<int> arr[])
{
    if (node == n)
    {
        return true;
    }
    for (int i = 1; i <= m; i++)
    {
        if (issafe(node, color, arr, n, i))
        {
            color[node] = i;
            if (solve(node + 1, color, m, n, arr))
                return true;
            color[node] = 0;
        }
    }
    return false;
}
bool graphcoloring(vector<int> arr[], int m, int n)
{
    int color[n] = {0};
    if (solve(0, color, m, n, arr) == true)
        return true;
    return false;
}

int main()
{
    vector<int> arr[4] = {{1,2,3}, {0, 2, 3}, {0, 1}, {0, 1}};
    int m=2,n=4;
     if (graphcoloring(arr, m, n))
        cout << "Coloring possible\n";
    else
        cout << "Coloring NOT possible\n";
    return 0;
}