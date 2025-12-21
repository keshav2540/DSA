#include <bits/stdc++.h>
using namespace std;
vector<int> zfun(string s)
{
    vector<int> ans(s.size());
    ans[0] = 0; // always
    int n = s.size();
    for (int i = 1; i < n; i++)
    {
        int count = 0;
        int j = i;
        while (j < n && s[j] == s[j - i])
        {
            count++;
            j++;
        }
        ans[i] = count;
    }
    return ans;
}
void findindex(string s, string y)
{
    vector<int> temp = zfun((y + "&" + s));
    for (int i = 0; i < temp.size(); i++)
    {
        if (temp[i] == y.size())
            cout << i-y.size() << " ";
    }
}
int main()
{
    findindex("abcabzabc","abc");

        return 0;
}