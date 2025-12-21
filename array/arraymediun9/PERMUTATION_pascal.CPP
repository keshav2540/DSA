#include <bits/stdc++.h>
using namespace std;

int nCr(int n,int r){
     if(r==0||r==n) return 1;
    int mul=1,ans=1;
    if(n-r<r) r=n-r;
    for(int i=0;i<r;i++){
        mul=mul*(n-i);
        mul=mul/(i+1);
    }
 return mul;
}    
void printNrow(int n){
    // for(int i=0;i<=n;i++){
    //     cout<<nCr(n,i)<<" ";
    // }
int mul=1;
cout<<mul<<" ";
    for(int i=1;i<n;i++){ 
        mul=mul*(n-i);
        mul=mul/(i);
        cout<<mul<<" ";
    }
}
void print(int n){
    int i;
    for(int j=1;j<=n;j++){
    for(i=1;i<n-j+1;i++){
        cout<<" ";
    }
    printNrow(j);
    cout<<endl;
}}

int main() {
     print(9);
    return 0;
}