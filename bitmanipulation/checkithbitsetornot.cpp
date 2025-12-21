#include <bits/stdc++.h>
using namespace std;
bool check(int n,int i){
    //  return (13>>i)&1;
    return n&(1<<i);
}
int main() {
    cout<<check(13,0);
    return 0;
}