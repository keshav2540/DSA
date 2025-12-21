#include <bits/stdc++.h>
using namespace std;
int helper(int ind1, int ind2, string s1, string s2)
{
    if (ind1 < 0)
        return ind2 + 1;
    if (ind2 < 0)
        return ind1 + 1;
    if (s1[ind1] == s2[ind2])
        return helper(ind1 - 1, ind2 - 1, s1, s2); // not perform any opration
    else
        return 1 + min(helper(ind1 - 1, ind2, s1, s2), min(helper(ind1, ind2 - 1, s1, s2), helper(ind1 - 1, ind2 - 1, s1, s2)));
    //            min(1+helper(ind1-1,ind2,s1,s2),min(1+helper(ind1,ind2-1,s1,s2),1+helper(ind1-1,ind2-1,s1,s2)));
    //                        delete opration             insert opration               replace
}
int helpershift(int ind1, int ind2, string s1, string s2)
{ // shifting in dp pass original size not after -1
    if (ind1 == 0)
        return ind2 + 1 - 1; // learn perpus
    if (ind2 == 0)
        return ind1 + 1 - 1;
    if (s1[ind1 - 1] == s2[ind2 - 1])
        return helpershift(ind1 - 1, ind2 - 1, s1, s2);
    else
        return 1 + min(helpershift(ind1 - 1, ind2, s1, s2), min(helpershift(ind1, ind2 - 1, s1, s2), helpershift(ind1 - 1, ind2 - 1, s1, s2)));
}
int helper2(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{
    if (ind1 == 0)
        return ind2 + 1 - 1; // learn perpus
    if (ind2 == 0)
        return ind1 + 1 - 1;
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s1[ind1 - 1] == s2[ind2 - 1])
        return dp[ind1][ind2] = helper2(ind1 - 1, ind2 - 1, s1, s2, dp);
    else
        return dp[ind1][ind2] = 1 + min(helper2(ind1 - 1, ind2, s1, s2, dp), min(helper2(ind1, ind2 - 1, s1, s2, dp), helper2(ind1 - 1, ind2 - 1, s1, s2, dp)));
}
int helper3(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{
    for (int i = 0; i <= ind1; i++)
        dp[i][0] = i;
    for (int j = 1; j <= ind2; j++)
        dp[0][j] = j;
    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                dp[i][j] = dp[i - 1][j - 1];
            else
                dp[i][j] = 1 + min(dp[i - 1][j], min(dp[i][j - 1], dp[i - 1][j - 1]));
        }
    }
    return dp[ind1][ind2];
}
int helperspaceoptimize(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{
    vector<int> prev(ind2 + 1, 0), curr(ind2 + 1, 0);
    for (int j = 1; j <= ind2; j++)
        prev[j] = j; 
    for (int i = 1; i <= ind1; i++)
    {      curr[0]=i;
        for (int j = 1; j <= ind2; j++)
        {
            if (s1[i - 1] == s2[j - 1])
                curr[j] = prev[j - 1];
            else
                curr[j] = 1 + min(prev[j], min(curr[j - 1], prev[j - 1]));
        }prev=curr;
    }
    return prev[ind2];
}
int editdistance(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    // return helpershift(n,m,s1,s2);
    // return helper2(n, m, s1, s2, dp);
    // return helper3(n, m, s1, s2, dp);
    return helperspaceoptimize(n,m,s1,s2,dp);
}

int main()
{
    cout << editdistance("horse", "ros") << endl;
    cout << editdistance("kitten", "sitting") << endl;
    cout << editdistance("abc", "tab") << endl;
    cout << editdistance("", "") << endl;
    cout << editdistance("intention", "execution")
         << endl;
    return 0;
}