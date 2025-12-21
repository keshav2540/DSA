#include <bits/stdc++.h>
using namespace std;
int count(int n){
    int count=0;
    while(n!=0){
        count+=n&1;
       n= n>>1;
    }
    return count;
}
int optimal(int n){int count=0;
    while(n!=0){
        count++;
        n=n&n-1;
    } return count;
}

int main() {
    cout<<optimal(13);
    return 0;
}