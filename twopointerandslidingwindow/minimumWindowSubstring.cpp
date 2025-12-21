#include <bits/stdc++.h>
using namespace std;
string sol(string s, string t)
{
    int minlen = INT32_MAX;
    int stidx = -1;
    for (int i = 0; i < s.size(); i++)
    {
        vector<int> hash(256, 0);
        int count = 0;
        for (int i = 0; i < t.size(); i++)
            hash[t[i]]++;
        for (int j = i; j < s.size(); j++)
        {
            if (hash[s[j]] > 0)
            {
                count++;
                hash[s[j]]--;
            }
            if (count == t.size())
            {
                if (j - i + 1 < minlen)
                {
                    minlen = j - i + 1;
                    stidx = i;
                }
                else
                    break;
            }
        }
    }
    return stidx == -1 ? "-1" : s.substr(stidx, minlen);
}
string op(string s, string t)
{
    int stidx = -1;
    vector<int> hash(256, 0);
    int r = 0, l = 0, minlen = INT32_MAX, count = 0;
    for (int i = 0; i < t.size(); i++)
    {
        hash[t[i]]++;
        cout << t[i] << " " << hash[t[i]] << endl;
    }
    while (r < s.size())
    {
        if (hash[s[r]] > 0) {count++;}
        hash[s[r]]--;
        while (count == t.size())
        {
            cout << l << endl;
            if (r - l + 1 <= minlen)
            {
                minlen = r - l + 1;
                stidx = l;
            }
            hash[s[l]]++;
            if (hash[s[l]]>0) {count--; }
             l++;
        }
        r++;
    }
    return stidx == -1 ? "-1" : s.substr(stidx, minlen );
}

int main()
{
    string s = "ddabcbac", t = "abc";
    cout << op(s, t);
    return 0;
}