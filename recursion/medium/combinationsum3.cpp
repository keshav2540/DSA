#include <bits/stdc++.h>
using namespace std;
void com(int n, int s, vector<int> &temp, int &tempsum, vector<vector<int>> &ans, int ind)
{
    if (temp.size() == n)
    {
        if (tempsum == s)
        {
            ans.push_back(temp);
            return;
        }
        return;
    }
    for (int i = ind; i <= 9; i++)
    {
        if (tempsum + i > s || ind > 9)
            return;
        temp.push_back(i);
        tempsum += i;
        com(n, s, temp, tempsum, ans, i + 1);
        temp.pop_back();
        tempsum -= i;
    }
}

int main()
{
    vector<int> temp;
    int tempsum = 0;
    vector<vector<int>> ans;
    int ind = 1;
    com(5, 23, temp, tempsum, ans, ind);
    for (int i = 0; i < ans.size(); i++)
    {
        for (int j = 0; j < ans[i].size(); j++)
        {
            cout << ans[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}