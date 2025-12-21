#include <bits/stdc++.h>
using namespace std;
int coutxor(int n){
    if(n%4==0) return n;
    if(n%4==1) return 1;
    if(n%4==2) return n+1;
    if(n%4==3) return 0;
}
 int xorrange(int n,int j){
    return coutxor(n-1)^coutxor(j);
 }
int main() {
    cout<<endl<<coutxor(1);
    cout<<endl<<coutxor(2);
    cout<<endl<<coutxor(3);
    cout<<endl<<coutxor(4);
    cout<<endl<<coutxor(5);
    cout<<endl<<coutxor(6);
    cout<<endl<<xorrange(4,6);
    cout<<endl<<(4^5^6);
    return 0;
}