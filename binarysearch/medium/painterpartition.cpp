#include <bits/stdc++.h>
using namespace std;
bool ispossible(vector<int> nums, int mid, int painter){
    int sum=0, countpainter=0;
    for(int i=0;i<nums.size();i++){
        if(sum+nums[i]<=mid)
        {sum+=nums[i];}
        else{
            sum=nums[i];
            countpainter++;
        }
    }
    if(countpainter>=painter) return true;
    return false;
}
int paintermintime(vector<int> nums, int painter)
{int low=*max_element(nums.begin(),nums.end());
    int high=accumulate(nums.begin(),nums.end(),0);
    while (low <= high)
{     
       int mid = (low + high) / 2;
    if (ispossible(nums, mid ,painter))
    {
        low=mid+1;
    }
    else{
        high=mid-1;
    }
}

    return low;
}

int main()
{
    vector<int> nums = {10,20,30,40,50,50};
int painter=2;
    cout << paintermintime(nums, painter);
    return 0;
}