#include <bits/stdc++.h>
using namespace std;
string longestpalindrome(string s)
{
    string res = "";
        int reslen = 0;
    for (int i = 0; i < s.size(); i++)
    {
        int l = i, r = i;//odd len
        while (l >= 0 && r <= s.size() && s[l] == s[r])
        {
            if ((r - l + 1) > reslen)
            {
                res = s.substr(l, r + 1);
                reslen = r - l + 1;
            }
            l -= 1;
            r += 1;
        }
        l = i, r = i + 1;//even len
        while (l >= 0 && r <= s.size() && s[l] == s[r])
        {
            if ((r - l + 1) > reslen)
            {
                res = s.substr(l, r + 1);
                reslen = r - l + 1;
            }
            l -= 1;
            r += 1;
        }
    } return res;
}

int main()
{
    string s = "babad";
    cout << longestpalindrome(s);

    return 0;
}