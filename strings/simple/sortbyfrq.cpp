#include <bits/stdc++.h>
using namespace std;
string sortfrq(string s)
{
    vector<pair<int, char>> frq(120, {0, 0});
    for (int i = 0; i < s.size(); i++)
    {
        frq[s[i]].first++;
        frq[s[i]].second = s[i];
    }
    sort(frq.rbegin(), frq.rend());
    string ans = "";
    int i=0;  
  while(frq[i].first!=0&& i<121){
    ans+=frq[i].second;
    if(!--frq[i].first)i++;
  }
    return ans;
}

int main()
{
    string s = "aacAbBA";
    cout << sortfrq(s);

    return 0;
}