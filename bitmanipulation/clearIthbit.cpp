#include <bits/stdc++.h>
using namespace std;
void clearithbit(int &n,int i){
  n=n&(~(1<<i));
}
int main() {
    int k=13;
    clearithbit(k,3);
    cout<<k;
       return 0;
}