#include <bits/stdc++.h>
using namespace std;
int bf(vector<int>arr,vector<int>dep){int maxcount=0;
    for(int i=0;i<arr.size()-1;i++){
         int count=1;
         for(int j=i+1;j<arr.size();j++){
            if(dep[i]>arr[j]){
                count++;
                maxcount=max(maxcount,count);
            }
         }
    } return maxcount;
}
int sortmethold(vector<int>&arr,vector<int>&dep)
{     sort(arr.begin(),arr.end());
    sort(dep.begin(),dep.end());
   int count=0,maxcount=0;
    int st=0,end=0;
    while(st<arr.size()&&end<dep.size()){
        if(arr[st]<=dep[end]){
            st++;
            count++;
        }
        else {count--;
         end++;}
        maxcount=max(maxcount,count);
    } return maxcount;
}
int main() {
vector<int>arr={900,945,955,1100,1500,1800};
vector<int>dep={920,1200,1130,1150,1900,2000};
cout<<sortmethold(arr,dep);
    return 0;
}