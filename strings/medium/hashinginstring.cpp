#include <bits/stdc++.h>
using namespace std;
const long long p = 31;
const long long m = 1e+9;
int hashi(string s)
{
    vector<long long> power(s.size());
    vector<long long> prefix(s.size());
    power[0] = 1;
    prefix[0] = s[0] - 'a' + 1;
    for (int i = 1; i < s.size(); i++)
    {
        power[i] = (power[i - 1] * p) % m;
        prefix[i] = (prefix[i - 1] + (s[i] - 'a' + 1) * power[i]) % m;
    }
    return prefix[s.size() - 1];
}
int main()
{
    string s = "abc";
    cout << hashi(s);
    return 0;
}