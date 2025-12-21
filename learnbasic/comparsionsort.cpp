#include <bits/stdc++.h>
using namespace std;
bool compare(int a,int b ){
    return a<b;
}
int main() {
    vector<int>nums={9,8,7,6,5,4,3};
    sort(nums.begin(),nums.end(),compare);
    for(int i :nums) cout<<i;
    return 0;
}