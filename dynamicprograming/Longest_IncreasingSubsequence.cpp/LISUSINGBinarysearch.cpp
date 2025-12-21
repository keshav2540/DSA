// this is a algorithm
#include <bits/stdc++.h>
using namespace std;
int lis(vector<int> &arr)
{
    vector<int> temp;
    for (int i = 0; i < arr.size(); i++)
    {
        if (i==0||arr[i] > temp.back())
        {
            temp.push_back(arr[i]);
        }
        else
        {
            int index =  lower_bound(temp.begin(), temp.end(),arr[i])-temp.begin();// it return itrator whose return idex poistion -arr.begin convert this to  index
            temp[index]=arr[i];
        }
    } 
    for(int i:temp) cout<<i<<" ";
    cout<<endl;
    return temp.size();
}
int main()
{
    vector<int> arr = {1, 7, 8, 4, 5, 6, -1, 9};
    vector<int>arr3={5,4,11,1,16,0};
    vector<int>arr1={1,2,2};
    vector<int>arr2={10,9,2,5,3,7,101,18};
    cout<<(lis(arr))<<endl;
    cout<<(lis(arr3))<<endl;
    cout<<(lis(arr1))<<endl;
    cout<<(lis(arr2))<<endl;
    return 0;
}