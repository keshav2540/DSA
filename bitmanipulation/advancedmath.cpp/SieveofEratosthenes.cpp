#include <bits/stdc++.h> //given a  number N,print all prime till n
using namespace std;
vector<int>printprime(int n){
    vector<int>ans(n+1,1);
    ans[0]=0; ans[1]=0;
    vector<int>nums;
    for(int i=2;i*i<n;i++){
        if(ans[i]==1){
            for( int j=i*i;j<=n;j+=i) ans[j]=0;
        }
    } for(int i=0;i<ans.size();i++) if(ans[i]==1)nums.push_back(i);
 return nums;
}

int main() {
    for(int i:printprime(60)) cout<<i<<endl;
    return 0;
}