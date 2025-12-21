#include <bits/stdc++.h>
using namespace std;
void remove(int &n){
   n=n&n-1;
}

int main() {
     int k=128;
    remove(k);
    cout<<k;
    return 0;
}