#include <bits/stdc++.h>
using namespace std;
long double better(vector<int> nums, int k)
{  int n = nums.size() - 1; 
       vector<long double> howmany(n, 0);
     priority_queue<pair<long double,int>>pq;
    for (int i = 0; i < n; i++) pq.push({(nums[i+1]-nums[i]),i});
    for(int gasstation=1;gasstation<=k;gasstation++){
        auto it=pq.top();
        pq.pop();
        int sectionidx=it.second;
        howmany[sectionidx]++;
        long double diff=nums[sectionidx+1]-nums[sectionidx];
        long double newsectionlen=diff/((long double)howmany[sectionidx]+1);
        pq.push({newsectionlen,sectionidx});
    }
        return pq.top().first;
  
    }

long double bf(vector<int> nums, int k)
{
    int n = nums.size() - 1;
    vector<long double> howmany(n, 0);
    for (int i = 0; i < k; i++)
    {
         long double maxval = -1;
        int maxindex = 0;
        for (int i = 0; i < n; i++)
        {
            long double diff = nums[i + 1] - nums[i];
            long double sectionlength = diff / howmany[i] + 1;
            if (maxval < sectionlength)
            {
                maxval = sectionlength;
                maxindex = i;
            }
        }
        howmany[maxindex]++;
    }
    long double length = 0;
    for (int i = 0; i < n; i++)
    {
        length = max(length, ((long double)(nums[i + 1] - nums[i]) / (howmany[i] + 1)));
    }
    return length;
}

int placestation(vector<int> nums, double mid)
{
    int count = 0;
    for (int i = 1; i < nums.size(); i++)
    {
        int numberinbetween = (nums[i] - nums[i - 1]) / (mid);
        if (((nums[i] - nums[i - 1]) / mid) == numberinbetween * mid)
        {
            numberinbetween--;
        }
        count += numberinbetween;
    }
    return count;
}

long double bs(vector<int> nums, int k)
{
    long double low = 0;
    long double high = 0;
    for (int i = 1; i < nums.size(); i++)
        high = max(high, (long double)(nums[i] - nums[i - 1]));
    long double diff = 1e-6;
    while ((high - low) > diff)
    {
        long double mid = (low + high) / 2.0;
        int check = placestation(nums, mid);
        if (check > k)
        {
            low = mid;
        }
        else
        {
            high = mid;
        }
    }
    return high;
}

int main()
{
    vector<int> nums = {1, 13, 17, 23};
    int k = 5;
    // cout << bf(nums, k) << endl;
     cout<<better(nums,k)<<endl;
    // cout << bs(nums, k) << endl;
    return 0;
}