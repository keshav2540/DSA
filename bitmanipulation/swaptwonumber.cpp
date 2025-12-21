#include <bits/stdc++.h>
using namespace std;
 void swap(int &a,int &b){
    a=a^b;
    b=a^b;
    a=a^b;
 }

int main() {
    int a=1,b=2;
    swap(a,b);
    cout<<a<<" "<<b;
    return 0;
}