#include <bits/stdc++.h>
using namespace std;
int bf()
{ // O(n^2)andO(n^3)
}
int prefixmethod(vector<int> nums, int k)
{
    int n = nums.size();
    unordered_map<int,int>m;
    int sum = 0;
    int count=0;
    m[0]=1;
    int remove;
    for (int i = 0; i < n; i++)
    {
        sum += nums[i];
         remove=sum-k;
         count+=m[remove];
         m[sum]++;}

 return count;
    
}

int main()
{
    vector<int> nums = {1, 2, 3, -3, 1, 1, 1, 4, 2, -3};
    cout << prefixmethod(nums, 3);
    return 0;
}