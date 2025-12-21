#include <bits/stdc++.h>
using namespace std;
int funstriver(int mid,int nums,int j){
    long int ans=1;
    for(int i=0;i<j;i++){
        ans=ans*mid;
        if(ans>nums) return 2;
    }

    if(ans==nums) return 1;
    return 0;
}
int findnthstriver(int nums, int j)
{
    int end = nums;
    int st = 0;
    int ans;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        int midn=funstriver(mid,nums,j);
        if (midn==1) return mid;
        else if(midn==0) st=mid+1;
        else
        {
            end = mid - 1;
        }
    }
    return -1;
}
long long int f(int i, int j)
{
    int ans = 1;
    while (j != 0)
    {
        if (j % 2 == 1)
        {
            ans = ans * i;
        }
        i = i * i;
        j = j / 2;
    }
    return ans;}

int findnth(int nums, int j)
{
    int end = nums;
    int st = 0;
    int ans;
    while (st <= end)
    {
        int mid = st + (end - st) / 2;
        if (f(mid, j) <= nums)
        {
            st = mid + 1;
            ans = mid;
        }
        else
        {
            end = mid - 1;
        }
    }
    if(nums==f(ans,j)) return ans;
           else return -1;
}

int ls(int nums, int j)
{
    int ans;
    for (int i = 0; i <= nums; i++)
    {
        if (f(i, j) <= nums)
        {
            ans = i;
        }
        else
           if(nums==f(ans,j)) return ans;
           else return -1;
    }
    return -1;
}

int main()
{
    int nums = 81;
    cout << findnthstriver(81,3);
    cout << endl << ls(nums, 2);
    // cout<<f(3,0);
    return 0;
}