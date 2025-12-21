#include <bits/stdc++.h>
using namespace std;
vector<int>singlenums(vector<int>nums){
int x0r=0;
for(int i:nums) x0r=x0r^i;
int ans=(x0r&x0r-1)^x0r; // right most bit
int first=0,second=0;
for(int i:nums){
    if(i&ans) first=first^i;
    else second^=i;
} return {first,second};
}

int main() {
    vector<int>nums={2,4,2,14,3,7,7,3};
    cout<<singlenums(nums)[0]<<" "<<singlenums(nums)[1];
    return 0;
}