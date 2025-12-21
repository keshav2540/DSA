#include <bits/stdc++.h>
using namespace std;

int findsq(int nums ){
    int end =nums;
    int st=0;
    int ans;
    while(st<=end){
         int mid=st+(end-st)/2;
        if(mid*mid<=nums) {
           st=mid+1;
            ans=mid;}
        else{  end=mid-1;}
} return ans;}
 int ls(int nums){
    int ans;
    for(int i=0;i<=nums;i++){
        if(i*i<=nums){
            ans=i;
        } else return ans;
    }
    return -1;
 }

int main() {
    int nums=1;
    cout<<findsq(nums);
    cout<<endl<<ls(nums);
    return 0;
}