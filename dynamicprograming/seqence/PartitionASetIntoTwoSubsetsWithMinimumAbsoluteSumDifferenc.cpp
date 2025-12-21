#include <bits/stdc++.h>
using namespace std;
// this is sub problem of subsetsum
bool partionsumdiff(vector<int>&arr){
int n=arr.size();
int totalsum=0;
for(int i=0;i<n;i++){totalsum+=arr[i];}
int t=totalsum;
 vector<bool>prev(1+t,false),curr(1+t,false);
        prev[0]=curr[0]=true;
    prev[arr[0]]=true;
    for(int i=1;i<=n;i++){
        for(int target=1;target<=t;target++){
            curr[target]=((prev[target])|(target>=arr[i]?prev[target-arr[i]]:false));
        }prev=curr;
    }
    int mini=INT32_MAX;
    for(int i=0;i<=totalsum/2;i++){
     if(prev[i]==true){
        mini=min(mini,abs(totalsum-(2*i)));
     }
    } return mini;
}
int main() {
vector<int>arr={1,2,3,4};
cout<<partionsumdiff(arr);
    return 0;
}