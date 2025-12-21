#include <bits/stdc++.h>
using namespace std;
int maxprofit(vector<int>&arr){
    int maxprofit=0;
    int mini=arr[0];
    for(int i=1;i<arr.size();i++){
        int cost=arr[i]-mini;
        mini=min(mini,arr[i]);
        maxprofit=max(maxprofit,cost);
    }
     return maxprofit;
}
int main() {
vector<int>arr={7,1,5,3,6,4};
cout<<maxprofit(arr);
    return 0;
}