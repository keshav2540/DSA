#include <bits/stdc++.h>
using namespace std;
bool check(int n){
    if(n&n-1==0) return 1;
    return 0;
}

int main() {
    cout<<check(4);
    return 0;
}