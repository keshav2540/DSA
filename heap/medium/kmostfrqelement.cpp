#include <bits/stdc++.h>
using namespace std;
vector<int> kmostfrqelement(vector<int> nums, int k)
{
    vector<int> ans;
    unordered_map<int, int> m;
    for (int i : nums)
        m[i]++;
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
    for (auto &i : m)
        pq.push({i.second, i.first});
    while (!pq.empty()&&pq.size() != k)
    {
        pq.pop();
    }
    while (!pq.empty())
    {
        ans.push_back(pq.top().second);
        pq.pop();
    }
    return ans;
}

int main()
{
    vector<int> nums = {1, 1, 1,2,2,3,3,3};
    int k = 2;
    for (int i : kmostfrqelement(nums, k)) cout<<i<<endl;
        return 0;
}