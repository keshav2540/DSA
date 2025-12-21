#include <bits/stdc++.h>
using namespace std;
void toggle(int &n,int i){
   n=(1<<i)^n;     
}

int main() {
    int k=13;
    toggle(k,1);
    cout<<k;
    return 0;
}