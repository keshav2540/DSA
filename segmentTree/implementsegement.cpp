#include<bits/stdc++.h>
using namespace std;
class segmentTree
{
    int n;
    int *tree;
   
    void build(const vector<int> &nums)
    {

        for (int i = 0; i < n; i++)
        {
            tree[n + i] = nums[i];
        }
        for (int i = n - 1; i > 0; i--)
        {
            tree[i] = tree[2 * i] + tree[2 * i + 1];
        }
    }

public:
 segmentTree(const vector<int> nums)
    {
        n = nums.size();
        tree = new int[2 * n];
        build(nums);
    }
    int Query(int l, int r)
    {
        l += n;
        r += n;
        int result = 0;
          while(l <= r){
            if (l % 2 == 1)
            {
                result += tree[l];
                l++;
            }
            if (r % 2 == 0)
            {
                result += tree[r];
                r--;
            }
            l /= 2;
            r /= 2;
        } return result;
    }
    void update(int index,int val){
        index+=n;
        tree[index]=val;
        while(index>1){
            index/=2;
            tree[index]=tree[2*index]+tree[(index*2)+1];
        }
    }
}; 
int main()
{
    vector<int>nums={1,3,5,7,9,11};
    segmentTree t(nums);
    cout<<t.Query(0,5);
    t.update(4,0);
    cout<<t.Query(2,5);
    return 0;
}