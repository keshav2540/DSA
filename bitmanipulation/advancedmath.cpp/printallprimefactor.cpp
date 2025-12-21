#include <bits/stdc++.h>
using namespace std;
bool checkprime(int n){int count=0;
    for(int i=1;i*i<=n;i++) if(n%i==0) count=count+2;
    if(count==2) return true;
    else return false;
}
vector<int>primefactor(int n){
    vector<int>ans;
    for(int i=2;i*i<=n;i++){
        if(n%i==0){
            if(checkprime(i)) ans.push_back(i);
            if(n/i!=n & checkprime(n/i))ans.push_back(n/i);
        }
    } return ans;
}
vector<int>optimalprimefactor(int n){  vector<int>ans;
    // for(int i=2;i<n;i++){
    //   if(n%i==0){
    //     ans.push_back(i);
    //     while(n%i==0)n=n/i;
    //   }
    // } return ans;
    for(int i=2;i*i<n;i++){
      if(n%i==0){
        ans.push_back(i);
        while(n%i==0)n=n/i;
      }
    } 
    if(n!=1) ans.push_back(n);
    return ans;
}
int main() {
    for(int i:optimalprimefactor(780)) cout<<i<<endl;
    return 0;
}