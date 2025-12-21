#include <bits/stdc++.h>
using namespace std;
int waitingtime(vector<int> &jobs)
{
    sort(jobs.begin(), jobs.end());
    int t = 0, wt = 0;
    for (int i = 0; i < jobs.size(); i++)
    {   wt += t;
        t += jobs[i];
    }
    return wt;
}

int main()
{
    vector<int> jobs = {4, 3, 7, 1, 2};
    cout << waitingtime(jobs);
    return 0;
}