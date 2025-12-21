#include <bits/stdc++.h>
using namespace std;
bool validbf(string s, int idx, int count)
{
    if (count < 0)
        return false;
    if (idx == s.size())
        return count == 0;
    if (s[idx] == '(')
        return validbf(s, idx + 1, count + 1);
    if (s[idx] == ')')
        return validbf(s, idx + 1, count - 1);
    else
    {
        return validbf(s, idx + 1, count + 1) || validbf(s, idx + 1, count - 1) || validbf(s, idx + 1, count);
    }
}
bool range(string s)
{
    int min = 0;
    int max = 0;
    for (int i = 0; i < s.size(); i++)
    {
        if (s[i] == '(')
        {
            min++;
            max++;
        }
        else if (s[i] == ')')
        {
            min--;
            max--;
        }
        else
        {
            min--;
            max++;
        }
        if (min < 0)
            min = 0;
        if (max < 0)
            return false;
    }
    return min == 0 || max == 0;
}

int main()
{
    string s = "(()))";
    cout << range(s);
    return 0;
}