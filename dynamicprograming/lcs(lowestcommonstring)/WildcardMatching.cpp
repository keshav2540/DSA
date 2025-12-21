#include <bits/stdc++.h>
using namespace std;
bool helper(int ind1, int ind2, string s1, string s2)
{
    if (ind1 < 0 && ind2 < 0)  //tc of this expnential
        return true;
    if (ind1 < 0 && ind2 >= 0)
        return false;
    if (ind1 >= 0 && ind2 < 0)
    {
        for (int k = 0; k <= ind1; k++)
            if (s1[ind1] != '*')
                return false;
        return true;
    }
    if (s1[ind1] == s2[ind2] || s1[ind1] == '?')
        return helper(ind1 - 1, ind2 - 1, s1, s2); // not perform any opration
    else if (s1[ind1] == '*')
        return helper(ind1 - 1, ind2, s1, s2) | helper(ind1, ind2 - 1, s1, s2); // it return a loop 0 to ind2 to comapre
    return false;
}
bool helpershift(int ind1, int ind2, string s1, string s2)
{
    if (ind1 == 0 && ind2 == 0)
        return true;
    if (ind1 == 0 && ind2 > 0)
        return false;
    if (ind1 > 0 && ind2 == 0)
    {
        for (int k = 0; k <= ind1; k++)
            if (s1[ind1 - 1] != '*')
                return false;
        return true;
    }
    if (s1[ind1 - 1] == s2[ind2 - 1] || s1[ind1 - 1] == '?')
        return helpershift(ind1 - 1, ind2 - 1, s1, s2); // not perform any opration
    else if (s1[ind1 - 1] == '*')
        return helpershift(ind1 - 1, ind2, s1, s2) | helpershift(ind1, ind2 - 1, s1, s2); // it return a loop 0 to ind2 to comapre
    else
        return false;
}
bool helper2(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{
    if (ind1 == 0 && ind2 == 0)
        return true;
    if (ind1 == 0 && ind2 > 0)
        return false;
    if (ind1 > 0 && ind2 == 0)
    {
        for (int k = 0; k <= ind1; k++)
            if (s1[ind1 - 1] != '*')
                return false;
        return true;
    }
    if (dp[ind1][ind2] != -1)
        return dp[ind1][ind2];
    if (s1[ind1 - 1] == s2[ind2 - 1] || s1[ind1 - 1] == '?')
        return dp[ind1][ind2] = helper2(ind1 - 1, ind2 - 1, s1, s2, dp); // not perform any opration
    else if (s1[ind1 - 1] == '*')
        return dp[ind1][ind2] = helper2(ind1 - 1, ind2, s1, s2, dp) | helper2(ind1, ind2 - 1, s1, s2, dp); // it return a loop 0 to ind2 to comapre
    else
        return dp[ind1][ind2] = false;
}
bool helper3(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{
    
    for (int j = 1; j <= ind2; j++) dp[0][j]=false;
    for (int i = 0; i <= ind1; i++)  {
         bool flag=true;
        for (int k = 1; k <= i; k++)  
            if (s1[k - 1] != '*')
                {
                    flag=false; break;
                }
               dp[i][0]=flag;
            }
    for (int i = 1; i <= ind1; i++)
    {
        for (int j = 1; j <= ind2; j++)
        {
      if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
        dp[i][j] = dp[i - 1][j -1]; // not perform any opration
     else if (s1[i - 1] == '*')
       dp[i][j] = dp[i - 1][j]|dp[i][j - 1]; // it return a loop 0 to ind2 to comapre
     else
        dp[i][j] = false;
           
        }
    }
    return dp[ind1][ind2];
}
bool helperspaceoptimize(int ind1, int ind2, string s1, string s2, vector<vector<int>> &dp)
{
    vector<int> prev(ind2 + 1, 0), curr(ind2 + 1, 0);
    prev[0]=true;
    for (int j = 1; j <= ind2; j++) prev[j]=false;
    for (int i = 1; i <= ind1; i++)
    {       bool flag=true;//every row assign curr[0] every tiem
       for (int k = 1; k <= i; k++)  
          {    if (s1[k - 1] != '*')
                {
                    flag=false; break;
                }
               curr[0]=flag;
            }
        for (int j = 1; j <= ind2; j++)
        {
      if (s1[i - 1] == s2[j - 1] || s1[i - 1] == '?')
        curr[j] = prev[j -1]; // not perform any opration
     else if (s1[i - 1] == '*')
       curr[j] = prev[j]|curr[j - 1]; // it return a loop 0 to ind2 to comapre
     else
        curr[j] = false; 
        }prev=curr;
    }
    return prev[ind2];}
bool wildcardmatching(string s1, string s2)
{
    int n = s1.length();
    int m = s2.length();
    vector<vector<int>> dp(n + 1, vector<int>(m + 1, -1));
    return helperspaceoptimize(n, m, s1, s2,dp);
}

int main()
{
    cout << wildcardmatching("?ay", "ray") << endl;
    cout << wildcardmatching("ab*cd", "abdefcd") << endl;
    cout << wildcardmatching("**abcd", "abcd") << endl;
    cout << wildcardmatching("*******", "") << endl;
    cout << wildcardmatching("abc?d", "abccd") << endl;
    cout << wildcardmatching("abc?d", "ab*lcd") << endl;
    return 0;
}